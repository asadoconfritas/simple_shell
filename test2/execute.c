#include "main.h"
/**
 * _env - print env
 * Return: end program
 **/
void _env(void)
{
	int i = 0;

	if (envaux)
		while (*(envaux + i))
		{
			printf("%s\n", *(envaux + i));
			i++
		}
}
