#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/**
*prompt -Inifinite loop for the prompt
*@argv: Argument
*/
void prompt(char *argv[])
{
	char *line;
	char **arguments;
	int i;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "# ", 2);
		i++;

		line = _getline();
		arguments = tokenoide(line);
		execute_command(arguments, argv, i, line);

		free(line);
		free(arguments);
	}
}
