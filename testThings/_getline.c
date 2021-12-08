#include "main.h"
/**
*_getline -Get the input string
*Return: line;
*/
char *_getline()
{
	char *line = NULL;
	size_t buffersize;
	size_t characters;
	int i;

	line = getline(&line, &buffersize, stdin);
	if (line == EOF)
	{
		free(line);
		exit(0);
	}

	for (i = 0, line[i] != '\0'; i++)
	{
		if (line[i] == '\n')
			line[i] = '\0';
	}

	return (line);
}
