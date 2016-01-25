/******************************************************************************
 *
 * File:	MotorCtrl_Func.c
 * Author:	Tobias Wurm
 *
 * >> see MotorCtrl.h for descriptions and prototypes <<
 *****************************************************************************/
#include "MotorCtrl.h"

void printMainM(void)
{
	printf("\n\n****************** Machine Control ******************");
	printf("\n********************* Main Menu *********************");
	printf("\n*                                                   *");
	printf("\n*                                                   *");
	printf("\n*            1. Speed Setpoint Menu                 *");
	printf("\n*            2. Show Actual Speed                   *");
	printf("\n*            3. Show PID Parameters                 *");
	printf("\n*                                                   *");
	printf("\n*            0. Exit                                *");
	printf("\n*                                                   *");
	printf("\n*            What do you want to do?                *");
	printf("\n*            Press corresponding key                *");
	printf("\n*                                                   *");
	printf("\n*                                                   *");
	printf("\n*****************************************************\n");
	printf("                              ");
}

void printSetpointM(float actualSSetpoint)
{
	printf("\n\n****************** Machine Control ******************");
	printf("\n**************** Speed Setpoint Menu ****************");
	printf("\n*                                                   *");
	printf("\n*                                                   *");
	printf("\n*            Actual Speed Setpoint:                 *");
	printf("\n*                %f                           *",actualSSetpoint);
	printf("\n*                                                   *");
	printf("\n*            1. Change Speed Setpoint               *");
	printf("\n*            0. Exit                                *");
	printf("\n*                                                   *");
	printf("\n*            What do you want to do?                *");
	printf("\n*            Press corresponding key                *");
	printf("\n*                                                   *");
	printf("\n*****************************************************\n");
	printf("                              ");
}

void printActualSM(void)
{
	printf("\n\n****************** Machine Control ******************");
	printf("\n**************** Show Actual Speed ****************");
	printf("\n*                                                   *");
	printf("\n*                                                   *");
	printf("\n*        !!! PRESS ENTER TO STOP !!!                *");
	printf("\n*                                                   *");
	printf("\n*                                                   *");
	printf("\n*****************************************************\n");
	printf("                              \n");
}

void printPIDSetup(float Param_iq[], float Param_id[], float Param_spd[])
{
	printf("\n\n********************** Machine Control *********************");
	printf("\n*********************** PID Parameters *********************");
	printf("\n*                                                          *");
	printf("\n*   |  PID_IQ:       |  PID_ID:       |  PID_SPD:      |   *");
	printf("\n*   |                |                |                |   *");
	printf("\n*   |  KP: %f  |  KP: %f  |  KP: %f  |   *", Param_iq[0], Param_id[0], Param_spd[0]);
	printf("\n*   |  KI: %f  |  KI: %f  |  KI: %f  |   *", Param_iq[1], Param_id[1], Param_spd[1]);
	printf("\n*   |  KD: %f  |  KD: %f  |  KD: %f  |   *", Param_iq[2], Param_id[2], Param_spd[2]);
	printf("\n*   |  KC: %f  |  KC: %f  |  KC: %f  |   *", Param_iq[3], Param_id[3], Param_spd[3]);
	printf("\n*                                                          *");
	printf("\n*   0. Exit                                                *");
	printf("\n************************************************************\n");
	printf("                              \n");
}

void printEnterSP(void)
{
	printf("\n\n****************** Machine Control ******************");
	printf("\n**************** Speed Setpoint Menu ****************");
	printf("\n*                                                   *");
	printf("\n*        Enter new Speed Setpoint                   *");
	printf("\n*        (e.g.  1.31546)                            *");
	printf("\n*                                                   *");
	printf("\n*****************************************************\n");
	printf("                              \n");
}

int getcheckOptions(void)
{
	char inputString[22];
	int optInput=-1, ret=0;

	//fgets() adds \n to the string
	fgets(inputString, 20, stdin);

	if(strlen(inputString)>2)
	{
		return -1;
	}
	ret = sscanf(inputString, "%d", &optInput);

	if(ret==EOF)	// No Input (just "Enter")
	{
		return -1;
	}

	if(ret==0)	//Invalid character
	{
		return -1;
	}

	return optInput;	//Vaild Input
}

int getFloat(float* floatInput)
{
	char inputFloatString[50];
	float setpointInput = 0, ret = 0;

	//fgets() adds \n to the string
	fgets(inputFloatString, 48, stdin);

	ret = sscanf(inputFloatString, "%f", &setpointInput);

	if(ret==EOF)	// No Input (just "Enter")
	{
		//printf("\nEOF");
		return -1;
	}

	if(ret==0)	//Invalid character
	{
		//printf("\nInvalid character");
		return -1;
	}

	//printf("Eingelesener Float Wert: %f", setpointInput);
	*floatInput = setpointInput;
	return 0;
}

void skaleIq2Byte(float iq, int* Byte)
{
	*Byte=(iq*16777216);
}

void skaleByte2Iq(float *iq, int Byte)
{
	*iq = (((float)Byte)/16777216);
}

void setSpeedZero(struct can_frame Send)
{
	memset(&Send, 0, sizeof(Send)); // init CAN frames

	//Set Bit for extended Identifier
	Send.can_id=(0x80000000|CAN_ID_SEND_SPEED_SETPOINT);
	Send.can_dlc=4;

	Send.data[0]=0;
	Send.data[1]=0;
	Send.data[2]=0;
	Send.data[3]=0;

	if(canSend(Send)!=0)
	{
		printf("\n!!! canSend() ERROR !!!\n");
		printMainM();
		fflush(stdout);
	}
}

int canReceiveInt(int can_id, int *mdl, int* mdh )
{
	struct can_frame Receive;
	int idMatch = 0;

	if(canReceive(&Receive, can_id, &idMatch)==0)
	{
		if(idMatch==1)
		{
			//0...3
			*mdl = (Receive.data[0]<<24);
			*mdl|=(Receive.data[1]<<16);
			*mdl|=(Receive.data[2]<<8);
			*mdl|=(Receive.data[3]);
			//4...7
			*mdh = (Receive.data[4]<<24);
			*mdh|=(Receive.data[5]<<16);
			*mdh|=(Receive.data[6]<<8);
			*mdh|=(Receive.data[7]);

		}
		else
		{
			printf("No CAN MSGs with Actual Speed Setpoint received\n");
			return -1;
		}
		return 0;
	}
	else
	{
		printf("Error in canReceive()\n");
		return -1;
	}

}

int stopKeyCheck(void)
{
	struct timeval tv;
	fd_set fds;
	tv.tv_sec = 0;
	tv.tv_usec = 0;

	FD_ZERO(&fds);
	FD_SET(STDIN_FILENO, &fds);

	select(STDIN_FILENO+1, &fds, NULL, NULL, &tv);
	return FD_ISSET(STDIN_FILENO, &fds);

}


