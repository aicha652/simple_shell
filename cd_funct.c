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
	char *word = NULL;
	char *path;
	int i = 0;
	char **array;

	array = malloc(sizeof(char *) * len());
	while (environ[i] != NULL)
	{
		array[i] = malloc(sizeof(char) * _strlen(environ[i]));
		_strcpy(array[i], environ[i]);
		i++;
	}
	i = 0;
	while (array[i] != NULL)
	{
		word = strtok(array[i], "=");
		if (_strcmp(word, name) == 0)
		{
			path = strtok(NULL, "=");
			free(array);
			return (path);
		}
		i++;
	}
	free(array);
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
