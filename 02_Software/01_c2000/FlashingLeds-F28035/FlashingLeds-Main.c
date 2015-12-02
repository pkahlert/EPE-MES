//----------------------------------------------------------------------------------
//	FILE:			FlashingLeds-Main.C
//
//	Description:	Empty Framework ready for customization
//
//	Version: 		2.0
//
//  Target:  		TMS320F2803x
//
//	Type: 			Device Independent
//
//----------------------------------------------------------------------------------
//  Copyright Texas Instruments © 2004-2010
//----------------------------------------------------------------------------------
//  Revision History:
//----------------------------------------------------------------------------------
//  Date	  | Description / Status
//----------------------------------------------------------------------------------
// 13 July 2010 - BRL
//----------------------------------------------------------------------------------
//
// PLEASE READ - Useful notes about this Project

// Although this project is made up of several files, the most important ones are:
//	 "FlashingLeds-Main.C"	- this file
//		- Application Initialization, Peripheral config,
//		- Application management
//		- Slower background code loops and Task scheduling
//	 "FlashingLeds-DevInit_F28xxx.C
//		- Device Initialization, e.g. Clock, PLL, WD, GPIO mapping
//		- Peripheral clock enables
//		- DevInit file will differ per each F28xxx device series, e.g. F280x, F2833x,
//	 "FlashingLeds-ISR.asm
//		- Assembly level library Macros and any cycle critical functions are found here
//	 "FlashingLeds-Settings.h"
//		- Global defines (settings) project selections are found here
//		- This file is referenced by both C and ASM files.

// Code is made up of sections, e.g. "FUNCTION PROTOTYPES", "VARIABLE DECLARATIONS" ,..etc
//	each section has FRAMEWORK and USER areas.
//  FRAMEWORK areas provide useful ready made "infrastructure" code which for the most part
//	does not need modification, e.g. Task scheduling, ISR call, GUI interface support,...etc
//  USER areas have functional example code which can be modified by USER to fit their appl.
//

//----------------------------------------------------------------------------------
//This program blinks LED3 on the controlCARD at a frequency given by the variable 
// Gui_LedPrd_ms. If an external GUI is connected LD2 will blink as well.
// 
//----------------------------------------------------------------------------------

#include "FlashingLeds-Settings.h"
#include "PeripheralHeaderIncludes.h"
																		 

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// FUNCTION PROTOTYPES
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// -------------------------------- FRAMEWORK --------------------------------------
void DeviceInit(void);
void SCIA_Init();
void SerialHostComms();
void InitFlash();
void MemCopy();


// State Machine function prototypes
//------------------------------------
// Alpha states
void A0(void);	//state A0
void B0(void);	//state B0
void C0(void);	//state C0

// A branch states
void A1(void);	//state A1
void A2(void);	//state A2

// B branch states
void B1(void);	//state B1
void B2(void);	//state B2

// C branch states
void C1(void);	//state C1
void C2(void);	//state C2

// Variable declarations
void (*Alpha_State_Ptr)(void);	// Base States pointer
void (*A_Task_Ptr)(void);		// State pointer A branch
void (*B_Task_Ptr)(void);		// State pointer B branch
void (*C_Task_Ptr)(void);		// State pointer C branch


// ---------------------------------- USER -----------------------------------------




//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// VARIABLE DECLARATIONS - GENERAL
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// -------------------------------- FRAMEWORK --------------------------------------

int16	SerialCommsTimer;
int16	CommsOKflg;


// Used for running BackGround in flash, and ISR in RAM
extern Uint16 *RamfuncsLoadStart, *RamfuncsLoadEnd, *RamfuncsRunStart;


// ---------------------------------- USER -----------------------------------------
int16	Gui_LedPrd_ms;			// LED Prd in ms
int16	LedBlinkTimer;			
	

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// VARIABLE DECLARATIONS - CCS WatchWindow / GUI support
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// -------------------------------- FRAMEWORK --------------------------------------

//GUI support variables
// sets a limit on the amount of external GUI controls - increase as necessary
int16 	*varSetTxtList[8];				//8 textbox controlled variables
int16 	*varSetBtnList[8];				//8 button controlled variables
int16 	*varSetSldrList[8];				//8 slider controlled variables
int16 	*varGetList[8];					//8 variables sendable to GUI
int16 	*arrayGetList[8];				//8 arrays sendable to GUI				



//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// MAIN CODE - starts here
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
void main(void)
{
//=================================================================================
//	INITIALIZATION - General
//=================================================================================

//-------------------------------- FRAMEWORK --------------------------------------

	DeviceInit();	// Device Life support & GPIO
	SCIA_Init();  	// Initalize the Serial Comms A peripheral

// Only used if running from FLASH
// Note that the variable FLASH is defined by the compiler with -d FLASH
// (see the project's Build Properties)
#ifdef FLASH		
// Copy time critical code and Flash setup code to RAM
// The  RamfuncsLoadStart, RamfuncsLoadEnd, and RamfuncsRunStart
// symbols are created by the linker. Refer to the linker files. 
	MemCopy(&RamfuncsLoadStart, &RamfuncsLoadEnd, &RamfuncsRunStart);

// Call Flash Initialization to setup flash waitstates
// This function must reside in RAM
	InitFlash();	// Call the flash wrapper init function
#endif //(FLASH)

// Initialize period for each CPU Timer (used by background loops)
// Timer period definitions found in PeripheralHeaderIncludes.h
	CpuTimer0Regs.PRD.all =  mSec1;		// A tasks
	CpuTimer1Regs.PRD.all =  mSec50;	// B tasks
	CpuTimer2Regs.PRD.all =  mSec500;	// C tasks

// Tasks State-machine init
	Alpha_State_Ptr = &A0;
	A_Task_Ptr = &A1;
	B_Task_Ptr = &B1;
	C_Task_Ptr = &C1;

	CommsOKflg = 0;
	SerialCommsTimer = 0;

// ---------------------------------- USER -----------------------------------------
//  put common initialization/variable definitions here



//=================================================================================
//	INITIALIZATION - GUI connections
//=================================================================================
// Use this section only if you plan to "Instrument" your application using the 
// Microsoft C# freeware GUI Template provided by TI

	//"Set" variables
	//---------------------------------------
	// assign GUI variable Textboxes to desired "setable" parameter addresses
	//varSetTxtList[0] = &Var1;

	// assign GUI Buttons to desired flag addresses
	//varSetBtnList[0] = &Var2;

	// assign GUI Sliders to desired "setable" parameter addresses
	varSetSldrList[0] = &Gui_LedPrd_ms;


	//"Get" variables
	//---------------------------------------
	// assign a GUI "getable" parameter address
	//varGetList[0] = &Var3;

	// assign a GUI "getable" parameter array address
	// 		only need to set initial position of array, program will run through it 
	//       based on the array length specified in the GUI
	//arrayGetList[0] = &Var4[0];



//==================================================================================
//	INITIALIZATION - Peripherals used
//==================================================================================

// ---------------------------------- USER -----------------------------------------
//  Put peripheral initialization here


// Initialization Time
// = = = = = = = = = = = = = = = = = = = = = = = =
EPwm1Regs.TBPRD = 600; // Period = 601 TBCLK counts
EPwm1Regs.CMPA.half.CMPA = 350; // Compare A = 350 TBCLK counts
EPwm1Regs.CMPB = 200; // Compare B = 200 TBCLK counts
EPwm1Regs.TBPHS.all = 0; // Set Phase register to zero, // .all hinzugefügt
EPwm1Regs.TBCTR = 0; // clear TB counter
EPwm1Regs.TBCTL.bit.CTRMODE = 0; // #lt
EPwm1Regs.TBCTL.bit.PHSEN = 0; // Phase loading disabled, // #lt
EPwm1Regs.TBCTL.bit.PRDLD = 1; // #lt
EPwm1Regs.TBCTL.bit.SYNCOSEL = 2; // #lt
EPwm1Regs.TBCTL.bit.HSPCLKDIV = 0; // TBCLK = SYSCLK, // #lt
EPwm1Regs.TBCTL.bit.CLKDIV = 0; // #lt
EPwm1Regs.CMPCTL.bit.SHDWAMODE = 1; // #lt
EPwm1Regs.CMPCTL.bit.SHDWBMODE = 0; // #lt
EPwm1Regs.CMPCTL.bit.LOADAMODE = 0; // load on CTR = Zero, // #lt
EPwm1Regs.CMPCTL.bit.LOADBMODE = 0; // load on CTR = Zero, // #lt
EPwm1Regs.AQCTLA.bit.ZRO = 1; // #lt
EPwm1Regs.AQCTLA.bit.CAU = 2; // #lt
EPwm1Regs.AQCTLB.bit.ZRO = 0; // #lt
EPwm1Regs.AQCTLB.bit.CBU = 0; // #lt
//
// Run Time
// = = = = = = = = = = = = = = = = = = = = = = = =
EPwm1Regs.CMPA.half.CMPA = 350; // adjust duty for output EPWM1A
EPwm1Regs.CMPB = 200; // adjust duty for output EPWM1B


//==================================================================================
//	INITIALIZATION - BUILD OPTIONS - Change in FlashingLeds-Settings.h
//==================================================================================

// ---------------------------------- USER -----------------------------------------

//------------------------------------------------------
#if (INCR_BUILD == 1)
//------------------------------------------------------
	
	LedBlinkTimer = 0;			//Initialize LedBlinkTimer to 0
	Gui_LedPrd_ms = 1000;		//Default to 1 blink every second

#endif // (INCR_BUILD == 1)


//------------------------------------------------------
#if (INCR_BUILD == 2)
//------------------------------------------------------

	LedBlinkTimer = 0;			//Initialize LedBlinkTimer to 0
	Gui_LedPrd_ms = 2000;  		//Default to 2 blinks each second
	
#endif // (INCR_BUILD == 2) 



//==================================================================================
//	INITIALIZATION - ISR - best to do this just before the infinite loop
//==================================================================================
// Initialize CLA if needed
//	CLA_Init();

// ---------------------------------- USER -----------------------------------------




//=================================================================================
//	BACKGROUND (BG) LOOP
//=================================================================================

//--------------------------------- FRAMEWORK -------------------------------------
	for(;;)  //infinite loop
	{
		// State machine entry & exit point
		//===========================================================
		(*Alpha_State_Ptr)();	// jump to an Alpha state (A0,B0,...)
		//===========================================================

	}
} //END MAIN CODE



//=================================================================================
//	STATE-MACHINE SEQUENCING AND SYNCRONIZATION
//=================================================================================

//--------------------------------- FRAMEWORK -------------------------------------
void A0(void)
{
	// loop rate synchronizer for A-tasks
	if(CpuTimer0Regs.TCR.bit.TIF == 1)
	{
		CpuTimer0Regs.TCR.bit.TIF = 1;	// clear flag

		//-----------------------------------------------------------
		(*A_Task_Ptr)();		// jump to an A Task (A1,A2,A3,...)
		//-----------------------------------------------------------

		SerialCommsTimer++;
	}

	Alpha_State_Ptr = &B0;		// Comment out to allow only A tasks
}

void B0(void)
{
	// loop rate synchronizer for B-tasks
	if(CpuTimer1Regs.TCR.bit.TIF == 1)
	{
		CpuTimer1Regs.TCR.bit.TIF = 1;				// clear flag

		//-----------------------------------------------------------
		(*B_Task_Ptr)();		// jump to a B Task (B1,B2,B3,...)
		//-----------------------------------------------------------
	}

	Alpha_State_Ptr = &C0;		// Allow C state tasks
}

void C0(void)
{
	// loop rate synchronizer for C-tasks
	if(CpuTimer2Regs.TCR.bit.TIF == 1)
	{
		CpuTimer2Regs.TCR.bit.TIF = 1;				// clear flag

		//-----------------------------------------------------------
		(*C_Task_Ptr)();		// jump to a C Task (C1,C2,C3,...)
		//-----------------------------------------------------------
	}

	Alpha_State_Ptr = &A0;	// Back to State A0
}


//----------------------------------- USER ----------------------------------------

//=================================================================================
//	A - TASKS
//=================================================================================
// Each active task runs every (CpuTimer0 period) * (# of active A Tasks)
//--------------------------------------------------------
void A1(void) // SCI-GUI
//--------------------------------------------------------
{
	SerialHostComms();		// Serialport controls LED2 (GPIO-31)
							// Will not blink until GUI is connected
	
	if(LedBlinkTimer == 0)
	{
		GpioDataRegs.GPBTOGGLE.bit.GPIO34 = 1;		// toggle GPIO34 which controls LD3 on most controlCARDs
		#if DSP2834x_DEVICE_H
		GpioDataRegs.GPBTOGGLE.bit.GPIO54 = 1;		// toggle GPIO54 which controls LD3 on the C2834x DIMM100 controlCARD
		#endif
		
		LedBlinkTimer = Gui_LedPrd_ms >> 1;			// divide by 2 (one LED blink period is 2 LED toggles)
	}
	else
	{
		LedBlinkTimer--;
	}
	

	//-------------------
	//the next time CpuTimer0 'counter' reaches Period value go to A1
	A_Task_Ptr = &A1;
	//-------------------
}

//--------------------------------
void A2(void) //  SPARE
//--------------------------------
{	

	//-------------------
	//task never runs; Task A1 always never set A_Task_Ptr to come to A2
	A_Task_Ptr = &A1;
	//-------------------
}


//=================================================================================
//	B - TASKS
//=================================================================================
// Each active task runs every (CpuTimer1 period) * (# of active B Tasks)
//--------------------------------
void B1(void) //  SPARE
//--------------------------------
{

	//-----------------
	//the next time CpuTimer1 'counter' reaches Period value go to B2
	B_Task_Ptr = &B2;	
	//-----------------
}

//--------------------------------
void B2(void) //  SPARE
//--------------------------------
{

	//-----------------
	//the next time CpuTimer1 'counter' reaches Period value go to B1
	B_Task_Ptr = &B1;
	//-----------------
}


//=================================================================================
//	C - TASKS
//=================================================================================
	// Each active task runs every (CpuTimer2 period) * (# of active C Tasks)
//--------------------------------
void C1(void) 	// SPARE
//--------------------------------
{

	//-----------------
	//the next time CpuTimer2 'counter' reaches Period value go to C2
	C_Task_Ptr = &C2;	
	//-----------------

}

//--------------------------------
void C2(void) //  SPARE
//--------------------------------
{

	//-----------------
	//the next time CpuTimer2 'counter' reaches Period value go to C1
	C_Task_Ptr = &C1;	
	//-----------------
}

