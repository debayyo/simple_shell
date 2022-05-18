#include "shell.h"

/* List of builtin commands, followed by their corresponding functions.*/
char *builtin_str[] = {
	"cd",
	"help",
	"exit"
};

int (*builtin_func[]) (char **) = {
	&cd_hsh,
	&help_hsh,
	&exit_hsh
};

int hsh_num_builtins(void)
{
	return (sizeof(builtin_str) / sizeof(char *));
}

/**
 * cd_hsh- change directory function
 * @args: List of args.  args[0] is "cd".  args[1] is the directory.
 * Return: Always returns 1, to continue executing.
 */
int cd_hsh(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "hsh: expected argument to \"cd\"\n");
	} else
	{
		if (chdir(args[1]) != 0)
			perror("hsh");
	}
	return (1);
}

/**
 * help_hsh- Builtin command to print help.
 * @args: List of args.
 * Return: Always returns 1, to continue executing.
 */
int help_hsh(char __attribute__((__unused__)) **args)
{
	int i;

	printf("Quadri & Aisha shell\n");
	printf("Type program names and arguments, and hit enter.\n");
	printf("The following are built in:\n");

	for (i = 0; i < hsh_num_builtins(); i++)
	{
		printf("  %s\n", builtin_str[i]);
	}

	printf("Use the man command for information on other programs.\n");
	return (1);
}

/**
 * exit_hsh- function to exit the shell
 * @args: list of args
 * Return: Always returns 0.
 */
int exit_hsh(char __attribute__((__unused__)) **args)
{
	return (0);
}
