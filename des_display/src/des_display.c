#include <stdio.h>
#include <stdlib.h>
#include <sys/neutrino.h>
#include <sys/netmgr.h>

#include "../../des_inputs/src/des-mva.h"

int main(void) {
	int chid;
	Display display;
	char rMsg[256];

	if ((chid = ChannelCreate(0)) == -1) {
		//TODO:: Error
	}

	while (1) {
		rMsg = MsgReceive(chid, &display, sizeof(display), NULL);

		//TODO: Implement PDL
		// IF message from controller is SCAN.STATE → #define (ls or rs)
		// THEN display person has been scanned and there id is <int>
		if (strcmp(rMsg, inMessages[LS_INPUT]) == 0
				|| strcmp(rMsg, inMessages[RS_INPUT]) == 0) {
			printf("Person scanned ID, ID = %d\n", display.person.personID);
		}

		else if (strcmp(rMsg, inMessages[WS_INPUT] == 0)) {
			printf("Person weighed, weight = %d\n", display.person.weight);
		}

		else {
			printf("%s\n", outMessages[OUTPUT]);
		}
		// ELSE display the message
		// IF message from controller == "exit"
		// THEN break out of loop
	}

	if (ChannelDestroy(chid) == -1) {
		//TODO: Error;
	}

	return EXIT_SUCCESS;
}
