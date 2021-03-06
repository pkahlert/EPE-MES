//###########################################################################
// Description:
//
// Generate a test input vector for the lookup algorithm
//
//###########################################################################
// $TI Release: F2803x C/C++ Header Files and Peripheral Examples V130 $
// $Release Date: May  8, 2015 $
// $Copyright: Copyright (C) 2009-2015 Texas Instruments Incorporated -
//             http://www.ti.com/ ALL RIGHTS RESERVED $
//###########################################################################

#include "DSP28x_Project.h"
#include "DSP2803x_Cla_defines.h"  
// Include the test header file whose name is based on the test name
// which is defined by the macro TEST on the command line
#include XSTRINGIZE(XCONCAT(TEST_NAME,_shared.h))

void test_run(void)
{	int i;
	
	for(i=0;i<BUFFER_SIZE;i++)
	{
	 fVal= (float)(BUFFER_SIZE - i)/(float)BUFFER_SIZE;
	 Cla1ForceTask1andWait();
	 y[i] = fResult; 
	}
    
#if 0
    Cla1ForceTask2andWait();

    Cla1ForceTask3andWait();

    Cla1ForceTask4andWait();

    Cla1ForceTask5andWait();

    Cla1ForceTask6andWait();

    Cla1ForceTask7andWait();

    Cla1ForceTask8andWait();
#endif
}

