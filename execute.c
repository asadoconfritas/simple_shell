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
		printf("\nFailed forking child..");
		return;
	}
	else if (pid == 0)
	{
		if (execvp(tokens[0], tokens) < 0)
		{
			printf("\nCould not execute command..");
			exit(0);
		}
	}
	else
	{
		wait(NULL);
		return;
	}
}
