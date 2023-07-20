#include "main.h"
/**
 * print_exit - function that exit the shell
 * @argv: arguments
 * Return: void function
 */
void print_exit(char **argv)
{
	if (_strcmp(argv[0], "exit") == 0)
	{
		exit(0);
	}
}
