
/******************************************************************************
 *
 * File:	cansend.c
 * Author:	Tobias Wurm
 *
 * >> see MotorCtrl.h for descriptions and prototypes <<
 *****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <net/if.h>
#include <sys/ioctl.h>
#include <sys/socket.h>

#include <linux/can.h>
#include <linux/can/raw.h>

#include "lib.h"

int canSend(struct can_frame frame)
{
	int s; 						//T	// 	can raw socket
	int nbytes;					//T	// 	unused
	struct sockaddr_can addr;	//T	// 	return value bind()
	//struct can_frame frame;	//T	//	Data and Identifier
	struct ifreq ifr;			//T	//	Interface Information
	char interfName[]="can0";

	/* open socket */
	if ((s = socket(PF_CAN, SOCK_RAW, CAN_RAW)) < 0) {
		perror("socket");
		return 1;
	}

	addr.can_family = AF_CAN;

	strncpy(ifr.ifr_name, &interfName[0], 4);	//copies Interf.name
	if (ioctl(s, SIOCGIFINDEX, &ifr) < 0) {
		perror("SIOCGIFINDEX");
		return 1;
	}
	addr.can_ifindex = ifr.ifr_ifindex;

	/* disable default receive filter on this RAW socket */
	/* This is obsolete as we do not read from the socket at all, but for */
	/* this reason we can remove the receive list in the Kernel to save a */
	/* little (really a very little!) CPU usage.                          */
	setsockopt(s, SOL_CAN_RAW, CAN_RAW_FILTER, NULL, 0);

	if (bind(s, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
		perror("bind");
		return 1;
	}

	/* send frame */
	if ((nbytes = write(s, &frame, sizeof(frame))) != sizeof(frame)) {
		perror("write");
		return 1;
	}

	close(s);

	return 0;
}
