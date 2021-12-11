#include "main.h"
#include <stdio.h>

/**
 * main - main program shell
 * @argc: n of arg
 * @argv: array of args
 * Return: end program
 **/
int main(int argc, char **argv)
{
	char **tokens;
	int mode = 1, fSres = 0, isa = 0;
	(void)argc;

	while (mode)
	{
		isa = isatty(STDIN_FILENO);
		if (isa == 1)
			write(1, "$ ", 2); /**display a prompt*/
		else
			mode = 0;
		fSres = firststep(&mode, argv, &tokens);
		if (fSres == -1)
			exit(0);
	}
	if (tokens)
		free(tokens);
	return (0);
}

/**
 * firststep - on the shell process
 * @mode: checks interactive mode
 * @inp: input
 * @tokens: all tokens
 * Return: int
 **/
int firststep(int *mode, char **inp, char ***tokens)
{
	int len = 0;
	size_t milv = 1024;

	len = getline(inp, &milv, stdin);
	if (len == -1)
	{
		free(*inp);
		return (-1);
	}
	if (*(*inp + len - 1) == '\n')
		*(*inp + len - 1) = '\0';
	if (len == 1)
		return (1);

	*tokens = parse(*inp, " ");
	if (!*tokens)
	{
		return (1);
	}
	if (_strcmp(inp[0], "exit") == 0)
	{
		*mode = 0;
		exit(0);
	}
	execute(tokens[0]);
	return (0);
}
