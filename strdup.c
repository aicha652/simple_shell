#include "main.h"

/**
 * _strdup - duplicate a str
 * @str: string
 * Return: pointer
 */
char *_strdup(char *str)
{
	unsigned int i = 0, len;
	char *dup;

	if (str != NULL)
	{
		len = _strlen(str);
		dup = malloc(sizeof(char) * (len + 1));
		if (dup != NULL)
		{
			while (i <= len)
			{
				dup[i] = str[i];
				i++;
			}
		}
		else
			return (NULL);
	}
	else
		return (NULL);
	return (dup);
}
