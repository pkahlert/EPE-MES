#/* ==============================================================================
System Name:  	HVACI_Sensored
File Name:	  	HVACI_Sensored.C

Description:	Primary system file by TI for the Real Implementation of Sensored  
          		Field Orientation Control for Induction Motors. 
          		CAN Communication for setpoint control and system monitoring added
          		by Tobias Wurm.
          		 
Originator:		Digital control systems Group - Texas Instruments 
				Tobias Wurm - Beuth Hochschule, Berlin
=====================================================================================
-------------------------------------------------------------------------------------
 02-05-2013 Version 1: Supports F2803x  
-------------------------------------------------------------------------------------
=================================================================================  */
  
// Include header files used for FOC (Field Oriented Control) in the main function
//-----------------------------------------------------------------------
#include "PeripheralHeaderIncludes.h" 	// Includes peripheral headers
										//( DSP2803x_Gpio.h, DSP2803x_ECan.h, ... )
#include "IQmathLib.h"
#include "HVACI_Sensored.h" 	// Includes project specific stuff
								//( clarke.h, cur_mod.h, .... )
#include "HVACI_Sensored-Settings.h"
#include <math.h>

//The CODE_SECTION pragma allocates space for the func in a section named section name.
#ifdef FLASH
#pragma CODE_SECTION(MainISR,"ramfuncs");	
#endif

// Prototype statements for functions found within this file.
//-----------------------------------------------------------------------
//FOC Prototypes
interrupt void MainISR(void);
void DeviceInit();
void MemCopy();
void InitFlash();
void HVDMC_Protection(void);

//CAN Prototypes
void mailbox_read(int16 i);

// State Machine function prototypes
//-----------------------------------------------------------------------
// Alpha states
void A0(void);	//state A0
void B0(void);	//state B0
void C0(void);	//state C0

// A branch states
void A1(void);	//state A1
void A2(void);	//state A2
void A3(void);	//state A3

// B branch states
void B1(void);	//state B1
void B2(void);	//state B2
void B3(void);	//state B3

// C branch states
void C1(void);	//state C1
void C2(void);	//state C2
void C3(void);	//state C3

// Other Variable declarations
//-----------------------------------------------------------------------
void (*Alpha_State_Ptr)(void);	// Base States pointer
void (*A_Task_Ptr)(void);		// State pointer A branch
void (*B_Task_Ptr)(void);		// State pointer B branch
void (*C_Task_Ptr)(void);		// State pointer C branch

// Used for running BackGround in flash, and ISR in RAM
extern Uint16 *RamfuncsLoadStart, *RamfuncsLoadEnd, *RamfuncsRunStart;

// VTimer[] are incremented on every Alpha State run through but nothing   
// is done with the value.		
int16	VTimer0[4];			// Virtual Timers slaved off CPU Timer 0 (A events)
int16	VTimer1[4]; 		// Virtual Timers slaved off CPU Timer 1 (B events)
int16	VTimer2[4]; 		// Virtual Timers slaved off CPU Timer 2 (C events)
int16	SerialCommsTimer;

// Global variables used in this system
//-----------------------------------------------------------------------
///////////////// CAN - Variables ///////////////////////
Uint32  ErrorCount = 0;
Uint32  PassCount = 0;

Uint32 LifeSign= 0;

struct {
	Uint32  receiveMDH;
	Uint32  receiveMDL;
	Uint32  receiveMSGID;
} receiveCAN[16];

int MNr=16;
int gpioToggle=0;
///////////////// CAN - Variables END ///////////////////


// Values after Level 2 Incremental Build
_iq VdTesting = _IQ(0);			// Vd reference (pu) 
_iq VqTesting = _IQ(0);			// Vq reference (pu)

_iq IdRef = _IQ(0.05);				// Id reference (pu) 
_iq IqRef = _IQ(0.02);				// Iq reference (pu) 

// Values after Level 2 Incremental Build
_iq SpeedRef = _IQ(0);			// Speed reference (pu)

float32 T = 0.001/ISR_FREQUENCY;    // Samping period (sec), see parameter.h 

Uint32 IsrTicker = 0;
Uint16 BackTicker = 0;
Uint16 lsw=0;
Uint16 TripFlagDMC=0;				//PWM trip status 

int16 PwmDacCh1=0;
int16 PwmDacCh2=0;
int16 PwmDacCh3=0;
int16 PwmDacCh4=0;

int16 DlogCh1 = 0;
int16 DlogCh2 = 0;
int16 DlogCh3 = 0;
int16 DlogCh4 = 0;

volatile Uint16 EnableFlag = TRUE;

Uint16 SpeedLoopPrescaler = 10;      // Speed loop prescaler
Uint16 SpeedLoopCount = 1;           // Speed loop counter

// Instancing object 
//-----------------------------------------------------------------------
// Instancing objects is pretty much all the same.
// See description on "CURMOD" and "QEP" to get an idea. 

// Instance a current model object
// CURMOD is typedef struct which includes values and parameters that 
// are use by the Current Module (iq, id, theta, rotor flux angle,...).
// CURMOD_DEFAULTS initializes the struct with zeros.
// See cur_mod.h in /motor_control/math_blocks
	
CURMOD cm1 = CURMOD_DEFAULTS;

// Instance a current model constant object
CURMOD_CONST cm1_const = CURMOD_CONST_DEFAULTS;

// Instance a QEP interface driver 
	// QEP is a typedef struct to be used with the QEP (Quadrature Encoder) unit.
	// (PolePairs, indexSyncFlag, ...)
	// See f2803xqep.h 
QEP qep1 = QEP_DEFAULTS; 

// Instance a Capture interface driver 
CAPTURE cap1 = CAPTURE_DEFAULTS;

// Instance a few transform objects (ICLARKE is added into SVGEN module)
CLARKE clarke1 = CLARKE_DEFAULTS;
PARK park1 = PARK_DEFAULTS;
IPARK ipark1 = IPARK_DEFAULTS;

// Instance PID regulators to regulate the d and q  axis currents, and speed
PIDREG3 pid1_id = PIDREG3_DEFAULTS;
PIDREG3 pid1_iq = PIDREG3_DEFAULTS;
PIDREG3 pid1_spd = PIDREG3_DEFAULTS;

// Instance a PWM driver instance
PWMGEN pwm1 = PWMGEN_DEFAULTS;

// Instance a PWM DAC driver instance
PWMDAC pwmdac1 = PWMDAC_DEFAULTS;

// Instance a Space Vector PWM modulator. This modulator generates a, b and c
// phases based on the d and q stationery reference frame inputs
SVGENDQ svgen_dq1 = SVGENDQ_DEFAULTS;

// Instance a ramp controller to smoothly ramp the frequency
RMPCNTL rc1 = RMPCNTL_DEFAULTS;

//	Instance a ramp(sawtooth) generator to simulate an Anglele
RAMPGEN rg1 = RAMPGEN_DEFAULTS;

// Instance a speed calculator based on QEP
SPEED_MEAS_QEP speed1 = SPEED_MEAS_QEP_DEFAULTS;

// Instance a speed calculator based on capture Qep (for eQep of 280x only)
SPEED_MEAS_CAP speed2 = SPEED_MEAS_CAP_DEFAULTS;

// Create an instance of DATALOG Module
DLOG_4CH dlog = DLOG_4CH_DEFAULTS; 
  

// main() function
//-----------------------------------------------------------------------
void main(void)
{	
	struct ECAN_REGS ECanaShadow;   
	
	DeviceInit();	// Device Life support & GPIO	
	
///////////////////// CAN-GPIO /////////////////////////////
	// DeviceInit() initializes GPIO so that CAN functionality
	// can not be used. This piece of code sets the GPIOs to
	// CAN operation.
	EALLOW;	
	/* Enable internal pull-up for the selected CAN pins */
	// Pull-ups can be enabled or disabled by the user.
	// This will enable the pullups for the specified pins.
	// Comment out other unwanted lines.
	
	GpioCtrlRegs.GPAPUD.bit.GPIO30 = 0;     // Enable pull-up for GPIO30 (CANRXA)	
	GpioCtrlRegs.GPAPUD.bit.GPIO31 = 0;     // Enable pull-up for GPIO31 (CANTXA)
	
	/* Set qualification for selected CAN pins to asynch only */
	// Inputs are synchronized to SYSCLKOUT by default.
	// This will select asynch (no qualification) for the selected pins.
	
	GpioCtrlRegs.GPAQSEL2.bit.GPIO30 = 3;   // Asynch qual for GPIO30 (CANRXA)
	
	/* Configure eCAN-A pins using GPIO regs*/
	// This specifies which of the possible GPIO pins will be eCAN functional pins.
	
	GpioCtrlRegs.GPAMUX2.bit.GPIO30 = 1;    // Configure GPIO30 for CANRXA operation	
	GpioCtrlRegs.GPAMUX2.bit.GPIO31 = 1;    // Configure GPIO31 for CANTXA operation
	
	EDIS;	
///////////////////// CAN-GPIO-END ///////////////////////////


////////////////////// CAN - eCAN init ///////////////////////
/* Create a shadow register structure for the CAN control registers. This is
 needed, since only 32-bit access is allowed to these registers. 16-bit access
 to these registers could potentially corrupt the register contents or return
 false data. */
 
    EALLOW;     // EALLOW enables access to protected bits

/* Configure eCAN RX and TX pins for CAN operation using eCAN regs*/

    ECanaShadow.CANTIOC.all = ECanaRegs.CANTIOC.all;
    ECanaShadow.CANTIOC.bit.TXFUNC = 1;
    ECanaRegs.CANTIOC.all = ECanaShadow.CANTIOC.all;

    ECanaShadow.CANRIOC.all = ECanaRegs.CANRIOC.all;
    ECanaShadow.CANRIOC.bit.RXFUNC = 1;
    ECanaRegs.CANRIOC.all = ECanaShadow.CANRIOC.all;

/* Configure eCAN for HECC mode - (reqd to access mailboxes 16 thru 31) */
                                    // HECC mode also enables time-stamping feature

    ECanaShadow.CANMC.all = ECanaRegs.CANMC.all;
    ECanaShadow.CANMC.bit.SCB = 1;
    ECanaRegs.CANMC.all = ECanaShadow.CANMC.all;

/* Initialize all bits of 'Message Control Register' to zero */
// Some bits of MSGCTRL register come up in an unknown state. For proper operation,
// all bits (including reserved bits) of MSGCTRL must be initialized to zero

    ECanaMboxes.MBOX0.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX1.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX2.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX3.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX4.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX5.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX6.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX7.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX8.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX9.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX10.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX11.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX12.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX13.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX14.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX15.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX16.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX17.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX18.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX19.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX20.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX21.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX22.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX23.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX24.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX25.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX26.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX27.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX28.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX29.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX30.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX31.MSGCTRL.all = 0x00000000;

// TAn, RMPn, GIFn bits are all zero upon reset and are cleared again
//  as a matter of precaution.
    ECanaRegs.CANTA.all = 0xFFFFFFFF;   /* Clear all TAn bits */
    ECanaRegs.CANRMP.all = 0xFFFFFFFF;  /* Clear all RMPn bits */
    ECanaRegs.CANGIF0.all = 0xFFFFFFFF; /* Clear all interrupt flag bits */
    ECanaRegs.CANGIF1.all = 0xFFFFFFFF;

/* Configure bit timing parameters for eCANA*/
    ECanaShadow.CANMC.all = ECanaRegs.CANMC.all;
    ECanaShadow.CANMC.bit.CCR = 1 ;            // Set CCR = 1
    ECanaRegs.CANMC.all = ECanaShadow.CANMC.all;

    // Wait until the CPU has been granted permission to change the configuration registers
    do
    {
    	ECanaShadow.CANES.all = ECanaRegs.CANES.all;
    } while(ECanaShadow.CANES.bit.CCE != 1 );       // Wait for CCE bit to be set..

    ECanaShadow.CANBTC.all = 0;
    /* The following block is only for 60 MHz SYSCLKOUT. (30 MHz CAN module clock Bit rate = 1 Mbps
       See Note at end of file. */

    ECanaShadow.CANBTC.bit.BRPREG = 2;
    ECanaShadow.CANBTC.bit.TSEG2REG = 1;
    ECanaShadow.CANBTC.bit.TSEG1REG = 6;

    ECanaShadow.CANBTC.bit.SAM = 1;
    ECanaRegs.CANBTC.all = ECanaShadow.CANBTC.all;

    ECanaShadow.CANMC.all = ECanaRegs.CANMC.all;
    ECanaShadow.CANMC.bit.CCR = 0 ;            // Set CCR = 0
    ECanaRegs.CANMC.all = ECanaShadow.CANMC.all;

    // Wait until the CPU no longer has permission to change the configuration registers
    do
    {
    	ECanaShadow.CANES.all = ECanaRegs.CANES.all;
    } while(ECanaShadow.CANES.bit.CCE != 0 );       // Wait for CCE bit to be  cleared..

/* Disable all Mailboxes  */
    ECanaRegs.CANME.all = 0;        // Required before writing the MSGIDs

    EDIS;    
///////////////////// CAN - eCan initEND /////////////////////
	
// Only used if running from FLASH
// Note that the variable FLASH is defined by the compiler

#ifdef FLASH
// Copy time critical code and Flash setup code to RAM
// The  RamfuncsLoadStart, RamfuncsLoadEnd, and RamfuncsRunStart
// symbols are created by the linker. Refer to the linker files. 
	MemCopy(&RamfuncsLoadStart, &RamfuncsLoadEnd, &RamfuncsRunStart);

// Call Flash Initialization to setup flash waitstates
// This function must reside in RAM
	InitFlash();	// Call the flash wrapper init function
#endif //(FLASH)

   // Waiting for enable flag set
   while (EnableFlag==FALSE) 
    { 
      BackTicker++;
    }

// Timing sync for background loops 
// Timer period definitions found in device specific PeripheralHeaderIncludes.h
	CpuTimer0Regs.PRD.all =  mSec1;		// A tasks
	CpuTimer1Regs.PRD.all =  mSec5;		// B tasks
	CpuTimer2Regs.PRD.all =  mSec50;	// C tasks

// Tasks State-machine init
	Alpha_State_Ptr = &A0;
	A_Task_Ptr = &A1;
	B_Task_Ptr = &B1;
	C_Task_Ptr = &C1;

// Initialize PWM module
    pwm1.PeriodMax = SYSTEM_FREQUENCY*1000000*T/2;  // Prescaler X1 (T1), ISR period = T x 1   
    PWM_INIT_MACRO(pwm1)

// Initialize PWMDAC module
	pwmdac1.PeriodMax = 500;   // @60Mhz, 3000->10kHz, 1500->20kHz, 1000-> 30kHz, 500->60kHz
    pwmdac1.PwmDacInPointer0 = &PwmDacCh1;
    pwmdac1.PwmDacInPointer1 = &PwmDacCh2;
    pwmdac1.PwmDacInPointer2 = &PwmDacCh3;
    pwmdac1.PwmDacInPointer3 = &PwmDacCh4;
	PWMDAC_INIT_MACRO(pwmdac1)	// f2803xpwmdac.h

// Initialize DATALOG module
    dlog.iptr1 = &DlogCh1;
    dlog.iptr2 = &DlogCh2;
    dlog.iptr3 = &DlogCh3;
    dlog.iptr4 = &DlogCh4;
    dlog.trig_value = 0x1;
    dlog.size = 0x0C8;
    dlog.prescalar = 5;
    dlog.init(&dlog);

// Initialize ADC module
	ADC_MACRO_INIT()

// Initialize QEP module
    qep1.LineEncoder = 2048;
    qep1.MechScaler = _IQ30(0.25/qep1.LineEncoder);
    qep1.PolePairs = POLES/2;
    qep1.CalibratedAngle = 0;
	QEP_INIT_MACRO(qep1)

// Initialize CAP module
	CAP_INIT_MACRO(cap1)

// Initialize the Speed module for QEP based speed calculation
    speed1.K1 = _IQ21(1/(BASE_FREQ*T));
    speed1.K2 = _IQ(1/(1+T*2*PI*5));  // Low-pass cut-off frequency
    speed1.K3 = _IQ(1)-speed1.K2;
    speed1.BaseRpm = 120*(BASE_FREQ/POLES);

// Initialize the Speed module for capture eQEP based speed calculation (low speed range)
    speed2.InputSelect = 1;
 	speed2.BaseRpm 	   = 120*(BASE_FREQ/POLES);
	speed2.SpeedScaler = 60*(SYSTEM_FREQUENCY*1000000/(1*2048*speed2.BaseRpm));
	   	
// Initialize the RAMPGEN module
    rg1.StepAngleMax = _IQ(BASE_FREQ*T);
    
// Initialize the CUR_MOD constant module     
	cm1_const.Rr = RR;
	cm1_const.Lr = LR;
	cm1_const.fb = BASE_FREQ;
	cm1_const.Ts = T;
	CUR_CONST_MACRO(cm1_const)

// Initialize the CUR_MOD module
 	cm1.Kr = _IQ(cm1_const.Kr);
 	cm1.Kt = _IQ(cm1_const.Kt);
 	cm1.K  = _IQ(cm1_const.K);

// Initialize the PID_REG3 module for Id
	pid1_id.Kp = _IQ(1.0);  
	pid1_id.Ki = _IQ(T/0.004);	
	pid1_id.Kd = _IQ(0/T); 						
	pid1_id.Kc = _IQ(0.2);
    pid1_id.OutMax = _IQ(0.3);
    pid1_id.OutMin = _IQ(-0.3);
            
// Initialize the PID_REG3 module for Iq
	pid1_iq.Kp = _IQ(1.0);
	pid1_iq.Ki = _IQ(T/0.004);			
	pid1_iq.Kd = _IQ(0/T); 				
	pid1_iq.Kc = _IQ(0.2);
    pid1_iq.OutMax = _IQ(0.8);
    pid1_iq.OutMin = _IQ(-0.8);    

// Initialize the PID_REG3 module for speed
    pid1_spd.Kp = _IQ(1.0);                  
	pid1_spd.Ki = _IQ(T*SpeedLoopPrescaler/0.5);			
	pid1_spd.Kd = _IQ(0/(T*SpeedLoopPrescaler));					
 	pid1_spd.Kc = _IQ(0.2);
    pid1_spd.OutMax = _IQ(0.95);
    pid1_spd.OutMin = _IQ(-0.95);  
    
///////////// CAN - Configure Mailboxes and specify Msg. /////////
// Mailboxs can be written to 16-bits or 32-bits at a time
// Write to the MSGID field of TRANSMIT mailboxes MBOX0 - 15
    ECanaMboxes.MBOX0.MSGID.all = 0x9555AAA0;
    ECanaMboxes.MBOX1.MSGID.all = 0x9555AAA1;
    ECanaMboxes.MBOX2.MSGID.all = 0x9555AAA2;
    ECanaMboxes.MBOX3.MSGID.all = 0x9555AAA3;
    ECanaMboxes.MBOX4.MSGID.all = 0x9555AAA4;
    ECanaMboxes.MBOX5.MSGID.all = 0x9555AAA5;
    ECanaMboxes.MBOX6.MSGID.all = 0x9555AAA6;
    ECanaMboxes.MBOX7.MSGID.all = 0x9555AAA7;
    
    // Write to the MSGID field of RECEIVE mailboxes MBOX16 - 31
    ECanaMboxes.MBOX16.MSGID.all = 0x9555AAA0;
    ECanaMboxes.MBOX17.MSGID.all = 0x9555AAA1;
    ECanaMboxes.MBOX18.MSGID.all = 0x9555AAA2;
    ECanaMboxes.MBOX19.MSGID.all = 0x9555AAA3;
    ECanaMboxes.MBOX20.MSGID.all = 0x9555AAA4;
    ECanaMboxes.MBOX21.MSGID.all = 0x9555AAA5;
    ECanaMboxes.MBOX22.MSGID.all = 0x9555AAA6;
    ECanaMboxes.MBOX23.MSGID.all = 0x9555AAA7;
    ECanaMboxes.MBOX24.MSGID.all = 0x9555AAA8;
    ECanaMboxes.MBOX25.MSGID.all = 0x9555AAA9;
    ECanaMboxes.MBOX26.MSGID.all = 0x9555AAAA;
    ECanaMboxes.MBOX27.MSGID.all = 0x9555AAAB;
    ECanaMboxes.MBOX28.MSGID.all = 0x9555AAAC;
    ECanaMboxes.MBOX29.MSGID.all = 0x9555AAAD;
    ECanaMboxes.MBOX30.MSGID.all = 0x9555AAAE;
    ECanaMboxes.MBOX31.MSGID.all = 0x9555AAAF;

    // Configure Mailboxes 0-15 as Tx, 16-31 as Rx
    // Since this write is to the entire register (instead of a bit
    // field) a shadow register is not required.
    ECanaRegs.CANMD.all = 0xFFFF0000;

    // Enable all Mailboxes */
    // Since this write is to the entire register (instead of a bit
    // field) a shadow register is not required.
    ECanaRegs.CANME.all = 0xFFFFFFFF;

    // Specify that 8 bits will be sent/received
    ECanaMboxes.MBOX0.MSGCTRL.bit.DLC = 8;
    ECanaMboxes.MBOX1.MSGCTRL.bit.DLC = 8;
    ECanaMboxes.MBOX2.MSGCTRL.bit.DLC = 8;
    ECanaMboxes.MBOX3.MSGCTRL.bit.DLC = 8;
    ECanaMboxes.MBOX4.MSGCTRL.bit.DLC = 8;
    ECanaMboxes.MBOX5.MSGCTRL.bit.DLC = 8;
    ECanaMboxes.MBOX6.MSGCTRL.bit.DLC = 8;
    ECanaMboxes.MBOX7.MSGCTRL.bit.DLC = 8;
        
    //Write 0 to set initial Speed Setpoint to 0
    ECanaMboxes.MBOX0.MDH.all = 0;
    
///////////////// CAN - Configure Mailboxes END //////////////////

//Call HVDMC Protection function
	HVDMC_Protection();	

// Reassign ISRs. 
//------------------------------------
	EALLOW;	// This is needed to write to EALLOW protected registers
	PieVectTable.EPWM1_INT = &MainISR;
	EDIS;

// Enable PIE group 3 interrupt 1 for EPWM1_INT
    PieCtrlRegs.PIEIER3.bit.INTx1 = 1;

// Enable CNT_zero interrupt using EPWM1 Time-base
    EPwm1Regs.ETSEL.bit.INTEN = 1;   // Enable EPWM1INT generation 
    EPwm1Regs.ETSEL.bit.INTSEL = 1;  // Enable interrupt CNT_zero event
    EPwm1Regs.ETPS.bit.INTPRD = 1;   // Generate interrupt on the 1st event
	EPwm1Regs.ETCLR.bit.INT = 1;     // Enable more interrupts

// Enable CPU INT3 for EPWM1_INT:
	IER |= M_INT3;
// Enable global Interrupts and higher priority real-time debug events:
	EINT;   // Enable Global interrupt INTM
	ERTM;	// Enable Global realtime interrupt DBGM

// IDLE loop. Just sit and loop forever:
//------------------------------------	
	for(;;)  //infinite loop
	{
		// State machine entry & exit point
		//===========================================================
		(*Alpha_State_Ptr)();	// jump to an Alpha state (A0,B0,...)
		//===========================================================

	}
} //END MAIN CODE



//=================================================================================
//	STATE-MACHINE SEQUENCING AND SYNCRONIZATION FOR SLOW BACKGROUND TASKS
//=================================================================================
//--------------------------------- FRAMEWORK -------------------------------------

// A0, B0 and C0 pass "Alpha_State_Ptr" around. Tasks A1,A2,A3,B1,B2,... are called
// from these Alpha states (A0, B0, C0)

void A0(void)
{
	// loop rate synchronizer for A-tasks
	if(CpuTimer0Regs.TCR.bit.TIF == 1)
	{
		//T//	This flag gets set when the CPU-timer decrements to zero.
			//	Writing a 1 to this bit clears the flag.
		CpuTimer0Regs.TCR.bit.TIF = 1;	// clear flag
		//-----------------------------------------------------------
		(*A_Task_Ptr)();		// jump to an A Task (A1,A2,A3,...)
		//-----------------------------------------------------------
		VTimer0[0]++;			// virtual timer 0, instance 0 (spare)
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
		VTimer1[0]++;			// virtual timer 1, instance 0 (spare)
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
		VTimer2[0]++;			//virtual timer 2, instance 0 (spare)
	}
	Alpha_State_Ptr = &A0;	// Back to State A0	
}

//=================================================================================
//	A - TASKS (executed in every 1 msec)
//=================================================================================
//--------------------------------------------------------
void A1(void) // SPARE (not used)
//--------------------------------------------------------
{
	if(EPwm1Regs.TZFLG.bit.OST==0x1)
	   TripFlagDMC=1;      // Trip on DMC (halt, and IPM fault trip )
	//-------------------
	//the next time CpuTimer0 'counter' reaches Period value go to A2
	A_Task_Ptr = &A2;
	//-------------------
}

//-----------------------------------------------------------------
void A2(void) // SPARE (not used)
//-----------------------------------------------------------------
{	
	//-------------------
	//the next time CpuTimer0 'counter' reaches Period value go to A3
	A_Task_Ptr = &A3;
	//-------------------	
}

//-----------------------------------------
void A3(void) // SPARE (not used)
//-----------------------------------------
{
	//-----------------
	//the next time CpuTimer0 'counter' reaches Period value go to A1
	A_Task_Ptr = &A1;
	//-----------------
}

//=================================================================================
//	B - TASKS (executed in every 5 msec)
//=================================================================================
//----------------------------------- USER ----------------------------------------
void B1(void) // Toggle GPIO-00
//----------------------------------------
{
	//-----------------
	//the next time CpuTimer1 'counter' reaches Period value go to B2
	B_Task_Ptr = &B2;	
	//-----------------
}

//----------------------------------------
void B2(void) //  SPARE
//----------------------------------------
{
	//-----------------
	//the next time CpuTimer1 'counter' reaches Period value go to B3
	B_Task_Ptr = &B3;
	//-----------------
}

//----------------------------------------
void B3(void) //  SPARE
//----------------------------------------
{
	//-----------------
	//the next time CpuTimer1 'counter' reaches Period value go to B1
	B_Task_Ptr = &B1;	
	//-----------------
}

//=================================================================================
//	C - TASKS (executed in every 50 msec)
//=================================================================================
//--------------------------------- USER ------------------------------------------

//----------------------------------------
void C1(void) 	// Toggle GPIO-34 
//----------------------------------------
{	
	gpioToggle++;
	if(gpioToggle==5)
	{
		GpioDataRegs.GPBTOGGLE.bit.GPIO34 = 1;	//turn on/off LD3 on the controlCARD
		gpioToggle=0;
	}
	
////////////////////// CAN - Program ///////////////////////
// Write to the mailbox RAM field of MBOX0 - 15
// Message Payload (8 Bytes)              
    ECanaMboxes.MBOX0.MDL.all = speed1.Speed;
    ECanaMboxes.MBOX0.MDH.all = SpeedRef;

	LifeSign++;
    ECanaMboxes.MBOX1.MDL.all = LifeSign;
    ECanaMboxes.MBOX1.MDH.all = 0x01AB45DE;

    ECanaMboxes.MBOX2.MDL.all = pid1_id.Kp;
    ECanaMboxes.MBOX2.MDH.all = pid1_id.Ki;

    ECanaMboxes.MBOX3.MDL.all = pid1_id.Kd;
    ECanaMboxes.MBOX3.MDH.all = pid1_id.Kc;

    ECanaMboxes.MBOX4.MDL.all = pid1_iq.Kp;
    ECanaMboxes.MBOX4.MDH.all = pid1_iq.Ki;

    ECanaMboxes.MBOX5.MDL.all = pid1_iq.Kd;
    ECanaMboxes.MBOX5.MDH.all = pid1_iq.Kc;

    ECanaMboxes.MBOX6.MDL.all = pid1_spd.Kp;
    ECanaMboxes.MBOX6.MDH.all = pid1_spd.Ki;

    ECanaMboxes.MBOX7.MDL.all = pid1_spd.Kd;
    ECanaMboxes.MBOX7.MDH.all = pid1_spd.Kc;

	// CAN - Send
	// Msgs. are specified in main()
	ECanaRegs.CANTRS.all = 0x000000FF;  // Set TRS(Transmission-Request) for all transmit mailboxes
    while(ECanaRegs.CANTA.all != 0x000000FF ) {}  // Wait for all TAn bits to be set..
    ECanaRegs.CANTA.all = 0x000000FF;   // Clear all TAn (The CPU resets the bits in CANTA by writing a 1)
  
	// CAN - Receive 										
    					//Read from Receive mailboxes
    mailbox_read(MNr);  // This func reads the indicated mailbox data
    
	// Interface CAN <--> FOC 
    SpeedRef = receiveCAN[MNr-1].receiveMDL;    
////////////////////// CAN - Program END ///////////////////		
	
	//-----------------
	//the next time CpuTimer2 'counter' reaches Period value go to C2
	C_Task_Ptr = &C2;	
	//-----------------
}

//----------------------------------------
void C2(void) //  SPARE
//----------------------------------------
{
		//-----------------
	//the next time CpuTimer2 'counter' reaches Period value go to C3
	C_Task_Ptr = &C3;	
	//-----------------
}

//-----------------------------------------
void C3(void) //  SPARE
//-----------------------------------------
{
	//-----------------
	//the next time CpuTimer2 'counter' reaches Period value go to C1
	C_Task_Ptr = &C1;	
	//-----------------
}

//=================================================================================
//	CAN Functions
//=================================================================================

// This function reads out the contents of the indicated
// by the Mailbox number (MBXnbr).
void mailbox_read(int16 MBXnbr)
{

   volatile struct MBOX *Mailbox;
   Mailbox = &ECanaMboxes.MBOX0 + MBXnbr;
   receiveCAN[MBXnbr-1].receiveMDL = Mailbox->MDL.all; // = 0x9555AAAn (n is the MBX number)
   receiveCAN[MBXnbr-1].receiveMDH = Mailbox->MDH.all; // = 0x89ABCDEF (a constant)
   receiveCAN[MBXnbr-1].receiveMSGID = Mailbox->MSGID.all;// = 0x9555AAAn (n is the MBX number)

} // MSGID of a rcv MBX is transmitted as the MDL data.

//=================================================================================
//	MAIN FIELD ORIENTED CONTROL ISR
//=================================================================================
 
//MainISR 
interrupt void MainISR(void)
{

// Verifying the ISR
    IsrTicker++;
// =============================== LEVEL 5 ======================================
//	Level 5 verifies verifies the speed regulator performed by PID_REG3 module.
//	The system speed loop is closed by using the measured speed from capture 
//	signal as a feedback.
// ==============================================================================  

#if (BUILDLEVEL==LEVEL5)

// ------------------------------------------------------------------------------
//  Connect inputs of the RMP module and call the ramp control macro
// ------------------------------------------------------------------------------
    rc1.TargetValue = SpeedRef;		
	RC_MACRO(rc1) 	// see rmp_cntl.h

// ------------------------------------------------------------------------------
//  Connect inputs of the RAMP GEN module and call the ramp generator macro
// ------------------------------------------------------------------------------
    rg1.Freq = rc1.SetpointValue;
	RG_MACRO(rg1)	//RAMP(Sawtooh) Generator Macro Definition to be found in rampgen.h

// ------------------------------------------------------------------------------
//  Measure phase currents, subtract the offset and normalize from (-0.5,+0.5) to (-1,+1). 
//	Connect inputs of the CLARKE module and call the clarke transformation macro
// ------------------------------------------------------------------------------
	clarke1.As=_IQ15toIQ((AdcResult.ADCRESULT1<<3)-_IQ15(0.4970))<<1; // Phase A curr.
	clarke1.Bs=_IQ15toIQ((AdcResult.ADCRESULT2<<3)-_IQ15(0.4995))<<1; // Phase B curr.	
	CLARKE_MACRO(clarke1) 

// ------------------------------------------------------------------------------
//  Connect inputs of the PARK module and call the park trans. macro
// ------------------------------------------------------------------------------
	park1.Alpha = clarke1.Alpha;
	park1.Beta  = clarke1.Beta;
	park1.Angle = cm1.Theta;
	park1.Sine  = _IQsinPU(park1.Angle);
	park1.Cosine= _IQcosPU(park1.Angle);
	PARK_MACRO(park1) 

// ------------------------------------------------------------------------------
//  Connect inputs of the PID_REG3 module and call the PID IQ controller macro
// ------------------------------------------------------------------------------  
    if (SpeedLoopCount==SpeedLoopPrescaler)
     {
      pid1_spd.Ref = rc1.SetpointValue;
      pid1_spd.Fdb = speed1.Speed;
	  PID_MACRO(pid1_spd);
      SpeedLoopCount=1;
     }
    else SpeedLoopCount++; 
 
// ------------------------------------------------------------------------------
//  Connect inputs of the PID_REG3 module and call the PID IQ controller macro
// ------------------------------------------------------------------------------  
    pid1_iq.Ref = pid1_spd.Out;
	pid1_iq.Fdb = park1.Qs;
	PID_MACRO(pid1_iq)

// ------------------------------------------------------------------------------
//  Connect inputs of the PID_REG3 module and call the PID ID controller macro
// ------------------------------------------------------------------------------  
    pid1_id.Ref = IdRef;
	pid1_id.Fdb = park1.Ds;
	PID_MACRO(pid1_id)

// ------------------------------------------------------------------------------
//	Connect inputs of the INV_PARK module and call the inverse park trans. macro
// ------------------------------------------------------------------------------
    ipark1.Ds = pid1_id.Out;
    ipark1.Qs = pid1_iq.Out ;
	ipark1.Sine   = park1.Sine;
    ipark1.Cosine = park1.Cosine;
	IPARK_MACRO(ipark1) 

// ------------------------------------------------------------------------------
//  Call the QEP macro (if incremental encoder used for speed sensing)
//  Connect inputs of the SPEED_FR module and call the speed calculation macro
// ------------------------------------------------------------------------------ 
    QEP_MACRO(qep1)

    speed1.ElecTheta = _IQ24toIQ((int32)qep1.ElecTheta);
    speed1.DirectionQep = (int32)(qep1.DirectionQep);
    SPEED_FR_MACRO(speed1)

/* ------------------------------------------------------------------------------
//  Call the CAP macro (if sprocket or spur gear used for speed sensing)
//  Connect inputs of the SPEED_PR module and call the speed calculation macro
// ------------------------------------------------------------------------------ 
	CAP_MACRO(cap1) 

    if(cap1.CapReturn ==0)             				     // Check the capture return
    {
        speed2.EventPeriod=(int32)(cap1.EventPeriod);    // Read out new event period
        SPEED_PR_MACRO(speed2)                 			 // Call the speed macro      
    } 
*/
// ------------------------------------------------------------------------------
//    Connect inputs of the CUR_MOD module and call the current model
//    calculation function.
// ------------------------------------------------------------------------------
    cm1.IDs = park1.Ds;
    cm1.IQs = park1.Qs;
	cm1.Wr = speed1.Speed;
	CUR_MOD_MACRO(cm1)

// ------------------------------------------------------------------------------
//  Connect inputs of the SVGEN_DQ module and call the space-vector gen. macro
// ------------------------------------------------------------------------------
  	svgen_dq1.Ualpha = ipark1.Alpha;
 	svgen_dq1.Ubeta = ipark1.Beta;
  	SVGEN_MACRO(svgen_dq1)        

// ------------------------------------------------------------------------------
//  Connect inputs of the PWM_DRV module and call the PWM signal generation macro
// ------------------------------------------------------------------------------
    pwm1.MfuncC1 = (int16)_IQtoIQ15(svgen_dq1.Ta); // MfuncC1 is in Q15
    pwm1.MfuncC2 = (int16)_IQtoIQ15(svgen_dq1.Tb); // MfuncC2 is in Q15  
    pwm1.MfuncC3 = (int16)_IQtoIQ15(svgen_dq1.Tc); // MfuncC3 is in Q15
	PWM_MACRO(pwm1)							   	   // Calculate the new PWM compare values	

	EPwm1Regs.CMPA.half.CMPA=pwm1.PWM1out;	// PWM 1A - PhaseA 
	EPwm2Regs.CMPA.half.CMPA=pwm1.PWM2out;	// PWM 2A - PhaseB
	EPwm3Regs.CMPA.half.CMPA=pwm1.PWM3out;	// PWM 3A - PhaseC  

// ------------------------------------------------------------------------------
//    Connect inputs of the PWMDAC module 
// ------------------------------------------------------------------------------	
    PwmDacCh1 = (int16)_IQtoIQ15(svgen_dq1.Ta);
    PwmDacCh2 = (int16)_IQtoIQ15(clarke1.As); 
    PwmDacCh3 = (int16)_IQtoIQ15(rg1.Out);
    PwmDacCh4 = (int16)_IQtoIQ15(cm1.Theta);    

// ------------------------------------------------------------------------------
//    Connect inputs of the DATALOG module 
// ------------------------------------------------------------------------------
    DlogCh1 = (int16)_IQtoIQ15(clarke1.As);
    DlogCh2 = (int16)_IQtoIQ15(clarke1.Bs);
    //DlogCh3 = (int16)_IQtoIQ15(svgen_dq1.Ta);
    //DlogCh4 = (int16)_IQtoIQ15(cm1.Theta);

	DlogCh3 = (int16)_IQtoIQ15(SpeedRef);
    DlogCh4 = (int16)_IQtoIQ15(speed1.Speed);
   

#endif // (BUILDLEVEL==LEVEL5)

// ------------------------------------------------------------------------------
//    Call the PWMDAC update macro.
// ------------------------------------------------------------------------------
	PWMDAC_MACRO(pwmdac1)

// ------------------------------------------------------------------------------
//    Call the DATALOG update function.
// ------------------------------------------------------------------------------
    dlog.update(&dlog);


#if (DSP2803x_DEVICE_H==1)||(DSP280x_DEVICE_H==1)
// Enable more interrupts from this timer
	EPwm1Regs.ETCLR.bit.INT = 1;

// Acknowledge interrupt to recieve more interrupts from PIE group 3
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;
#endif

}// ISR Ends Here

/**********************************************************/
/***************Protection Configuration*******************/  
/**********************************************************/

void HVDMC_Protection(void)
{

// Configure Trip Mechanism for the Motor control software
// -Cycle by cycle trip on CPU halt
// -One shot IPM trip zone trip 
// These trips need to be repeated for EPWM1 ,2 & 3

//===========================================================================
//Motor Control Trip Config, EPwm1,2,3
//===========================================================================
      EALLOW;
// CPU Halt Trip  
      EPwm1Regs.TZSEL.bit.CBC6=0x1;
      EPwm2Regs.TZSEL.bit.CBC6=0x1;
      EPwm3Regs.TZSEL.bit.CBC6=0x1;
      
      
      EPwm1Regs.TZSEL.bit.OSHT1   = 1;  //enable TZ1 for OSHT  
      EPwm2Regs.TZSEL.bit.OSHT1   = 1;  //enable TZ1 for OSHT      
      EPwm3Regs.TZSEL.bit.OSHT1   = 1;  //enable TZ1 for OSHT

// What do we want the OST/CBC events to do?
// TZA events can force EPWMxA
// TZB events can force EPWMxB

      EPwm1Regs.TZCTL.bit.TZA = TZ_FORCE_LO; // EPWMxA will go low 
      EPwm1Regs.TZCTL.bit.TZB = TZ_FORCE_LO; // EPWMxB will go low
      
      EPwm2Regs.TZCTL.bit.TZA = TZ_FORCE_LO; // EPWMxA will go low 
      EPwm2Regs.TZCTL.bit.TZB = TZ_FORCE_LO; // EPWMxB will go low
      
      EPwm3Regs.TZCTL.bit.TZA = TZ_FORCE_LO; // EPWMxA will go low 
      EPwm3Regs.TZCTL.bit.TZB = TZ_FORCE_LO; // EPWMxB will go low
      
      
      EDIS;

     // Clear any spurious OV trip
      EPwm1Regs.TZCLR.bit.OST = 1;
      EPwm2Regs.TZCLR.bit.OST = 1;
      EPwm3Regs.TZCLR.bit.OST = 1;  
      
//************************** End of Prot. Conf. ***************************//
}
//===========================================================================
// No more.
//===========================================================================
