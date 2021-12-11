#include "main.h"

/**
 * execute - receives command line arg list (first file name)
 * @tokens: argument
 */

void execute(char **tokens)
{
	pid_t pid = fork();

	if (pid == -1)
	{
		printf("Failed forking child..\n");
		return;
	}
	else if (pid == 0)
	{
		if (execve(tokens[0], tokens, NULL) < 0)
			printf("Could not execute command..\n");
		exit(0);
	}
	else
	{
		wait(NULL);
		return;
	}
}
