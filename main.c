#include "main.h"

/**
 * exec_cmd -execute cmd
 * @args: arguments
 */
void exec_cmd(char **args)
{
	pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		perror("child process could not be created");
		return;
	}
	if (pid == 0)
	{
		if (execve(args[0], args, NULL) == -1)
		{
			perror(args[0]);
			_free(args);
			exit(EXIT_FAILURE);
		}
		exit(EXIT_SUCCESS);
	}
	else
		waitpid(pid, NULL, 0);
}

/**
 * print_dir - print directory
 */
void print_dir(void)
{
	char cwd[1024];

	getcwd(cwd, sizeof(cwd));
	write(1, cwd, _strlen(cwd));
	write(1, "\n", 1);
}

/**
 * main - check the code
 * @argc: num of args
 * @argv: arguments
 * @envp: environ args
 * Return: Always 0
 */
int main(int argc, char **argv, char **envp)
{
	char *line = NULL, *line_copy = NULL, *tok;
	size_t sz = 0;
	ssize_t num_char;
	int num_tok = 0, i = 0;

	(void) argc, (void) envp;
	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDIN_FILENO, "($) ", 4);
		num_char = getline(&line, &sz, stdin);
		if (num_char == -1)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 2);
			if (line)
				free(line);
			exit(EXIT_SUCCESS);;
		}
		if (line[_strlen(line) - 1] == '\n')
			line[_strlen(line) - 1] = '\0';
		num_char++;
		line_copy = malloc(sizeof(char) * num_char);
		if (line_copy == NULL)
		{
			free(line);
			free(line_copy);
			perror("command ");
			exit(EXIT_SUCCESS);
		}
		_strcpy(line_copy, line);
		tok = strtok(line, " \t\n");
		while (tok != NULL)
		{
			num_tok++;
			tok = strtok(NULL, " \t\n");
		}
		num_tok++;
		argv = malloc(sizeof(char *) * num_tok);
		tok =strtok(line_copy, " \t\n");
		for (i = 0; tok != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * _strlen(tok) + 1);
			_strcpy(argv[i], tok);
			tok = strtok(NULL, " \t\n");
		}
		argv[i] = NULL;
		free(line_copy);
		if (argv[0] != NULL)
		{
			if (exit_status(argv) != 0)
			{
				_free(argv);
				exit(EXIT_SUCCESS);
			}
			if (_strcmp(argv[0], "ls") == 0)
				*argv = "/bin/ls";
			if (_strcmp(argv[0], "env") == 0)
			{
				print_env(argv, envp);
				_free(argv);
			}
			else if (_strcmp(argv[0], "setenv") == 0)
			{
				mysetenv(argv);
				_free(argv);
			}
			else if (_strcmp(argv[0], "unsetenv") == 0)
			{
				myunsetenv(argv);
				_free(argv);
			}
			else if (_strcmp(argv[0], "cd") == 0)
			{
				cd_funct(argv);
				_free(argv);
			}
			else
			{
				print_exit(argv);
				exec_cmd(argv);
				_free(argv);
			}
		}
		else
			_free(argv);
	}
	return (0);
}
