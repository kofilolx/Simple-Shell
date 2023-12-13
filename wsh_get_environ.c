#include "shell.c"

/**
 * wsh_get_environ - Prints environment variables to standard output.
 *
 * Description: This function iterates through
 * the `environ` array and prints each
 * environment variable followed by a newline
 * character to the standard output.
 *
 * Return: Always returns 0 to indicate successful execution.
 */


void wsh_get_environ(char **env)
{
	size_t itr;			/* Iteration count */

	itr = 0;			/* Initializing itr to 0 */

	/* Iterate through the `environ` array */

	while (env[itr] != NULL)
	{
		/*
		 * Write the current environment variable to the standard output.
		 * Use the wsh_str_len function to determine the length of the string.
		 */

		write(STDOUT_FILENO, env[itr], strlen(env[itr]));

		/*
		 * Write a newline character to separate environment variables.
		 */

		write(STDOUT_FILENO, "\n", 1);

		/* Move to the next environment variable */
		itr++;
	}

	/* Return 0 to indicate successful execution */
	/* return (0); */
}
