#include "main.h"
/**
 * print_exit - function that exit the shell
 * @argv: arguments
 * Return: void function
 */
void print_exit(char **argv)
{
	int status = 0;

	if (argv[1] != NULL)
		status = _atoi(argv[1]);
	_free(argv);
	exit(status);
}
