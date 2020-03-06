#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/neutrino.h>
#include <sys/netmgr.h>

#include "des-mva.h"

void displayMenu();

int main(int argc, char* argv[]) {
	int coid;
	char userInput[4];
	int personID = 0;
	int weight = 0;
	pid_t serverpid;
	Person person;

	// TODO: Replace with number of required arguments
	if(argc != 5) {
		fprintf(stderr, "Wrong number of arguments\n");
		exit(EXIT_FAILURE);
	}

	serverpid = atoi(argv[1]);
	if((coid = ConnectAttach(ND_LOCAL_NODE, serverpid, 1, _NTO_SIDE_CHANNEL, 0)) == -1) {
		fprintf (stderr, "ConnectAttach error\n");
		perror (NULL);
		exit(EXIT_FAILURE);
	}

	//TODO: Fix implementation to meet specification
	while(1) {
		displayMenu();
		scanf("%s", userInput);
		if (strcmp(userInput, "ls") == 0 || strcmp(userInput, "rs") == 0) {
			printf("Enter your ID: ");
			scanf("%d", person.personID);
		}
		if(strcmp(userInput, "ws") == 0) {
			printf("Enter your weight: ");
			scanf("%d", weight);
		}
		if(strcmp(userInput, "exit") == 0) {
			break;
		}

		if(MsgSend(coid, &person, sizeof(person) + 1, NULL, 0) == -1L) {
			fprintf (stderr, "MsgSend had an error\n");
			exit (EXIT_FAILURE);
		}
	}

	ConnectDetach(coid);

	return EXIT_SUCCESS;
}

void displayMenu() {
	printf("\nEnter the event type:\n");
	printf("\t%s\n", "ls  - left scan");
	printf("\t%s\n", "rs  - right scan");
	printf("\t%s\n", "ws  - weight scale");
	printf("\t%s\n", "lo  - left open");
	printf("\t%s\n", "ro  - right open");
	printf("\t%s\n", "lc  - left close");
	printf("\t%s\n", "rc  - right close");
	printf("\t%s\n", "gru - guard right unlock");
	printf("\t%s\n", "glu - guard left unlock");
	printf("\t%s\n", "grl - guard right lock");
	printf("\t%s\n", "gll - guard left lock");
	printf("\t%s\n", "exit  - quit the program");
}
