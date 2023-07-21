#include "main.h"

/**
 * _free - free an array
 * @args: to be free
 */
void _free(char **args)
{
	int i;

	for (i = 0; args[i] != NULL; i++)
		free(args[i]);
	free(args);
}
