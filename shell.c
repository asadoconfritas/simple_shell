#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/**
*
*
*
*/

void execute(char **argv)
{
	pid_t pid;
	int status;

	if((pid = fork()) < 0)
	{
		exit(1);
	}
	else if (pid == 0)
	{
		if(execvp(*argv, argv) < 0)
		{
			exit(1);
		}
	}
	else
	{
		while (wait(&status) != pid)
			;
	}
}
