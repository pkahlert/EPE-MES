//###########################################################################
//
// FILE:   f2802x_examples/LED_Boost_PC/LED_Boost_PC_Settings.h
//
// TITLE:  Settings for the LED Boosterpack PC Example
//
//###########################################################################
// $TI Release: LaunchPad f2802x Support Library v100 $
// $Release Date: Wed Jul 25 10:45:39 CDT 2012 $
//###########################################################################

#ifndef _PROJSETTINGS_H
#define _PROJSETTINGS_H

//**************************************************************
//  NOTE: WHEN CHANGING THIS FILE PLEASE REBUILD ALL
//**************************************************************

void comp(void);

//===============================================================
// Incremental Build options for System check-out
//---------------------------------------------------------------
#define INCR_BUILD 2    //1 - Open-Loop
                        //2 - Closed-Loop Current
                        //3 - 

//===============================================================
// System Settings
//---------------------------------------------------------------
#define HistorySize 8       // Number of samples averaged for use in GUI
#define DMAX        700     // High clamping value for normal operation = DMAX/1000
#define DMIN        0       // Low clamping value for normal operation = DMIN/1000
#define uSec100     6000    // 100 uS

#endif

