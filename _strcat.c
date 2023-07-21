#include "main.h"

/**
 * _strcat -concatenate 2 strings
 * @dest: first str
 * @src: second str
 * Return: pointer to dest
 */
char *_strcat(char *dest, char *src)
{
	int i, c;

	for (i = 0; dest[i] != '\0'; i++)
		;
	for (c = 0; src[i] != '\0'; c++)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
