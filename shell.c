#include <stdio.h>
#include <stdlib.h>

int input(char *s, int length);

int main()
{
	char *buffer;
	size_t bufsize = 32;
	size_t characters;

	buffer = (char *)malloc(bufsize * sizeof(char));
	if (buffer == NULL)
	{
		return ('\0');
	}
	while (1)
	{
	printf("root@0035e6b65699:~/holbertonschool-low_level_programming/testShell# ");
	characters = getline(&buffer, &bufsize, stdin);
	}
	free(buffer);
	return (0);
}
