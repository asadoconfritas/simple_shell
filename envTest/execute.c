#include "main.h"

/**
 * execute - receives command line arg list (first file name)
 * @alltok: input
 * @env: environment
 * @tokens: argument
 */

void execute(char **tokens, char ***alltok, char **env)
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
		i = execve(tokens[0], *alltok, env);
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
