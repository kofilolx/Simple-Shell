#include "shell.h"

/**
 * wsh_builtins_count - Returns the number of built-in commands.
 *
 * Return: total number of builtin commands
 */
int wsh_builtins_count(void)
{
	return (sizeof(builtins) / sizeof(struct built_s) - 1;);
}

/**
 * wsh_cd - Builtin command for changing the current directory.
 * @args: User input
 *
 * Return: 1 Always on Success
 */
int wsh_cd(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "wicksh: cd: missing arg\n");
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("wicksh: cd");
		}
	}
	return (1);
}

/**
 * wsh_ctrl - Builtin command for ctrl.
 * @args: User input
 *
 * Return: return BUF on success
 */
int wsh_ctrl(char **args)
{
	(void)args;

	free(args);
	return (BUF);
}

/**
 * wsh_help - Builtin command for displaying help information.
 * @args: User input
 *
 * Return: 1 Always on success
 */
int wsh_help(char **args)
{
	int itr;

	printf("Use man Pages\n");

	(void)args;

	for (itr = 0; builtins[itr].name != NULL; itr++)
	{
		printf("%s \n", builtins[itr].name);
	}
	return (1);
}
