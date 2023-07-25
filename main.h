#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <limits.h>
extern char **environ;
int _strlen(const char *s);
char *_strcpy(char *dest, char *src);
void exec_cmd(char **args);
void cmds(char *args[], char **envp);
int _strcmp(char *s1, char *s2);
void print_exit(char **argv);
void print_env (char **argv, char *envp[]);
void print_dir();
int _isdigit(int c);
int _atoi(char *s);
int len();
char *_getenv(char* name);
void cd_funct(char **args);
void _free(char **args);
ssize_t _getline(char **str, size_t *sz, FILE *stream);
char *_strcat(char *dest, char *src);
char *_memcpy(char *dest, char *src, unsigned int n);
void mysetenv(char **args);
void myunsetenv(char **args);
char *_strdup(char *str);
int print_cd(char **args);

#endif /* MAIN_H */
