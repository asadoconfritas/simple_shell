#include "main.h"
#include <errno.h>
/**
 * rajar - exit the program
 * @inp: input
 * @tokens: all tok
 * @env: environment
 * Return: end program
 **/
void rajar(char *inp, char *tokens, char *env)
{
	int i;

	if (inp)
		free(inp);
	if (tokens)
		for (i = 0; tokens[i]; i++)
			free(tokens[i]);
	if (env)
		for (i = 0; env[i]; i++)
			free(env[i]);
	exit(-1);
}
