#include "main.h"
/**
 * print_cd - function that changes the directory
 * @args: arguments
 * Return: 0 on success, 1 on failure
 */
int print_cd(char **args)
{
	char *home = _getenv("HOME");
	static char _prevdir[PATH_MAX] = "";
	char _currdir[PATH_MAX];
	char *dir[2];
	char prevdir_copy[PATH_MAX];

	if (args[1] == NULL)
	{
		dir[0] = home;
		getcwd(_currdir, PATH_MAX);
	}
	else if (_strcmp(args[1], "-") == 0)
	{
		if (_prevdir[0] == '\0')
		{
			write(2, "./hsh: cd: OLDPWD NOT SET\n", 26);
			free(home);
			return (1);
		}
		dir[0] = _prevdir;
	}
	else
	{
		dir[0] = args[1];
		getcwd(_currdir, PATH_MAX);
	}
	dir[1] = NULL;
	_strcpy(prevdir_copy, _prevdir);
	if (chdir(dir[0]) != 0)
	{
		perror("cd");
		free(home);
		return (1);
	}
	else
	{
		getcwd(_currdir, PATH_MAX);
		_strcpy(_prevdir, prevdir_copy);
		setenv("PWD", _currdir, 1);
		free(home);
		return (0);
	}
	return (0);
}
