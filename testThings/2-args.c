#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * main - print all arguments
 * @argc: size of argv
 * @argv: array
 * Return: end program
 **/

int main(int argc, char **argv)
{
	int i;

	for (i = 1; ; i++)
	{
		printf("%s\n", argv[i]);
		if (argv[i + 1] == NULL)
			break;
	}
	printf("filename: %s\n", argv[0]);
	if (argv[2] != NULL)
		printf("second arg: %s\n", argv[2]);
	(void)argc;
	return (0);
}
