//----------------------------------------------------------------------------------
//	FILE:			{ProjectName}-CLA_Shared.h
//
//	Description:	CLA and CPU shared variables and constants 
//  
//   Revision/ Version: See {ProjectName}-Main.c
//----------------------------------------------------------------------------------
#ifndef CLA_SHARED_H
#define CLA_SHARED_H

#ifdef __cplusplus
extern "C" {
#endif

// Project includes
#include "ProjectName-Settings.h"
#include "DSP2803x_Cla_typedefs.h"
#include "DSP2803x_Cla_defines.h"

// Digital Power library header file
#include "DPlib.h"

#define CLA_DEBUG 1

#ifdef __TMS320C28XX__
#define ClaToCpu_volatile volatile
#else
#define ClaToCpu_volatile
#endif

// Declare variables shared between CLA and CPU
extern volatile float32 CLA_DUTY1;

// The following are symbols defined in the CLA_Tasks.cla file.
// Including them in the shared header file makes them visible to the CPU.

//CLA C Tasks defined in ProjectName-CLA_Tasks.cla
interrupt void Cla1Task1();
interrupt void Cla1Task2();
interrupt void Cla1Task3();
interrupt void Cla1Task4();
interrupt void Cla1Task5();
interrupt void Cla1Task6();
interrupt void Cla1Task7();
interrupt void Cla1Task8();

#ifdef __cplusplus
}
#endif /* extern "C" */


#endif  // end of CLA_SHARED definition
