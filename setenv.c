#include "main.h"
/**
 * mysetenv - function that sets environment variable
 * @args: arguments
 * Return: void
 */
void mysetenv(char **args)
{
	if (args[1] && args[2])
	{
		if (setenv(args[1], args[2], 1) == -1)
			perror("setenv");
	}
	else
	{
		write(STDERR_FILENO, "setenv: Invalid number\n", 23);
	}
}
