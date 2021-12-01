#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int input(char *s, int length);

int main()
{
	char *buffer;
	size_t bufsize = 32;
	size_t characters;
	char *p = "# ";

	buffer = (char *)malloc(bufsize * sizeof(char));
	if (buffer == NULL)
	{
		return ('\0');
	}
	while (1)
	{
	write(1, p, 2);
	characters = getline(&buffer, &bufsize, stdin);
	}
	free(buffer);
	return (0);
}
