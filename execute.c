#include "main.h"

/**
 * execute - receives command line arg list (first file name)
 * @tokens: argument
 */

void execute(char **tokens)
{
	int i;
	pid_t pid = fork();

	if (pid == -1)
	{
		printf("Failed forking child..\n");
		return;
	}
	else if (pid == 0)
	{
		i = execvp(tokens[0], tokens);
		if (i < 0)
		{
			printf("Could not execute command..\n");
			exit(0);
		}
		else
		{
			wait(NULL);
			return;
		}
	}
}
