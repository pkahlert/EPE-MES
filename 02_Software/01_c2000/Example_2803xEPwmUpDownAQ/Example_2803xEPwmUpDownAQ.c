//###########################################################################
// Description:
//! \addtogroup f2803x_example_list
//! <h1>ePWM Action Qualifier Module using up/down count (epwm_updown_aq)</h1>
//!
//! This example configures ePWM1, ePWM2, ePWM3 to produce an waveform with
//! independent modulation on EPWMxA and EPWMxB. The compare values CMPA
//! and CMPB are modified within the ePWM's ISR. The TB counter is in up/down
//! count mode for this example.
//!
//! Monitor ePWM1-ePWM3 pins on an oscilloscope as described
//!
//! \b External \b Connections \n
//!  - EPWM1A is on GPIO0
//!  - EPWM1B is on GPIO1
//!  - EPWM2A is on GPIO2
//!  - EPWM2B is on GPIO3
//!  - EPWM3A is on GPIO4
//!  - EPWM3B is on GPIO5
//
//###########################################################################
// $TI Release: F2803x C/C++ Header Files and Peripheral Examples V130 $
// $Release Date: May  8, 2015 $
// $Copyright: Copyright (C) 2009-2015 Texas Instruments Incorporated -
//             http://www.ti.com/ ALL RIGHTS RESERVED $
//###########################################################################

#include "DSP28x_Project.h"     // Device Headerfile and Examples Include File
#include "math.h"

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
   float dutyA;
   float dutyB;
}EPWM_INFO;

// Prototype statements for functions found within this file.
void InitEPwm1Example(void);
void InitEPwm2Example(void);
void InitEPwm3Example(void);
__interrupt void epwm1_isr(void);
__interrupt void epwm2_isr(void);
__interrupt void epwm3_isr(void);
__interrupt void xint2_isr(void);
void update_compare1(EPWM_INFO*);
void update_compare2(EPWM_INFO*);
void update_compare3(EPWM_INFO*);

// Global variables used in this example
EPWM_INFO epwm1_info;
EPWM_INFO epwm2_info;
EPWM_INFO epwm3_info;

/*epwm1_info.EPwmRegHandle = &EPwm1Regs;
epwm2_info.EPwmRegHandle = &EPwm2Regs;
epwm3_info.EPwmRegHandle = &EPwm3Regs;
*/

// Configure the period for each timer

#define EPWM_TIMER_TBPRD  2000  // Period register
#define EPWM_START_CMP 200 // default cmp
#define EPWM_START_DUTY 0.2

void InitEPwm1Example() {
	EPwm1Regs.TBPRD = EPWM_TIMER_TBPRD;           // Set timer period 801 TBCLKs
	EPwm1Regs.TBPHS.half.TBPHS = 0;           // Phase is 0
	//   EPwm1Regs.TBCTR = 0x0000;                      // Clear counter

	// Set Compare values
	EPwm1Regs.CMPA.half.CMPA = EPWM_START_CMP;     // Set compare A value

	// Setup counter mode
	EPwm1Regs.TBCTL.bit.CTRMODE = TB_COUNT_UPDOWN; //UPDOWN // Count up
	EPwm1Regs.TBCTL.bit.PHSEN = TB_DISABLE;        // Disable phase loading
	EPwm2Regs.TBCTL.bit.PRDLD = TB_SHADOW;
	EPwm1Regs.TBCTL.bit.SYNCOSEL = TB_CTR_ZERO; // Sync down-stream module

	// Setup shadowing
	EPwm1Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;
	EPwm1Regs.CMPCTL.bit.SHDWBMODE = CC_SHADOW;
	EPwm1Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO;  // Load on Zero
	EPwm1Regs.CMPCTL.bit.LOADBMODE = CC_CTR_ZERO;

	// Set actions
	EPwm1Regs.AQCTLA.bit.CAU = AQ_SET;             // Set PWM1A on event A, up count
	EPwm1Regs.AQCTLA.bit.CAD = AQ_CLEAR;           // Clear PWM1A on event A, down count
	//  EPwm1Regs.AQCTLA.bit.ZRO = AQ_TOGGLE; //#DEBUG

	// Interrupt where we will change the Compare Values
	EPwm1Regs.ETSEL.bit.INTSEL = ET_CTR_ZERO;      // Select INT on Zero event
	EPwm1Regs.ETSEL.bit.INTEN = 1;                 // Enable INT
	EPwm1Regs.ETPS.bit.INTPRD = ET_3RD;            // Generate INT on 3rd event

	EPwm1Regs.DBCTL.bit.OUT_MODE = DB_FULL_ENABLE;
	EPwm1Regs.DBCTL.bit.POLSEL = DB_ACTV_HIC;
	EPwm1Regs.DBFED = 20;
	EPwm1Regs.DBRED = 20;

//	epwm1_info.EPwmRegHandle = &EPwm1Regs;          // Set the pointer to the ePWM module
	epwm1_info.dutyA = EPWM_START_DUTY;
	epwm1_info.dutyB = EPWM_START_DUTY;
}

void InitEPwm2Example() {
	EPwm2Regs.TBPRD = EPWM_TIMER_TBPRD;           // Set timer period 801 TBCLKs
	EPwm2Regs.TBPHS.half.TBPHS = 2*EPWM_TIMER_TBPRD/3;           // Phase is 0

	// Set Compare values
	EPwm2Regs.CMPA.half.CMPA = EPWM_START_CMP; //EPWM_START_CMP;     // Set compare A value

	// Setup counter mode
	EPwm2Regs.TBCTL.bit.CTRMODE = TB_COUNT_UPDOWN; //TB_COUNT_UPDOWN; // Count up
	EPwm2Regs.TBCTL.bit.PHSEN = TB_ENABLE; //#DEBUG TB_DISABLE;        // Disable phase loading
	EPwm2Regs.TBCTL.bit.PHSDIR = TB_DOWN;
	EPwm2Regs.TBCTL.bit.PRDLD = TB_SHADOW;
	EPwm2Regs.TBCTL.bit.SYNCOSEL = TB_SYNC_IN; // sync flow-through

	// Setup shadowing
	EPwm2Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;
	EPwm2Regs.CMPCTL.bit.SHDWBMODE = CC_SHADOW;
	EPwm2Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO;  // Load on Zero
	EPwm2Regs.CMPCTL.bit.LOADBMODE = CC_CTR_ZERO;

	// Set actions
	EPwm2Regs.AQCTLA.bit.CAU = AQ_SET;             // Set PWM1A on event A, up count
	EPwm2Regs.AQCTLA.bit.CAD = AQ_CLEAR;           // Clear PWM1A on event A, down count
	// EPwm2Regs.AQCTLA.bit.ZRO = AQ_TOGGLE; //in case of TB_COUNT_DOWN


	// Interrupt where we will change the Compare Values
	EPwm2Regs.ETSEL.bit.INTSEL = ET_CTR_ZERO;      // Select INT on Zero event
	EPwm2Regs.ETSEL.bit.INTEN = 1;                 // Enable INT
	EPwm2Regs.ETPS.bit.INTPRD = ET_3RD;            // Generate INT on 3rd event

	// #TODO anpassen oder raus?
	EPwm2Regs.DBCTL.bit.OUT_MODE = DB_FULL_ENABLE;
	EPwm2Regs.DBCTL.bit.POLSEL = DB_ACTV_HIC;
	EPwm2Regs.DBFED = 20;
	EPwm2Regs.DBRED = 20;

	epwm2_info.dutyA = EPWM_START_DUTY;
	epwm2_info.dutyB = EPWM_START_DUTY;
//	epwm2_info.EPwmRegHandle = &EPwm2Regs;          // Set the pointer to the ePWM module
}

void InitEPwm3Example() {
	EPwm3Regs.TBPRD = EPWM_TIMER_TBPRD;           // Set timer period 801 TBCLKs
   EPwm3Regs.TBPHS.half.TBPHS = 2*EPWM_TIMER_TBPRD/3;           // Phase is 0

   // Set Compare values
   EPwm3Regs.CMPA.half.CMPA = EPWM_START_CMP; //EPWM_START_CMP;     // Set compare A value

   // Setup counter mode
   EPwm3Regs.TBCTL.bit.CTRMODE = TB_COUNT_UPDOWN; //TB_COUNT_UPDOWN; // Count up
   EPwm3Regs.TBCTL.bit.PHSEN = TB_ENABLE; //#DEBUG TB_DISABLE;        // Disable phase loading
   EPwm3Regs.TBCTL.bit.PHSDIR = TB_UP;
   EPwm3Regs.TBCTL.bit.PRDLD = TB_SHADOW;
   EPwm3Regs.TBCTL.bit.SYNCOSEL = TB_SYNC_IN; // sync flow-through

   // Setup shadowing
   EPwm3Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;
   EPwm3Regs.CMPCTL.bit.SHDWBMODE = CC_SHADOW;
   EPwm3Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO;  // Load on Zero
   EPwm3Regs.CMPCTL.bit.LOADBMODE = CC_CTR_ZERO;

   // Set actions
   EPwm3Regs.AQCTLA.bit.CAU = AQ_SET;             // Set PWM1A on event A, up count
   EPwm3Regs.AQCTLA.bit.CAD = AQ_CLEAR;           // Clear PWM1A on event A, down count
  // EPwm3Regs.AQCTLA.bit.ZRO = AQ_TOGGLE; //in case of TB_COUNT_DOWN

   // Interrupt where we will change the Compare Values
	EPwm3Regs.ETSEL.bit.INTSEL = ET_CTR_ZERO;      // Select INT on Zero event
	EPwm3Regs.ETSEL.bit.INTEN = 1;                 // Enable INT
	EPwm3Regs.ETPS.bit.INTPRD = ET_3RD;            // Generate INT on 3rd event

   EPwm3Regs.DBCTL.bit.OUT_MODE = DB_FULL_ENABLE;
   EPwm3Regs.DBCTL.bit.POLSEL = DB_ACTV_HIC;
   EPwm3Regs.DBFED = 20;
   EPwm3Regs.DBRED = 20;

   //epwm3_info.EPwmRegHandle = &EPwm3Regs;          // Set the pointer to the ePWM module
   epwm3_info.dutyA = EPWM_START_DUTY;
   epwm3_info.dutyB = EPWM_START_DUTY;
}
//----------------------------------
//---- FLOATING TIMESTAMP BUFFER ---
//----------------------------------
/*typedef struct {

} timestampBuffer;
*/

void main(void)
{
// Step 1. Initialize System Control:
// PLL, WatchDog, enable Peripheral Clocks
// This example function is found in the DSP2803x_SysCtrl.c file.
    InitSysCtrl();

// Step 2. Initialize GPIO:
// This example function is found in the DSP2803x_Gpio.c file and
// illustrates how to set the GPIO to it's default state.
  //-------------------------
  //---- GPIO PREPARATION ---
  //-------------------------

  // Configure GPIO34 as a GPIO output pin
  EALLOW;
  GpioCtrlRegs.GPBMUX1.bit.GPIO34 = 0;
  GpioCtrlRegs.GPBDIR.bit.GPIO34 = 1;
  EDIS;

  // Make GPIO26 the input source for XINT2
  EALLOW;
  GpioCtrlRegs.GPAPUD.bit.GPIO26 = 1; // pullup disable
  GpioCtrlRegs.GPAMUX2.bit.GPIO26 = 0;  // GPIO26 = GPIO26
  GpioCtrlRegs.GPADIR.bit.GPIO26 = 0;   // GPIO26 = input
  GpioCtrlRegs.GPAQSEL2.bit.GPIO26 = 0;
  GpioIntRegs.GPIOXINT2SEL.bit.GPIOSEL = 26;    // XINT2 connected to GPIO26

  GpioDataRegs.GPADAT.bit.GPIO26 = 0;

  XIntruptRegs.XINT2CR.bit.POLARITY = 1;      // Rising edge interrupt
  XIntruptRegs.XINT2CR.bit.ENABLE = 1;        // Enable XINT2

  EDIS;


// InitGpio();  // Skipped for this example

// For this case just init GPIO pins for ePWM1, ePWM2, ePWM3
// These functions are in the DSP2803x_EPwm.c file
   InitEPwm1Gpio();
   InitEPwm2Gpio();
   InitEPwm3Gpio();

// Step 3. Clear all interrupts and initialize PIE vector table:
// Disable CPU interrupts
   DINT;

// Initialize the PIE control registers to their default state.
// The default state is all PIE interrupts disabled and flags
// are cleared.
// This function is found in the DSP2803x_PieCtrl.c file.
   InitPieCtrl();

// Disable CPU interrupts and clear all CPU interrupt flags:
   IER = 0x0000;
   IFR = 0x0000;

// Initialize the PIE vector table with pointers to the shell Interrupt
// Service Routines (ISR).
// This will populate the entire table, even if the interrupt
// is not used in this example.  This is useful for debug purposes.
// The shell ISR routines are found in DSP2803x_DefaultIsr.c.
// This function is found in DSP2803x_PieVect.c.
   InitPieVectTable();

// Interrupts that are used in this example are re-mapped to
// ISR functions found within this file.
   EALLOW;
   PieVectTable.EPWM1_INT = &epwm1_isr;
   PieVectTable.EPWM2_INT = &epwm2_isr;
   PieVectTable.EPWM3_INT = &epwm3_isr;
   PieVectTable.XINT2 = &xint2_isr;
   EDIS;

   // Step 4. Initialize all the Device Peripherals:


   //-------------------------
   //---- PWM PREPARATION ----
   //-------------------------
   EALLOW;
   SysCtrlRegs.PCLKCR0.bit.TBCLKSYNC = 0;
   EDIS;

   InitEPwm1Example();
   InitEPwm2Example();
   InitEPwm3Example();

   EALLOW;
   SysCtrlRegs.PCLKCR0.bit.TBCLKSYNC = 1;
   EDIS;

// Step 5. User specific code, enable interrupts:


// Enable CPU INT3 which is connected to EPWM1-3 INT:
   IER |= M_INT3;
   IER |= 0x0003;

// Enable EPWM INTn in the PIE: Group 3 interrupt 1-3
   PieCtrlRegs.PIEIER3.bit.INTx1 = 1;
   PieCtrlRegs.PIEIER3.bit.INTx2 = 1;
   PieCtrlRegs.PIEIER3.bit.INTx3 = 1;

   PieCtrlRegs.PIEIER1.bit.INTx5 = 1;
   PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;

// Enable global Interrupts and higher priority real-time debug events:
   EINT;   // Enable Global interrupt INTM
   ERTM;   // Enable Global realtime interrupt DBGM

// Step 6. IDLE loop. Just sit and loop forever (optional):
   for(;;)
   {
       __asm("          NOP");
   }
}

//------------------------
//---- GPIO INTERRUPT ----
//------------------------

int t1 = 0;
float duty = 0.5;

__interrupt void xint2_isr(void)
{
	GpioDataRegs.GPACLEAR.bit.GPIO26 = 1;   // GPIO26 is low

	t1++;
	if (t1 >= 1000) {
		t1 = 0;

		// Toggle LED
		GpioDataRegs.GPBTOGGLE.bit.GPIO34 = 1;
	}

	// Acknowledge this interrupt to get more from group 1
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;
}

__interrupt void epwm1_isr(void)
{
   // Update the CMPA and CMPB values
   update_compare1(&epwm1_info);

   // Clear INT flag for this timer
   EPwm1Regs.ETCLR.bit.INT = 1;

   // Acknowledge this interrupt to receive more interrupts from group 3
   PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;
}

__interrupt void epwm2_isr(void)
{
   // Update the CMPA and CMPB values
   update_compare2(&epwm2_info);

   // Clear INT flag for this timer
   EPwm2Regs.ETCLR.bit.INT = 1;

   // Acknowledge this interrupt to receive more interrupts from group 3
   PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;
}

__interrupt void epwm3_isr(void)
{
   // Update the CMPA and CMPB values
   update_compare3(&epwm3_info);

   // Clear INT flag for this timer
   EPwm3Regs.ETCLR.bit.INT = 1;

   // Acknowledge this interrupt to receive more interrupts from group 3
   PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;
}


/*void update_compare(EPWM_INFO *epwm_info) {
	epwm_info->EPwmRegHandle->CMPA.half.CMPA = (1 - epwm_info->dutyA) * EPWM_TIMER_TBPRD;
	epwm_info->EPwmRegHandle->CMPB = (1- epwm_info->dutyB) * EPWM_TIMER_TBPRD;
	return;
}*/

void update_compare1(EPWM_INFO *epwm_info) {
	EPwm1Regs.CMPA.half.CMPA = (1 - epwm_info->dutyA) * EPWM_TIMER_TBPRD;
	return;
}
void update_compare2(EPWM_INFO *epwm_info) {
	EPwm2Regs.CMPA.half.CMPA = (1 - epwm_info->dutyA) * EPWM_TIMER_TBPRD;
	return;
}
void update_compare3(EPWM_INFO *epwm_info) {
	EPwm3Regs.CMPA.half.CMPA = (1 - epwm_info->dutyA) * EPWM_TIMER_TBPRD;
	return;
}


//===========================================================================
// No more.
//===========================================================================

