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

	tokens = malloc(strlen(inp) + 1);
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
