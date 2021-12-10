#include "main.h"

/**
 * main - main program shell
 * @argc: n of arg
 * @argv: array of args
 * @env: array
 * Return: end program
 **/

int main(int argc, char **argv, char **env)
{
	char *inp, **tokens;
	int ret = 0, mode = 1, isBuilti = 0, fSres = 0;
	(void)argc;
	(void)argv;

	signal(SIGINT, SIG_IGN);
	while (mode)/** repeat until done ...*/
	{
		fSres = firststep(&mode, &inp, &tokens);
		if (fSres == -1)
			break;
		isBuilti = isbuiltin(tokens);
		if (isBuilti == 1)
		{
			rajar(&inp, &tokens, env);
		}
		if (isBuilti == 2)
		{
			_env();
		}
	}
	return (ret);
}

/**
 * firststep - on the shell process
 * @mode: checks interactive mode
 * @inp: input
 * @tokens: all tokens
 * Return: int
 **/
int firststep(int *mode, char **inp, char **tokens)
{
	int len = 0;
	size_t milv = 1024;

	if (isatty(STDIN_FILENO))
		write(1, "$ ", 2); /**display a prompt*/
	else
		*mode = 0;
	len = getline(inp, &milv, stdin);
	if (len == -1)
	{
		free(*inp);
		return (-1);
	}
	if (*(*inp + (len - 1)) == '\n')
		*(*inp (len - 1)) = '0';
	if (len == 1)
		return (1);
	
	*tokens = parse(*inp, **argv);
	if (!*tokens)
	{
		return (1);
	}
	return (0);
}

/**
 * parse -Take input lines and parse into token
 * @line: Input line
 * @argv: Arguments
 */
void parse(char *line, char **argv)
{
	while (*line != '\0')/** if not the end of line... */
	{
	while (*line == ' ' || *line == '\t' || *line == '\n')
		{
			*line++ = '\0';/** replace white spaces with 0*/
		}
	*argv++ = line;/** save the argument position*/
	while (*line != '\0' && *line != ' ' && *line != '\t' && *line != '\n')
		line++;/**skip the argument until...*/
	}
	*argv = '\0';/**mark the end of argument list*/
}

/**
 * isbuiltin - associates w a certain builtin
 * @tokens: all of them
 * Return: int
 **/
int isbuiltin(char **tokens)
{
	if (_strcmp(tokens[0], "exit") == 0)
		return (1);
	if (_strcmp(tokens[0], "env") == 0)
		return (2);
	return (0);
}
