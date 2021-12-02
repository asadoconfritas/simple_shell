#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/**
*toktok -Parse into token the input lines
*@line: input line
*@argv: arguments
*/
void toktok(char *line, char **argv)
{
	while (*line != '\0')
	{
		while (*line == ' ')
			*line++ = '\0';
		*argv++ = line;
		while (*line != '\0' && *line != ' ')
			line++;
	}
	*argv = '\0';
}
/**
*execute -Recive command line arg, forks a child process and exe
*@argv: Argument
*/

void execute(char **argv)
{
	pid_t pid = fork();
	int status;

	if (pid < 0)
	{
		exit(1);
	}
	else if (pid == 0)
	{
		if (execvp(*argv, argv) < 0)
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
