#include "shell.h"
/**
 * built_s - Structure representing a built-in command
 *
 * @name: The name of the built-in command.
 * @p: Pointer to the corresponding function
 * to execute for the built-in command.
 */

char *builtin_lineptr[] = {"cd", "help", "exit", "NULL"};

int (*function_built[]) (char **) = {
        &wsh_help,
        &wsh_exit,
        &wsh_ctrl,
        /* &wsh_cdir */
};

/* wsh_builtins - Builins
 *
 */

int wsh_builts(void)
{
	return (sizeof(builtin_lineptr) / sizeof(char *));
}


/* wsh_cd - builtins
 *
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

int wsh_ctrl(char **args)
{
	(void)args;
	free(args);
	return (BUF);
}

int wsh_help(char **args)
{
	int itr;

	printf("Use man Pages\n");

	(void)args;
	for (itr = 0; itr < wsh_builts(); itr++)
	{
		printf("%s \n", builtin_lineptr[itr]);
	}
	return (1);
}
