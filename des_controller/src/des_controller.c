#include <stdio.h>
#include <stdlib.h>

#include <sys/neutrino.h>
#include <sys/types.h>
#include <sys/netmgr.h>
#include <unistd.h>

#include "../../des_inputs/src/des-mva.h"

int main(int argc, char* argv[]) {
	pid_t displaypid;
	int coid;
	int chid;
	int rcvid;

	// TODO: Replace with number of required arguments
	if(argc != 5) {
		fprintf(stderr, "Wrong number of arguments\n");
		exit(EXIT_FAILURE);
	}

	displaypid = atoi(argv[1]);

	if((chid = ChannelCreate(0)) == -1) {
		fprintf(stderr, "Error creating channel");
		exit(EXIT_FAILURE);
	}

	//TODO: Attach to display - need nid, chid, coid
	if((coid = ConnectAttach(ND_LOCAL_NODE, displaypid, 1, _NTO_SIDE_CHANNEL, 0)) == -1) {
		fprintf (stderr, "ConnectAttach error\n");
		perror (NULL);
		exit(EXIT_FAILURE);
	}

	while(1) {
		//TODO: Create person struct
//		if((rcvid = MsgReceive(chid, &person, sizeof( person ), NULL)) < 0) {
//
//		}

		//TODO: Process state machine
		//TODO: Create display struct
		//		if(MsgSend(coid, &display, sizeof(display), NULL, 0) == -1L) {
		//			fprintf (stderr, "MsgSend had an error\n");
		//			exit (EXIT_FAILURE);
		//		}
		//TODO: Reply to inputs
//		if(MsgReply(rcvid, EOK, NULL, 0) == -1) {
//			perror("MsgReply error.");
//			exit(EXIT_FAILURE);
//		}
		//TODO: Check for exit message, send exit message and break loop
	}

	ConnectDetach(coid);
	ChannelDestroy(chid);

	return EXIT_SUCCESS;
}
