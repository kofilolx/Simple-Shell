#include "shell.h"

/**
 * wsh_process - Executes a command in a child process.
 *
 * Description: This function takes the full path of the executable (path) and
 * tokenized user input (toks).
 * It uses fork to create a child process.
 * In the child process, it uses execve to replace the
 * current process image with a new one specified by fullpath.
 * Returns -1
 * if execve fails. In the parent process, it waits for
 * the child process to finish using the wait system call.
 *
 * @arg: Array of command and arguments.
 * @av: Array containing the name of the program.
 * @env: Array of environment variables.
 * @line_ptr: Command line entered by the user.
 * @p_id: Process ID.
 * @check: Checker for adding new test.
 *
 * Return: 0 on success, -1 on failure.
 */
int wsh_process(char **arg, char **av, char **env, char *line_ptr, int p_id, int check)
{
	pid_t c_pid;					/* Process ID of the child */
	int execve_stat, itr;				/* Status of the execve system call */
	int stat;					/* Status of the child process */
	char *specifiers;				/* Demiliters */
	char **environ;				/* Environment variables for execve */

	specifiers = "%d: %s: missing\n";

	if (arg[0] == NULL)
	{
		return (1);
	}

	for (itr = 0; itr < wsh_builts(); itr++)
	{
		if (strcmp(arg[0], builtin_lineptr[itr]) == 0)
		{
			return (function_built[itr](arg));
		}
	}

	/* Initiation of child process using fork */
	c_pid = fork();

	/* Error handling */
	if (c_pid == 0)
	{
		exec_stat = execve(arg[0], arg, env);

		if (exec_stat == -1)
		{
			fprintf(stderr, specifiers, av[0], p_id, arg[0]);
			if (!check)
				free(arg[0]);		/* Free first cmd */

			free(line_ptr);			/* Free strings */

			free(arg);			/* Free allocated mem. */
			exit(errno);
		}
	}
	else if (c_pid > 0)
	{
		wait(&stat);
		return (stat);
	}
	else
	{
		perror("Wicksh");			/* Print wicksh to std output*/
		exit(EXIT_FAILURE);
	}

	return (0); /* Return 0 on success */
}
