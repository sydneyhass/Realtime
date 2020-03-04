#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "des-mva.h"

void displayMenu();

int main(void) {
	char userInput[4];
	char personID[32];

	while(1) {
		displayMenu();
		scanf("%s", userInput);
		if (strcmp(userInput, "ls") == 0 || strcmp(userInput, "rs") == 0) {
			printf("Enter your ID: ");
			scanf("%s", personID);

		}
		if(strcmp(userInput, "exit") == 0) {
			break;
		}
	}
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
