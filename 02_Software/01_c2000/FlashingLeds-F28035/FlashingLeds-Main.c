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

// #lt imports standard assets
#include "DSP2803x_headers/include/DSP2803x_Device.h"

// EPWM_INFO wrapper, used for every single configured epwm
typedef struct
{
   volatile struct EPWM_REGS *EPwmRegHandle;
   Uint16 EPwm_CMPA_Direction;
   Uint16 EPwm_CMPB_Direction;
   Uint16 EPwmTimerIntCount;
   Uint16 EPwmMaxCMPA;
   Uint16 EPwmMinCMPA;
   Uint16 EPwmMaxCMPB;
   Uint16 EPwmMinCMPB;
}EPWM_INFO;

// Configure the period for each timer
#define EPWM1_TIMER_TBPRD  2000  // Period register
#define EPWM1_MAX_CMPA     1950
#define EPWM1_MIN_CMPA       50
#define EPWM1_MAX_CMPB     1950
#define EPWM1_MIN_CMPB       50

#define EPWM2_TIMER_TBPRD  2000  // Period register
#define EPWM2_MAX_CMPA     1950
#define EPWM2_MIN_CMPA       50
#define EPWM2_MAX_CMPB     1950
#define EPWM2_MIN_CMPB       50

#define EPWM3_TIMER_TBPRD  2000  // Period register
#define EPWM3_MAX_CMPA      950
#define EPWM3_MIN_CMPA       50
#define EPWM3_MAX_CMPB     1950
#define EPWM3_MIN_CMPB     1050

// To keep track of which way the compare value is moving
#define EPWM_CMP_UP   1
#define EPWM_CMP_DOWN 0

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

// A branch states
void A1(void);	//state A1
void A2(void);	//state A2


// Variable declarations
void (*Alpha_State_Ptr)(void);	// Base States pointer
void (*A_Task_Ptr)(void);		// State pointer A branch

// ---------------------------------- USER -----------------------------------------
// Prototype statements for functions found within this file.
void InitEPwm1Example(void);
void InitEPwm2Example(void);
void InitEPwm3Example(void);
__interrupt void epwm1_isr(void);
__interrupt void epwm2_isr(void);
__interrupt void epwm3_isr(void);
void update_compare(EPWM_INFO*);



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

EPWM_INFO epwm1_info;
EPWM_INFO epwm2_info;
EPWM_INFO epwm3_info;

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// VARIABLE DECLARATIONS - CCS WatchWindow / GUI support
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// -------------------------------- FRAMEWORK --------------------------------------


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

	CommsOKflg = 0;
	SerialCommsTimer = 0;

// ---------------------------------- USER -----------------------------------------
//  put common initialization/variable definitions here



//==================================================================================
//	INITIALIZATION - Peripherals used
//==================================================================================

// ---------------------------------- USER -----------------------------------------
//  Put peripheral initialization here


// Initialization Time
// = = = = = = = = = = = = = = = = = = = = = = = =
	EALLOW;
	SysCtrlRegs.PCLKCR0.bit.TBCLKSYNC = 0;
	EDIS;

	InitEPwm1Example();
	InitEPwm2Example();
	InitEPwm3Example();

	EALLOW;
	SysCtrlRegs.PCLKCR0.bit.TBCLKSYNC = 1;
	EDIS;

//
// Run Time
// = = = = = = = = = = = = = = = = = = = = = = = =


//==================================================================================
//	INITIALIZATION - BUILD OPTIONS - Change in FlashingLeds-Settings.h
//==================================================================================

// ---------------------------------- USER -----------------------------------------
	
	LedBlinkTimer = 0;			//Initialize LedBlinkTimer to 0
	Gui_LedPrd_ms = 1000;		//Default to 1 blink every second


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

	Alpha_State_Ptr = &A0;		// Comment out to allow only A tasks
}


//----------------------------------- USER ----------------------------------------

__interrupt void epwm1_isr(void) {
   // Update the CMPA and CMPB values
   update_compare(&epwm1_info);

   // Clear INT flag for this timer
   EPwm1Regs.ETCLR.bit.INT = 1;
}

__interrupt void epwm2_isr(void) {
   // Update the CMPA and CMPB values
   update_compare(&epwm2_info);

   // Clear INT flag for this timer
   EPwm2Regs.ETCLR.bit.INT = 1;
}

__interrupt void epwm3_isr(void) {
   // Update the CMPA and CMPB values
   update_compare(&epwm3_info);

   // Clear INT flag for this timer
   EPwm3Regs.ETCLR.bit.INT = 1;
}

void InitEPwm1Example() {
   // Setup TBCLK
   EPwm1Regs.TBPRD = EPWM1_TIMER_TBPRD;           // Set timer period 801 TBCLKs
   EPwm1Regs.TBPHS.half.TBPHS = 0x0000;           // Phase is 0
   EPwm1Regs.TBCTR = 0x0000;                      // Clear counter

   // Set Compare values
   EPwm1Regs.CMPA.half.CMPA = EPWM1_MIN_CMPA;     // Set compare A value
   EPwm1Regs.CMPB = EPWM1_MAX_CMPB;               // Set Compare B value

   // Setup counter mode
   EPwm1Regs.TBCTL.bit.CTRMODE = TB_COUNT_UPDOWN; // Count up
   EPwm1Regs.TBCTL.bit.PHSEN = TB_DISABLE;        // Disable phase loading
   EPwm1Regs.TBCTL.bit.HSPCLKDIV = TB_DIV1;       // Clock ratio to SYSCLKOUT
   EPwm1Regs.TBCTL.bit.CLKDIV = TB_DIV1;

   // Setup shadowing
   EPwm1Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;
   EPwm1Regs.CMPCTL.bit.SHDWBMODE = CC_SHADOW;
   EPwm1Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO;  // Load on Zero
   EPwm1Regs.CMPCTL.bit.LOADBMODE = CC_CTR_ZERO;

   // Set actions
   EPwm1Regs.AQCTLA.bit.CAU = AQ_SET;             // Set PWM1A on event A, up count
   EPwm1Regs.AQCTLA.bit.CAD = AQ_CLEAR;           // Clear PWM1A on event A, down count

   EPwm1Regs.AQCTLB.bit.CBU = AQ_SET;             // Set PWM1B on event B, up count
   EPwm1Regs.AQCTLB.bit.CBD = AQ_CLEAR;           // Clear PWM1B on event B, down count

   // Interrupt where we will change the Compare Values
   EPwm1Regs.ETSEL.bit.INTSEL = ET_CTR_ZERO;      // Select INT on Zero event
   EPwm1Regs.ETSEL.bit.INTEN = 1;                 // Enable INT
   EPwm1Regs.ETPS.bit.INTPRD = ET_3RD;            // Generate INT on 3rd event

   // Information this example uses to keep track
   // of the direction the CMPA/CMPB values are
   // moving, the min and max allowed values and
   // a pointer to the correct ePWM registers
   epwm1_info.EPwm_CMPA_Direction = EPWM_CMP_UP;   // Start by increasing CMPA &
   epwm1_info.EPwm_CMPB_Direction = EPWM_CMP_DOWN; // decreasing CMPB
   epwm1_info.EPwmTimerIntCount = 0;               // Zero the interrupt counter
   epwm1_info.EPwmRegHandle = &EPwm1Regs;          // Set the pointer to the ePWM module
   epwm1_info.EPwmMaxCMPA = EPWM1_MAX_CMPA;        // Setup min/max CMPA/CMPB values
   epwm1_info.EPwmMinCMPA = EPWM1_MIN_CMPA;
   epwm1_info.EPwmMaxCMPB = EPWM1_MAX_CMPB;
   epwm1_info.EPwmMinCMPB = EPWM1_MIN_CMPB;
}

void InitEPwm2Example() {
   // Setup TBCLK
   EPwm2Regs.TBPRD = EPWM2_TIMER_TBPRD;           // Set timer period 801 TBCLKs
   EPwm2Regs.TBPHS.half.TBPHS = 0x0000;           // Phase is 0
   EPwm2Regs.TBCTR = 0x0000;                      // Clear counter

   // Set Compare values
   EPwm2Regs.CMPA.half.CMPA = EPWM2_MIN_CMPA;     // Set compare A value
   EPwm2Regs.CMPB = EPWM2_MIN_CMPB;               // Set Compare B value

   // Setup counter mode
   EPwm2Regs.TBCTL.bit.CTRMODE = TB_COUNT_UPDOWN; // Count up
   EPwm2Regs.TBCTL.bit.PHSEN = TB_DISABLE;        // Disable phase loading
   EPwm2Regs.TBCTL.bit.HSPCLKDIV = TB_DIV1;       // Clock ratio to SYSCLKOUT
   EPwm2Regs.TBCTL.bit.CLKDIV = TB_DIV1;

   // Setup shadowing
   EPwm2Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;
   EPwm2Regs.CMPCTL.bit.SHDWBMODE = CC_SHADOW;
   EPwm2Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO;  // Load on Zero
   EPwm2Regs.CMPCTL.bit.LOADBMODE = CC_CTR_ZERO;

   // Set actions
   EPwm2Regs.AQCTLA.bit.CAU = AQ_SET;            // Set PWM2A on event A, up count
   EPwm2Regs.AQCTLA.bit.CBD = AQ_CLEAR;          // Clear PWM2A on event B, down count

   EPwm2Regs.AQCTLB.bit.ZRO = AQ_CLEAR;          // Clear PWM2B on zero
   EPwm2Regs.AQCTLB.bit.PRD = AQ_SET  ;          // Set PWM2B on period

   // Interrupt where we will change the Compare Values
   EPwm2Regs.ETSEL.bit.INTSEL = ET_CTR_ZERO;     // Select INT on Zero event
   EPwm2Regs.ETSEL.bit.INTEN = 1;                // Enable INT
   EPwm2Regs.ETPS.bit.INTPRD = ET_3RD;           // Generate INT on 3rd event

   // Information this example uses to keep track
   // of the direction the CMPA/CMPB values are
   // moving, the min and max allowed values and
   // a pointer to the correct ePWM registers
   epwm2_info.EPwm_CMPA_Direction = EPWM_CMP_UP;   // Start by increasing CMPA &
   epwm2_info.EPwm_CMPB_Direction = EPWM_CMP_UP;   // increasing CMPB
   epwm2_info.EPwmTimerIntCount = 0;               // Zero the interrupt counter
   epwm2_info.EPwmRegHandle = &EPwm2Regs;          // Set the pointer to the ePWM module
   epwm2_info.EPwmMaxCMPA = EPWM2_MAX_CMPA;        // Setup min/max CMPA/CMPB values
   epwm2_info.EPwmMinCMPA = EPWM2_MIN_CMPA;
   epwm2_info.EPwmMaxCMPB = EPWM2_MAX_CMPB;
   epwm2_info.EPwmMinCMPB = EPWM2_MIN_CMPB;

}

void InitEPwm3Example(void) {
   // Setup TBCLK
   EPwm3Regs.TBCTL.bit.CTRMODE = TB_COUNT_UPDOWN;// Count up/down
   EPwm3Regs.TBPRD = EPWM3_TIMER_TBPRD;          // Set timer period
   EPwm3Regs.TBCTL.bit.PHSEN = TB_DISABLE;       // Disable phase loading
   EPwm3Regs.TBPHS.half.TBPHS = 0x0000;          // Phase is 0
   EPwm3Regs.TBCTR = 0x0000;                     // Clear counter
   EPwm3Regs.TBCTL.bit.HSPCLKDIV = TB_DIV1;      // Clock ratio to SYSCLKOUT
   EPwm3Regs.TBCTL.bit.CLKDIV = TB_DIV1;

   // Setup shadow register load on ZERO
   EPwm3Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;
   EPwm3Regs.CMPCTL.bit.SHDWBMODE = CC_SHADOW;
   EPwm3Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO;
   EPwm3Regs.CMPCTL.bit.LOADBMODE = CC_CTR_ZERO;

  // Set Compare values
   EPwm3Regs.CMPA.half.CMPA = EPWM3_MIN_CMPA;    // Set compare A value
   EPwm3Regs.CMPB = EPWM3_MAX_CMPB;              // Set Compare B value

   // Set Actions
   EPwm3Regs.AQCTLA.bit.PRD = AQ_SET;            // Set PWM3A on period
   EPwm3Regs.AQCTLA.bit.CBD = AQ_CLEAR;          // Clear PWM3A on event B, down count

   EPwm3Regs.AQCTLB.bit.PRD = AQ_CLEAR;          // Clear PWM3A on period
   EPwm3Regs.AQCTLB.bit.CAU = AQ_SET;            // Set PWM3A on event A, up count

   // Interrupt where we will change the Compare Values
   EPwm3Regs.ETSEL.bit.INTSEL = ET_CTR_ZERO;     // Select INT on Zero event
   EPwm3Regs.ETSEL.bit.INTEN = 1;                // Enable INT
   EPwm3Regs.ETPS.bit.INTPRD = ET_3RD;           // Generate INT on 3rd event

   // Information this example uses to keep track
   // of the direction the CMPA/CMPB values are
   // moving, the min and max allowed values and
   // a pointer to the correct ePWM registers
   epwm3_info.EPwm_CMPA_Direction = EPWM_CMP_UP;   // Start by increasing CMPA &
   epwm3_info.EPwm_CMPB_Direction = EPWM_CMP_DOWN; // decreasing CMPB
   epwm3_info.EPwmTimerIntCount = 0;               // Zero the interrupt counter
   epwm3_info.EPwmRegHandle = &EPwm3Regs;          // Set the pointer to the ePWM module
   epwm3_info.EPwmMaxCMPA = EPWM3_MAX_CMPA;        // Setup min/max CMPA/CMPB values
   epwm3_info.EPwmMinCMPA = EPWM3_MIN_CMPA;
   epwm3_info.EPwmMaxCMPB = EPWM3_MAX_CMPB;
   epwm3_info.EPwmMinCMPB = EPWM3_MIN_CMPB;
}

void update_compare(EPWM_INFO *epwm_info) {
   // Every 10'th interrupt, change the CMPA/CMPB values
   if(epwm_info->EPwmTimerIntCount == 10) {
	   epwm_info->EPwmTimerIntCount = 0;

	   // If we were increasing CMPA, check to see if
	   // we reached the max value.  If not, increase CMPA
	   // else, change directions and decrease CMPA
	   if(epwm_info->EPwm_CMPA_Direction == EPWM_CMP_UP) {
		   if(epwm_info->EPwmRegHandle->CMPA.half.CMPA < epwm_info->EPwmMaxCMPA) {
			  epwm_info->EPwmRegHandle->CMPA.half.CMPA++;
		   }
		   else {
			  epwm_info->EPwm_CMPA_Direction = EPWM_CMP_DOWN;
			  epwm_info->EPwmRegHandle->CMPA.half.CMPA--;
		   }
	   }

	   // If we were decreasing CMPA, check to see if
	   // we reached the min value.  If not, decrease CMPA
	   // else, change directions and increase CMPA
	   else {
		   if(epwm_info->EPwmRegHandle->CMPA.half.CMPA == epwm_info->EPwmMinCMPA) {
			  epwm_info->EPwm_CMPA_Direction = EPWM_CMP_UP;
			  epwm_info->EPwmRegHandle->CMPA.half.CMPA++;
		   }
		   else {
			  epwm_info->EPwmRegHandle->CMPA.half.CMPA--;
		   }
	   }

	   // If we were increasing CMPB, check to see if
	   // we reached the max value.  If not, increase CMPB
	   // else, change directions and decrease CMPB
	   if(epwm_info->EPwm_CMPB_Direction == EPWM_CMP_UP) {
		   if(epwm_info->EPwmRegHandle->CMPB < epwm_info->EPwmMaxCMPB) {
			  epwm_info->EPwmRegHandle->CMPB++;
		   }
		   else {
			  epwm_info->EPwm_CMPB_Direction = EPWM_CMP_DOWN;
			  epwm_info->EPwmRegHandle->CMPB--;
		   }
	   }

	   // If we were decreasing CMPB, check to see if
	   // we reached the min value.  If not, decrease CMPB
	   // else, change directions and increase CMPB

	   else {
		   if(epwm_info->EPwmRegHandle->CMPB == epwm_info->EPwmMinCMPB) {
			  epwm_info->EPwm_CMPB_Direction = EPWM_CMP_UP;
			  epwm_info->EPwmRegHandle->CMPB++;
		   }
		   else {
			  epwm_info->EPwmRegHandle->CMPB--;
		   }
	   }
   }
   else {
	  epwm_info->EPwmTimerIntCount++;
   }

   return;
}

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
