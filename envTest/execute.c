#include "main.h"
#include <stdio.h>

/**
 * execute - receives command line arg list (first file name)
 * @alltok: input
 * @env: environment
 * @tokens: argument
 */

void execute(char **tokens, char ***alltok, char **env)
{
	pid_t pid = fork();
	(void)alltok;

	if (pid == -1)
	{
		printf("Failed forking child..\n");
		return;
	}
	else if (pid == 0)
	{
		if (execve(tokens[0], tokens, env) < 0)
			printf("Could not execute command..\n");
		exit(0);
	}
	else
	{
		wait(NULL);
		return;
	}
}
