;;###########################################################################
;;
;; FILE:   f2802x_examples/LED_Boost_CapTouch/LED_Boost_CapTouch_ISR.asm
;;
;; TITLE:  Interrupt service routines for LED BoosterPack
;;
;;###########################################################################
;; $TI Release: LaunchPad f2802x Support Library v100 $
;; $Release Date: Wed Jul 25 10:45:39 CDT 2012 $
;;###########################################################################

        ;Gives peripheral addresses visibility in assembly
        .cdecls   C,LIST,"DSP28x_Project.h"

        ;Include C header file - sets INCR_BUILD (used in conditional builds)
        .cdecls C,NOLIST, "LED_Boost_CapTouch_Settings.h"

        ;Include files for the Power Library Maco's being used by the system
        .include "ADCDRV_1ch.asm"
        .include "CNTL_2P2Z.asm"
        .include "PWMDRV_DualUpDwnCnt.asm"
        .include "PWMDRV_1ch_UpDwnCnt.asm"
        
        .global _comp

;**********************************************************************************
; Declare Public functions for External Reference
;**********************************************************************************
        ; label to DP initialisation function
        .def _DPL_Init    

;**********************************************************************************
; Variable declaration
;**********************************************************************************    
; All Terminal modules initially point to the ZeroNet to ensure a known
; start state. Pad extra locations to accomodate unwanted ADC results.
        ; dummy variable for pointer initialisation
ZeroNet    .usect "ZeroNet_Section",2,1,1    ; output terminal 1

                .text
;---------------------------------------------------------
; ISR Initialisation
;---------------------------------------------------------
_DPL_Init:

; Clear the ZeroNet
    MOVL     XAR2,#ZeroNet
    RPT        #7 ; 8 times
    ||MOV    *XAR2++, #0

    ;---------------------------------------------------------
    .if(INCR_BUILD = 1) ; Open-Loop
        ADCDRV_1ch_INIT 1
        ADCDRV_1ch_INIT 2
        PWMDRV_DualUpDwnCnt_INIT 1    ; EPWM1AB
        ADCDRV_1ch_INIT 3
        PWMDRV_1ch_UpDwnCnt_INIT 2    ; EPWM2A
        ADCDRV_1ch_INIT 9
        ADCDRV_1ch_INIT 10
        ADCDRV_1ch_INIT 11
        ADCDRV_1ch_INIT 12
    .endif
    ;---------------------------------------------------------
    .if(INCR_BUILD = 2) ; Closed-Loop 2P2Z
        ; Initialize the time slicer

        ADCDRV_1ch_INIT 1
        CNTL_2P2Z_INIT 1
        ADCDRV_1ch_INIT 2
        CNTL_2P2Z_INIT 2
        PWMDRV_DualUpDwnCnt_INIT 1    ; EPWM1AB

        ADCDRV_1ch_INIT 3
        CNTL_2P2Z_INIT 3
        PWMDRV_1ch_UpDwnCnt_INIT 2    ; EPWM2A

        ADCDRV_1ch_INIT 9
        ADCDRV_1ch_INIT 10
        ADCDRV_1ch_INIT 11
        ADCDRV_1ch_INIT 12
    .endif
    ;---------------------------------------------------------
    .if(INCR_BUILD = 3) ; Closed-Loop PID
    .endif
    ;---------------------------------------------------------

    LRETR

        .sect "ramfuncs"
        ; label to DP ISR Run function
        .def    _DPL_ISR

;---------------------------------------------------------
; ISR Run
;---------------------------------------------------------
_DPL_ISR:    ;(13 cycles to get to here from ISR trigger)
    ;CONTEXT_SAVE
    PUSH AR1H:AR0H ; 32-bit
    PUSH XAR2 ; 32-bit
    PUSH XAR3 ; 32-bit
    PUSH XAR4 ; 32-bit
;-- Comment these to save cycles --------
    PUSH XAR5 ; 32-bit
    PUSH XAR6 ; 32-bit
    PUSH XAR7 ; 32-bit
;----------------------------------------
    PUSH XT      ; 32-bit
;    SPM       0                          ; set C28 mode
;    CLRC      AMODE       
;    CLRC      PAGE0,OVM 
    NOP        

    ;---------------------------------------------------------
    .if(INCR_BUILD = 1) ; Open-Loop
        ADCDRV_1ch 1
        ADCDRV_1ch 2
        PWMDRV_DualUpDwnCnt 1

        ADCDRV_1ch 3
        PWMDRV_1ch_UpDwnCnt 2

    .endif
    ;---------------------------------------------------------
    .if(INCR_BUILD = 2) ; Closed-Loop 2P2Z

        ADCDRV_1ch 1
        ADCDRV_1ch 2
        ADCDRV_1ch 3
        
        LCR #_comp
        
        CNTL_2P2Z 1
        CNTL_2P2Z 2
        PWMDRV_DualUpDwnCnt 1

        CNTL_2P2Z 3
        PWMDRV_1ch_UpDwnCnt 2

        ADCDRV_1ch 9
        ADCDRV_1ch 10
        ADCDRV_1ch 11
        ADCDRV_1ch 12
    .endif
    ;---------------------------------------------------------
    .if(INCR_BUILD = 3) ; Closed-Loop PID
    .endif
    ;---------------------------------------------------------

;===================================
EXIT_ISR
;===================================
; Interrupt management before exit
    MOVW     DP,#_EPwm1Regs.ETCLR
    MOV     @_EPwm1Regs.ETCLR,#0x01            ; Clear EPWM1 Int flag
    MOVW     DP,#_PieCtrlRegs.PIEACK            
    MOV     @_PieCtrlRegs.PIEACK, #0x4        ; Acknowledge PIE interrupt Group 3

; Restore context & return
    POP XT
;-- Comment these to save cycles ---
    POP XAR7
    POP XAR6
    POP XAR5
;-----------------------------------
    POP XAR4
    POP XAR3
    POP XAR2
    POP AR1H:AR0H

    IRET

