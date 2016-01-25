/******************************************************************************
 *
 * File:	canreceivec.c
 * Author:	Tobias Wurm
 *
 * >> see MotorCtrl.h for descriptions and prototypes <<
 *****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <ctype.h>
#include <libgen.h>
#include <time.h>

#include <sys/time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <sys/uio.h>
#include <net/if.h>

#include <linux/can.h>
#include <linux/can/raw.h>

#include "terminal.h"

#define CAN_BITRATE 1000000

//// Global Variables ////
int s=0;

int openReceiveSocket()
{
	struct ifreq ifr;
	char interfName[]="can0";
	struct sockaddr_can addr;

	//Set ifr
	memset(&ifr.ifr_name, 0, sizeof(ifr.ifr_name));	//write zeros in ifr.ifr_name
	strncpy(ifr.ifr_name, &interfName[0], 4);	//copy "can0" in .ifr_name

	s = socket(PF_CAN, SOCK_RAW, CAN_RAW);
	if (s < 0)
	{
		perror("socket");
		return 1;
	}

	if (ioctl(s, SIOCGIFINDEX, &ifr) < 0)	//Writes on ifr.ifr_index
	{
		perror("SIOCGIFINDEX");
		exit(1);
	}

	addr.can_family = AF_CAN;
	addr.can_ifindex = ifr.ifr_ifindex;

	//Bind Socket
	if (bind(s, (struct sockaddr *)&addr, sizeof(addr)) < 0)
	{
		perror("bind");
		return 1;
	}

	return 0;
}

int canReceive(struct can_frame* frame, int filter, int* idMatch)
{
	int nbytes, ret, filterRecID, running = 1, noMatch=0;
	//struct can_frame frame;
	fd_set rdfs;
	struct timeval selectblockmax;

	do
	{
		FD_ZERO(&rdfs); // Initializes the file descriptor set fdset
						// to have zero bits for all file descriptors.

		FD_SET(s, &rdfs);	//Sets the bit for the file descriptor fd
							//in the file descriptor set fdset.

		// init timeval structure for select()
		// Specifies the time select() block when no
		// socket(file) descriptors are ready
		selectblockmax.tv_sec = 1;
		selectblockmax.tv_usec = 0;

		//	!	The select() function tests file descriptors
		//		in the range of 0 to nfds-1.
		if ((ret = select((s+1), &rdfs, NULL, NULL, &selectblockmax)) < 0)
		{
			perror("select");
		}
		if(ret == 0)
		{
			printf("select() timed out. No CAN-MSGs received\n");
			return 1;
		}

		if (FD_ISSET(s, &rdfs))
		{
			// Reade CAN RAW Sockets
			nbytes = read(s, frame, sizeof(struct can_frame));

			if (nbytes < 0)
			{
				perror("read");
				return 1;
			}

			if (nbytes < sizeof(struct can_frame))
			{
				fprintf(stderr, "read: incomplete CAN frame\n");
				return 1;
			}
		 }

		if(filter != 0)	//Filter enabled
		{
			//// Filter Frames ////							Example:
			filterRecID = (frame->can_id) & 0x1FFFFFFF;	// 101101 && 000111
															// ----------------
															//		000101

			//Tell function-caller about results
			if(!(filterRecID ^ filter))
			{
				*idMatch=1;	//Return Value. Frame matches filter
				running = 0;
			}
			else
			{
				*idMatch=0;	//Return Value. Frame does not match filter.
				noMatch++;
			}

			if(noMatch == 32)
			{
				running = 0;
			}
		}
		else	// Filter disabled
		{
			*idMatch=1;	//Return Value. Frame matches filter
			running = 0;
		}

	}while(running);

	return 0;
}

void closeReceiveSocket()
{
	//close Socket
	close(s);

}
