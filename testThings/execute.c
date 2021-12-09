#include "main.h"

/**
 * execute - receives command line arg list (first file name)
 * @argv: arguments
 */

void execute(char **argv)
{
	pid_t pid = fork();
	int status;

	if (pid < 0)/**fork a child process*/
	{
		write(1, "*** ERROR: forking child process failed\n", 40);
		exit(1);
	}
	else if (pid == 0)/**for the child process:*/
	{
		if (execvp(*argv, argv) < 0)/**execute the command*/
		{
			write(1, "*** ERROR: exec failed\n", 23);
			exit(1);
		}
	}
	else/**for the parent:*/
	{
		while (wait(&status) != pid)/**wait for completion*/
			;
	}
}
