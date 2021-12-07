#include "main.h"
/**
*tokenoide -Parse stirng into substring
*@line: Line input
*Return: arguments_token
*/
char **tokenoide(char *line)
{
	int size = _strlen(line);
	char *token;
	char **arrguments_token = malloc(sizeof(char *) * size);
	int i;

	if (!arguments_token)
	{
		perror(error with args);
		exit(EXIT_FAILURE);
	}
	token = strtok(command_line, " ");
	for (i = 0; token != NULL; i++)
	{
		arguments_token[i] = token;
		token = strtok(NULL, " ");
	}

	return (arguments_token);
}
