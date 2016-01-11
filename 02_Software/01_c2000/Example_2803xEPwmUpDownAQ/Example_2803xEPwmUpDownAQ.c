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
   Uint16 index;
}EPWM_INFO;

// Prototype statements for functions found within this file.
void InitEPwmExample(EPWM_INFO*);
__interrupt void epwm1_isr(void);
__interrupt void epwm2_isr(void);
__interrupt void epwm3_isr(void);
void update_compare(EPWM_INFO*);

// Global variables used in this example
EPWM_INFO epwm1_info;
EPWM_INFO epwm2_info;
EPWM_INFO epwm3_info;

/*epwm1_info.EPwmRegHandle = &EPwm1Regs;
epwm2_info.EPwmRegHandle = &EPwm2Regs;
epwm3_info.EPwmRegHandle = &EPwm3Regs;
*/

// Configure the period for each timer

#define EPWM1_TIMER_TBPRD  2000  // Period register
#define EPWM1_MAX_CMPA     1000
#define EPWM1_MIN_CMPA      999
#define EPWM1_MAX_CMPB     1999
#define EPWM1_MIN_CMPB     1000

/*
#define EPWM2_TIMER_TBPRD  2000  // Period register
#define EPWM2_MAX_CMPA     1000
#define EPWM2_MIN_CMPA      999
#define EPWM2_MAX_CMPB     1000
#define EPWM2_MIN_CMPB      999

#define EPWM3_TIMER_TBPRD  2000  // Period register
#define EPWM3_MAX_CMPA     1000
#define EPWM3_MIN_CMPA      999
#define EPWM3_MAX_CMPB     1000
#define EPWM3_MIN_CMPB      999

// To keep track of which way the compare value is moving
#define EPWM_CMP_UP   1
#define EPWM_CMP_DOWN 0
*/

#define EPWM_TIMER_TBPRD  2000  // Period register
#define EPWM_START_CMP 100 // default cmp

void InitEPwmExample(EPWM_INFO *epwm_info)
{
	// Setup TBCLK
	static Uint16 i = 0;
	epwm_info->index = i;

	switch (epwm_info->index+1) {
	case 1:
		EPwm1Regs.TBPRD = EPWM_TIMER_TBPRD;           // Set timer period 801 TBCLKs
	   EPwm1Regs.TBPHS.half.TBPHS = 0x0000;           // Phase is 0
	   EPwm1Regs.TBCTR = 0x0000;                      // Clear counter

	   // Set Compare values
	   EPwm1Regs.CMPA.half.CMPA = EPWM_START_CMP;     // Set compare A value
	   EPwm1Regs.CMPB = EPWM_START_CMP;               // Set Compare B value

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
	   epwm_info->EPwmRegHandle = &EPwm1Regs;          // Set the pointer to the ePWM module
	   break;
	case 2:
		EPwm2Regs.TBPRD = EPWM_TIMER_TBPRD;           // Set timer period 801 TBCLKs
	   EPwm2Regs.TBPHS.half.TBPHS = 0x0000;           // Phase is 0
	   EPwm2Regs.TBCTR = 0x0000;                      // Clear counter

	   // Set Compare values
	   EPwm2Regs.CMPA.half.CMPA = EPWM_START_CMP;     // Set compare A value
	   EPwm2Regs.CMPB = EPWM_START_CMP;               // Set Compare B value

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
	   EPwm2Regs.AQCTLA.bit.CAU = AQ_SET;             // Set PWM1A on event A, up count
	   EPwm2Regs.AQCTLA.bit.CAD = AQ_CLEAR;           // Clear PWM1A on event A, down count

	   EPwm2Regs.AQCTLB.bit.CBU = AQ_SET;             // Set PWM1B on event B, up count
	   EPwm2Regs.AQCTLB.bit.CBD = AQ_CLEAR;           // Clear PWM1B on event B, down count

	   // Interrupt where we will change the Compare Values
	   EPwm2Regs.ETSEL.bit.INTSEL = ET_CTR_ZERO;      // Select INT on Zero event
	   EPwm2Regs.ETSEL.bit.INTEN = 1;                 // Enable INT
	   EPwm2Regs.ETPS.bit.INTPRD = ET_3RD;            // Generate INT on 3rd event
	   epwm_info->EPwmRegHandle = &EPwm2Regs;          // Set the pointer to the ePWM module
	   break;
	case 3:
		EPwm3Regs.TBPRD = EPWM_TIMER_TBPRD;           // Set timer period 801 TBCLKs
	   EPwm3Regs.TBPHS.half.TBPHS = 0x0000;           // Phase is 0
	   EPwm3Regs.TBCTR = 0x0000;                      // Clear counter

	   // Set Compare values
	   EPwm3Regs.CMPA.half.CMPA = EPWM_START_CMP;     // Set compare A value
	   EPwm3Regs.CMPB = EPWM_START_CMP;               // Set Compare B value

	   // Setup counter mode
	   EPwm3Regs.TBCTL.bit.CTRMODE = TB_COUNT_UPDOWN; // Count up
	   EPwm3Regs.TBCTL.bit.PHSEN = TB_DISABLE;        // Disable phase loading
	   EPwm3Regs.TBCTL.bit.HSPCLKDIV = TB_DIV1;       // Clock ratio to SYSCLKOUT
	   EPwm3Regs.TBCTL.bit.CLKDIV = TB_DIV1;

	   // Setup shadowing
	   EPwm3Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;
	   EPwm3Regs.CMPCTL.bit.SHDWBMODE = CC_SHADOW;
	   EPwm3Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO;  // Load on Zero
	   EPwm3Regs.CMPCTL.bit.LOADBMODE = CC_CTR_ZERO;

	   // Set actions
	   EPwm3Regs.AQCTLA.bit.CAU = AQ_SET;             // Set PWM1A on event A, up count
	   EPwm3Regs.AQCTLA.bit.CAD = AQ_CLEAR;           // Clear PWM1A on event A, down count

	   EPwm3Regs.AQCTLB.bit.CBU = AQ_SET;             // Set PWM1B on event B, up count
	   EPwm3Regs.AQCTLB.bit.CBD = AQ_CLEAR;           // Clear PWM1B on event B, down count

	   // Interrupt where we will change the Compare Values
	   EPwm3Regs.ETSEL.bit.INTSEL = ET_CTR_ZERO;      // Select INT on Zero event
	   EPwm3Regs.ETSEL.bit.INTEN = 1;                 // Enable INT
	   EPwm3Regs.ETPS.bit.INTPRD = ET_3RD;            // Generate INT on 3rd event
	   epwm_info->EPwmRegHandle = &EPwm3Regs;          // Set the pointer to the ePWM module
	   break;
	}

	i++;



   // Information this example uses to keep track
   // of the direction the CMPA/CMPB values are
   // moving, the min and max allowed values and
   // a pointer to the correct ePWM registers
   epwm_info->EPwm_CMPA_Direction = 1;   // Start by increasing CMPA &
   epwm_info->EPwm_CMPB_Direction = 1; // decreasing CMPB
   epwm_info->EPwmTimerIntCount = 0;               // Zero the interrupt counter
   epwm_info->EPwmMaxCMPA = EPWM1_MAX_CMPA;        // Setup min/max CMPA/CMPB values
   epwm_info->EPwmMinCMPA = EPWM1_MIN_CMPA;
   epwm_info->EPwmMaxCMPB = EPWM1_MAX_CMPB;
   epwm_info->EPwmMinCMPB = EPWM1_MIN_CMPB;
}


void main(void)
{
// Step 1. Initialize System Control:
// PLL, WatchDog, enable Peripheral Clocks
// This example function is found in the DSP2803x_SysCtrl.c file.
   InitSysCtrl();

// Step 2. Initialize GPIO:
// This example function is found in the DSP2803x_Gpio.c file and
// illustrates how to set the GPIO to it's default state.
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
   EALLOW;  // This is needed to write to EALLOW protected registers
   PieVectTable.EPWM1_INT = &epwm1_isr;
   PieVectTable.EPWM2_INT = &epwm2_isr;
   PieVectTable.EPWM3_INT = &epwm3_isr;
   EDIS;    // This is needed to disable write to EALLOW protected registers

// Step 4. Initialize all the Device Peripherals:
// Not required for this example

// For this example, only initialize the ePWM
   EALLOW;
   SysCtrlRegs.PCLKCR0.bit.TBCLKSYNC = 0;
   EDIS;

   InitEPwmExample(&epwm1_info);
   InitEPwmExample(&epwm2_info);
   InitEPwmExample(&epwm3_info);

   EALLOW;
   SysCtrlRegs.PCLKCR0.bit.TBCLKSYNC = 1;
   EDIS;

// Step 5. User specific code, enable interrupts:
   // Configure GPIO34 as a GPIO output pin
   EALLOW;
   GpioCtrlRegs.GPBMUX1.bit.GPIO34 = 0;
   GpioCtrlRegs.GPBDIR.bit.GPIO34 = 1;
   EDIS;


// Enable CPU INT3 which is connected to EPWM1-3 INT:
   IER |= M_INT3;

// Enable EPWM INTn in the PIE: Group 3 interrupt 1-3
   PieCtrlRegs.PIEIER3.bit.INTx1 = 1;
   PieCtrlRegs.PIEIER3.bit.INTx2 = 1;
   PieCtrlRegs.PIEIER3.bit.INTx3 = 1;

// Enable global Interrupts and higher priority real-time debug events:
   EINT;   // Enable Global interrupt INTM
   ERTM;   // Enable Global realtime interrupt DBGM

// Step 6. IDLE loop. Just sit and loop forever (optional):
   for(;;)
   {
       __asm("          NOP");
   }
}

__interrupt void epwm1_isr(void)
{
   // Update the CMPA and CMPB values
   update_compare(&epwm1_info);

   // Clear INT flag for this timer
   EPwm1Regs.ETCLR.bit.INT = 1;

   // Acknowledge this interrupt to receive more interrupts from group 3
   PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;
}

__interrupt void epwm2_isr(void)
{
   // Update the CMPA and CMPB values
   update_compare(&epwm2_info);

   // Clear INT flag for this timer
   EPwm2Regs.ETCLR.bit.INT = 1;

   // Acknowledge this interrupt to receive more interrupts from group 3
   PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;
}

__interrupt void epwm3_isr(void)
{
   // Update the CMPA and CMPB values
   update_compare(&epwm3_info);

   // Clear INT flag for this timer
   EPwm3Regs.ETCLR.bit.INT = 1;

   // Acknowledge this interrupt to receive more interrupts from group 3
   PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;
}


int t1 = 0;
float duty = 0.5;

void update_compare(EPWM_INFO *epwm_info) {
	t1++;
	if (t1 >= 1000) {
		t1 = 0;

		// Toggle LED
		GpioDataRegs.GPBTOGGLE.bit.GPIO34 = 1;
	}

	epwm_info->EPwmRegHandle->CMPA.half.CMPA = (1- duty) * 2000;
	return;
}

//===========================================================================
// No more.
//===========================================================================

