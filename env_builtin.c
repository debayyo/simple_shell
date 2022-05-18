#include "shell.h"

/**
 *hsh_env - prints the current environment
 *@args: array of arguments
 *@start: double pointer
 *Return: -1 if an error occurs, otherwise 0
 */

int hsh_env(char **args, char __attribute__((__unused__)) **start)
{
	int index;
	char nc = '\n';

	if (!environ)
		return (-1);
	for (index = 0; environ[index]; index++)
	{
		write(STDOUT_FILENO, environ[index], _strlen(environ[index]));
		write(STDOUT_FILENO, &nc, 1);
	}

	(void)args;
	return (0);
}
