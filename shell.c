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
	pid_t pid;
	int status;

	pid = fork();
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
/**
*main -main shell
*Return: 0
*/
int main(void)
{
	char line[1024];
	char *argv[64];
	char *p = "# ";
	char *buffer;
	size_t bufsize = 32;
	size_t car;

	buffer = (char *)malloc(bufsize * sizeof(char));
	if (buffer == NULL)
		return ('\0');
	while (1)
	{
		write(1, p, 2);
		car = getline(&buffer, &bufsize, stdin);
		if (strcmp(line, "exit\n") == 0)
			break;
		toktok(line, argv);
		execute(argv);
	}
	free(buffer);
	return (0);
}
