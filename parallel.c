#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {

	int n = argc;
	char path[100];
	strcpy(path, "/bin/");
	strcat(path, argv[1]);
	int pid;
	for (int i = 2; i < argc; ++i) {
		 if ((pid = fork()) == 0) {
				char *arguments[] = {path, argv[i], NULL};
				execv(path, arguments);
		  }
	}
	
	while (wait(0) > 0);
	
    return 0;
}
