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
