/******************************************************************************
 *
 * File:	MotorCtrl.h
 * Author:	Tobias Wurm
 *
 *****************************************************************************/

#ifndef MOTORCTRL_H_
#define MOTORCTRL_H_

#include <termios.h>
#include <sys/select.h>
#include <unistd.h>

#include <stdio.h>
#include <errno.h>

#include <string.h>
#include <stdlib.h>

#include <linux/can.h>
#include <linux/can/raw.h>

#define CAN_ID_REC_ACTSPEED_ACTSSETPOINT 0x1555AAA0
#define CAN_ID_REC_LIFE_SIGN 0x1555AAA1
#define CAN_ID_REC_PID_ID1 0x1555AAA2
#define CAN_ID_REC_PID_ID2 0x1555AAA3
#define CAN_ID_REC_PID_IQ1 0x1555AAA4
#define CAN_ID_REC_PID_IQ2 0x1555AAA5
#define CAN_ID_REC_PID_SPD1 0x1555AAA6
#define CAN_ID_REC_PID_SPD2 0x1555AAA7

#define CAN_ID_SEND_SPEED_SETPOINT 0x1555AAA0

#define CAN_FILTER_DISABLE 0x00000000

// Prototypes //
void printMainM(void);
void printSetpointM(float);
void printActualSM(void);
void printEnterSP(void);
void printPIDSetup(float*, float*, float*);


/******************************************************************************
 *
 * int canSend(struct can_frame FRAME);
 *
 * canSend() opens a CAN Socket, sets it up according to CAN communication
 * specification, sends date in FRAME and closes socket.
 *
 * RETURN:
 *		error in socket functions	->  1
 * 		no error					->  0
 *****************************************************************************/
int canSend(struct can_frame);

/******************************************************************************
 *
 * int getcheckOptions(void);
 *
 * getcheckOptions() reads input from stdin and checks it on validity.
 *
 * RETURN:
 *		Input valid 	->  Input Value (0,1,2,3,4,5,6,7,8,9)
 * 		input invalid  	->  -1 (e.g. no input or invalid characters)
 *****************************************************************************/
int getcheckOptions();

/******************************************************************************
 *
 * int getFloat(float* FLOATINPUT);
 *
 * getFloat() reads input from stdin, checks it on validity and
 * returns it in FLOATINPUT.
 *
 * RETURN:
 *		Input valid 	->  0
 * 		input invalid  	->  -1 (e.g. no input or invalid characters)
 *****************************************************************************/
int getFloat(float*);

/******************************************************************************
 *
 * int stopKeyCheck(void)
 *
 * stopKeyCheck() detects a newline (Enter) on stdin.
 *
 * RETURN:
 *		newline on stdin	->  1
 * 		no newline			->  0
 *****************************************************************************/
int stopKeyCheck(void);

/******************************************************************************
 *
 * int openReceiveSocket(void)
 *
 * openReceiveSocket() opens a Receive Socket.
 *
 * RETURN:
 *		error in Socket functions	->  1
 * 		no error					->  0
 *****************************************************************************/
int openReceiveSocket(void);

/******************************************************************************
 *
 * void closeReceiveSocket(void)
 *
 * closeReceiveSocket() closes a Receive Socket.
 *
 *****************************************************************************/
void closeReceiveSocket(void);

/*****************************************************************************
 *
 *	int canReceive(struct can_frame* FRAME, int FILTER, int* IDMATCH)
 *
 *	canReceive reads CAN socket and returns the frames which Identifiers
 *	match the given FILTER. IDMATCH is set to 1 in case of a match. canReceive
 *	exits after 32 not matching frames and writes IDMATCH to 0.
 *	A matching frame is returned in FRAME.
 *
 *	Set FILTER to CAN_FILTER_DISABLE (0x00000000) to disable filter functionality.
 *
 *	RETURNVALUE:
 *			1 error
 *			0 no error
 *
 *****************************************************************************/
int canReceive(struct can_frame*, int, int*);

/******************************************************************************
 *
 * int canReceiveInt(int CANID, int *MDL, int* MDH)
 *
 * canReceiveInt() receives frame with specified CANID and converts
 * date from char[] to int. The lower 4Bytes are returned in MDL,
 * the higher 4 Bytes in MDH.
 *
 * RETURN:
 *		Success ->  0
 * 		Error	->  -1 (e.g. no frames received or interface down)
 *****************************************************************************/
int canReceiveInt(int, int*, int*);

/******************************************************************************
 *
 * void skaleIq2Byte(float IQ, int* BYTE);
 *
 * skaleIq2Byte() converts value from iq-format (IQ) to 32Bit Hex Value and
 * returns it in BYTE.
 *
 *****************************************************************************/
void skaleIq2Byte(float iq, int* Byte);

/******************************************************************************
 *
 * void skaleByte2Iq(float* IQ, int BYTE);
 *
 * skaleByte2Iq() converts value from 32Bit Hex format (BYTE) to
 * iq-format and returns it in IQ.
 *
 *****************************************************************************/
void skaleByte2Iq(float *iq, int Byte);

/******************************************************************************
 *
 * setSpeedZero(struct can_frame Send)
 *
 * setSpeedZero() is used to set speed setpoint in TI unit to zero and
 * is mostly used in start up and shut down procedures
 *
 *
 *****************************************************************************/
void setSpeedZero(struct can_frame);

#endif /* MOTORCTRL_H_ */
