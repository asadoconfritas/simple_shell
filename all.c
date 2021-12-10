#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>

/* str functions */
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);

/* shell */
int main(int argc, char **argv);
int firststep(int *mode, char **inp, char ***tokens);
void execute(char **tokens);
char **parse(char *inp, char *del);

#endif
#include "main.h"

/**
 * execute - receives command line arg list (first file name)
 * @tokens: argument
 */

void execute(char **tokens)
{
	int i;
	pid_t pid = fork();

	if (pid == -1)
	{
		printf("Failed forking child..\n");
		return;
	}
	else if (pid == 0)
	{
		i = execvp(tokens[0], tokens);
		if (i < 0)
		{
			printf("Could not execute command..\n");
			exit(0);
		}
		else
		{
			wait(NULL);
			return;
		}
	}
}
#include "main.h"

/**
 * parse - string to toks
 * @inp: input
 * @del: space
 * Return: tokens
 **/
char **parse(char *inp, char *del)
{
	char **tokens;
	char *tokenizer = NULL;
	int i = 0;

	tokens = calloc(strlen(inp) + 1, 1);
	if (!tokens)
		exit(-1);

	tokenizer = strtok(inp, del);
	if (!tokenizer)
		free(tokens);
	while (tokenizer)
	{
		tokens[i] = tokenizer;
		tokenizer = strtok(NULL, del);
		i++;
	}
	return (tokens);
}
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
	int mode = 1, fSres = 0;
	(void)argc;

	while (mode)
	{
		fSres = firststep(&mode, argv, &tokens);
		if (fSres == -1)
			break;
	}
	if (argv)
		free(argv);
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

	if (isatty(STDIN_FILENO))
	{
		write(1, "$ ", 2); /**display a prompt*/
		printf("llego aca");
	}
	else
		*mode = 0;
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
#include "main.h"

/**
 *_strcat - concatenate strings
 * @dest: char
 * @src: char
 * Return: end program
 **/

char *_strcat(char *dest, char *src)
{
	int i, y;

	i = 0;
	y = 0;

	while (dest[i] != 0)
		i++;

	while (src[y] != 0)
	{
		dest[i] = src[y];
		i++;
		y++;
	}
	dest[i] = 0;
	return (dest);
}

/**
 * _strcmp - string compare
 * @s1: char
 * @s2: char
 * Return: end product
 **/

int _strcmp(char *s1, char *s2)
{
	int i, dif;

	dif = 0;
	for (i = 0; (s1[i] != 0) && (s2[i] != 0) && s1[i] == s2[i]; i++)
		continue;
	if (s1[i] != s2[i])
	{
		dif = s1[i] - s2[i];
	}
	return (dif);
}

/**
 * _strlen - return lenght
 * @s: pointer
 * Return: end program
 **/

int _strlen(char *s)
{
	int i;

	i = 0;
	while (*(s + i) != 0)
		i++;
	return (i);
}

/* ADD STRCPY */

/**
 * _strcpy - string copy
 * @dest: char
 * @src: char
 * Return: end program
 **/
char *_strcpy(char *dest, char *src)
{
	int count = 0;

	while (count >= 0)
	{
		*(dest + count) = *(src + count);
		if (*(src + count) == '\0')
			break;
		count++;
	}
	return (dest);
}
