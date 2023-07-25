#include "main.h"

/**
 * cd_funct -cd command
 * @args: argument
 */
void cd_funct(char **args)
{
	if (args[1] == NULL)
	{
		chdir(_getenv("HOME"));
		print_dir();
	}
	else if (_strcmp(args[1], "-") == 0)
	{
		chdir(_getenv("OLDPWD"));
		print_dir();
	}
}

/**
 * _getenv - getenv funct
 * @name: char
 * Return: char pointer
 */
char *_getenv(char *name)
{
	int i;
	char *word, *path;

	if (name == NULL || environ == NULL)
		return (NULL);

	for (i = 0; environ[i] != NULL; i++)
	{
		word = strtok(environ[i], "=");
		if (word != NULL && _strcmp(word, name) == 0)
		{
			path = strtok(NULL, "=");
			if (path != NULL)
				return (_strdup(path));
			break;
		}
	}
	return (NULL);
}

/**
 * len - size of environ
 * Return: size
 */
int len(void)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		i++;
	}
	return (i);
}
