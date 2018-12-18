#include <strings.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char **argv) {

	char input[100];
	ssize_t bytes_read;
	char path[100];
	strcpy(path, "/bin/");
	strcat(path, argv[1]);
	while ( scanf("%s", input) > 0) {
		int pid = fork();
		char *arguments[] = {path, input, NULL};
		if (pid == 0) {
			execv(arguments[0], arguments);
		}

	}
	return 0;
}
