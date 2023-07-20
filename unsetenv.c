#include "main.h"
/**
 * myunsetenv - function that remove environment variable
 * @args: arguments
 * Return: void
 */
void myunsetenv(char **args)
{
	if (args[1])
	{
		if (unsetenv(args[1]) == -1)
			perror("unsetenv");
	}
	else
	{
		write(STDERR_FILENO, "unsetenv: Missing argument\n", 27);
	}
}
