#include "shell.h"
#include <errno.h>

#define BUF 200

/**
 * cleanup - Frees allocated memory for lines and bufline.
 * @lines: User input.
 * @bufline: Tokenized command.
 */
void cleanup(char *lines, char **bufline)
{
	free(lines);

	if (bufline)
	{
		free(bufline[0]);
		/* free(bufline);*/
	}
}

/**
 * handle_cmd - Handles the 'env' command.
 * @env: Array of environment variables.
 */
void handle_env_cmd(char **env)
{
	wsh_get_environ(env);
}

/**
 * handle_cmd - Handles commands other than 'env'.
 * @bufline: Tokenized command.
 * @arg: Command-line arguments.
 * @env: Array of environment variables.
 * @lines: User input.
 * @p_val: Process value.
 */
void handle_cmd(char **bufline, char **arg, char **env, char *lines, int p_val)
{
	int boolPath = wsh_val_path(&bufline[0], env);
	int stat = wsh_process(bufline, arg, env, lines, p_val, boolPath);

	if (stat == BUF)
	{
		cleanup(lines, bufline);
		exit(0);
	}

	if (boolPath == 0)
		free(bufline[0]);
}

/**
 * main - Entry point of the shell.
 * @argc: Number of command-line arguments.
 * @arg: Command-line arguments.
 * @env: Array of environment variables.
 * Return: Status code.
 */
int main(int argc, char **arg, char **env)
{
	int p_val = 0;
	int stat = 0;
	int boolPath;
	char *lines = NULL;
	char **bufline = NULL;
	int TRUE = 1;

	(void)argc;  /* Suppress unused argument warning */

	while (TRUE)
	{
		lines = wsh_getline();
		errno = 0;

		if (errno == 0 && lines == NULL)
		{
			return (0);
		}

		if (lines)
		{
			p_val++;
			bufline = wsh_tokenize(lines);

			if (!bufline)
			{
				cleanup(lines, NULL);
			}
			else
			{
				if (!strncmp(bufline[0], "env", strlen("env")))
				{
					handle_env_cmd(env);
				}
				else
				{
					handle_cmd(bufline, arg, env, lines, p_val);
				}

				cleanup(lines, bufline);
			}
		}
		else
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			exit(stat);
		}
	}

	return (stat);
}
