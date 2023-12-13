#include "shell.h"
#include <errno.h>


/**
 * main - Entry point for the shell program.
 *
 * @argc: Number of arguments.
 * @arg: Array of command-line arguments.
 * @env: Array of environment variables.
 * Return: Always 0 (Success).
 */


int main(int argc, char **arg, char **env)
{
	int p_val, stat, boolPath;			/* Process Value, Status, Path Check */
	char *lines = NULL;				/* User input */
	char **bufline = NULL;				/* Command */
	int TRUE = 1;					/* Boolean for the main loop */


/*	void(argc);*/					 /* Suppress unused argument warning */
	while (TRUE)
	{

		lines = wsh_getline();			/* Takes User Input */
		errno = 0;

		/* Check if there was an error or if the user entered EOF */
		if (errno == 0 && lines == NULL)
		{
			return (0);
		}


		if (lines)
		{
			p_val++;
			bufline = wsh_tokenize(lines);

			/* Free user input if it cannot be tokenized */
			if (!bufline)
			{
				free(lines);
			}

			/* Check if the command is 'env' */
			if (!strncmp(bufline[0], "env", strlen("env")))
			{
				wsh_get_environ(env);
			}
			else
			{
				boolPath = wsh_val_path(&bufline[0], env);

				stat = wsh_process(bufline, arg, env, lines, p_val, boolPath);

				/* Check for a special status BUF (buffer overflow) */
				if (stat == BUF)
				{
					free(lines);
					return (0);
				}

				/* Free the command if it is not in the PATH */
				if (boolPath == 0)
					free(bufline[0]);
			}
			free(bufline);
		}
		else
		{

			/* Check if the input is from a terminal and print a new line */
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			exit(stat);
		}
		free(lines);
	}
	return (stat);
}
