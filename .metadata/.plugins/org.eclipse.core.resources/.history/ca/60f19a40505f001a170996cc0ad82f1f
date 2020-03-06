#include <stdio.h>
#include <stdlib.h>
#include <sys/neutrino.h>
#include <sys/netmgr.h>

int main(void) {
	int chid;

	chid = ChannelCreate(0);

	while(1) {
		//TODO: Display struct
//		MsgReceive(chid, &display, sizeof(display), NULL);

		//TODO: Implement PDL
		// IF message from controller is SCAN.STATE → #define (ls or rs)
		    // THEN display person has been scanned and there id is <int>
		    // IF message from controller is WEIGHED
		    // THEN display person has been weighed and their weight is <int>
		    // ELSE display the message
		    // IF message from controller == "exit"
		    // THEN break out of loop
	}

	ChannelDestroy(chid);

	return EXIT_SUCCESS;
}
