#include "main.h"
/**
 * _isdigit - function that checks for a digit
 * @c: the int to be check
 * Return: 1 Success
 */
int _isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
