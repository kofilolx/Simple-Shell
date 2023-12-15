#include "shell.h"

/**
 * wsh_cd - Change directory built-in
 * @args: Array of arguments passed to the function
 *
 * Description: Changes the current working
 * directory based on the given arguments.
 * If no argument is provided, prints an
 * error message.
 */
void wsh_cdir(char **args)
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
}

/**
 * wsh_ctrl - Control built-in
 * @args: Array of arguments
 * passed to the function (unused)
 *
 * Description: Placeholder function
 * for a control built-in. Currently does nothing.
 */
void wsh_ctrl(char **args)
{
	(void)args;
	/* Suppress unused parameter warning */

	free(args);
	/* Free allocated memory (if any) */
}


/**
 * wsh_help - Help built-in
 * @args: Array of arguments
 * passed to the function (unused)
 *
 * Description: Prints a help message
 * providing information on available built-in commands.
 */
void wsh_help(char **args)
{
	(void)args; /* Suppress unused parameter warning */

	printf("Use man Pages\n");
}