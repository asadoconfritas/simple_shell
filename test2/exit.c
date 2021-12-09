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

/**
 * ctrl_c - does not exit if ctrl c is pressed
 * @n: is not used
 * Return: void
 **/
void ctrl_c(int n)
{
	write(STDOUT_FILENO, "\n> ", 3);
	(void)n;
}

/**
 * ctrl_d - exits if ctrl_d is pressed
 * @inp: input
 * @tokens: all tok
 * @env: environment
 * Return: end program
 **/
void ctrl_d(char *inp, char *tokens, char *env)
{
	rajar(inp, tokens, env);
	write(STDOUT_FILENO, "\n", 1);
	exit(0);
}
