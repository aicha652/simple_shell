#include "main.h"
/**
 * exit_status - function that exit with status
 * @argv: arguments
 * Return: 0 success
 */
int exit_status(char **argv)
{
	int i = 0, status;

	if (_strcmp(argv[0], "exit") == 0)
	{
		if (argv[1] != NULL)
		{
			while (argv[1][i] != '\0')
			{
				if (!_isdigit((unsigned char)argv[1][i]))
				{
					free(argv);
					return (1);
				}
				i++;
			}
			status = _atoi(argv[1]);
			exit(status);
		}
		free(argv);
		exit(0);
	}
	return (0);
}
