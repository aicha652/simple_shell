#include "main.h"

/**
 * _strdup - duplicate a str
 * @str: string
 * Return: pointer
 */
char *_strdup(char *str)
{
	unsigned int i, len;
	char *dup;

	if (str == NULL)
		return (NULL);

	len = _strlen(str);
	dup = malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
	{
		perror("malloc");
		return (NULL);
	}
	for (i = 0; i <= len; i++)
		dup[i] = str[i];
	return (dup);
}
