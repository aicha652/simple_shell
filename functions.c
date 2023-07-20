#include "main.h"
/**
 * _strlen -function that returns the length of a string
 * @s: the length of a string
 * Return: the length of a string
 */
int _strlen(const char *s)
{
	int count = 0;

	while (s[count])
	{
		count++;
	}
	return (count);
}

/**
 * *_strcpy - function that copies the string
 * @src: the string to be copied
 * @dest: the value to be return
 * Return: the pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	unsigned int src_len, i;

	src_len = _strlen(src);

	for (i = 0; i < src_len; i++)
	{
		if (src[i + 1] == '\n' && src[i] == ' ')
		{
		}
		else
			dest[i] = src[i];
	}
	dest[i] = '\0';

	return (dest);
}
/**
 * _strcmp - function that compares two strings
 * @s1: first string
 * @s2: second string
 * Return: the value of comparing
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] != '\0' || s2[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
	}
	return (0);
}
