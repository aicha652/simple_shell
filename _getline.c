#include "main.h"
#define BUFFER_SIZE 1024

/**
 * _getline - function that reads a string of text
 * @str: parameter
 * @sz: size
 * @stream: file
 * Return: size_t
 */
ssize_t _getline(char **str, size_t *sz, FILE *stream)
{
	ssize_t i = 0, size = 0, t = 0, t1 = 0, n = 0;
	char buff[1024], *new_str;

	(void)stream;
	if (str == NULL || sz == NULL)
		return (-1);

	while (t1 == 0 && (i = read(STDIN_FILENO, buff, 1024 - 1)))
	{
		if (i == -1)
			return (-1);
		buff[i] = '\0';

		n = 0;

		while (buff[n] != '\0')
		{
			if (buff[n] == '\n')
				t1 = 1;
			n++;
		}
		if (t == 0)
		{
			i++;
			*str = malloc(sizeof(char) * i);
			_memcpy(*str, buff, i);
			*sz = i;
			t = 1;
		}
		else
		{
			size += i;
			new_str = malloc(sizeof(char) * (*sz + i));
			_memcpy(new_str, *str, *sz);
			_memcpy(new_str + *sz, buff, i);
			free(*str);
			*str = new_str;
			*sz += i;
		}
	}
	return (size);
}
