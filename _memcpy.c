#include "main.h"

/**
 * _memcpy - copy memory
 * @dest: char array
 * @src: char array
 * @n: number of elements
 * Return: pointer to dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int count = 0;

	while (count < n)
	{
		dest[count] = src[count];
		count++;
	}
	return (dest);
}
