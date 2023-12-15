#include "shell.h"
#include <string.h>


/**
 * wsh_val_path - Separate the path into new strings.
 * @arg: Command input of the user.
 * @env: Environment.
 * Return: Pointer to strings.
 */
int wsh_val_path(char **arg, char **env)
{
	char *token = NULL;
	char *path_relative = NULL;
	char *path_absolute = NULL;
	size_t val_path, ln;

	struct stat _line_ptr;

    /* Check if the command is in the path */
	if (stat(*arg, &_line_ptr) == 0)
	{
		return (-1);
	}

	/* Retrieve the value of the PATH environment variable */
	path_relative = wsh_path(env);

	/* If PATH is not found, return an error */

	if (!path_relative)
		return (-1);

	/* Tokenize the content of "PATH=" */
	token = strtok(path_relative, ":");

	/* Get the length of the command */
	ln = strlen(*arg);

	/* Iterate through each path in the PATH variable */
	while (token)
	{
		val_path = strlen(token);

	/* allocate memory for the absolute path */
		path_absolute = malloc(sizeof(char) * (val_path + ln + 2));

	/* Check if memory allocation was successful */
		if (!path_absolute)
		{
			free(path_relative);
			return (-1);
		}

		/* Copy the current token to the absolute path*/
		path_absolute = strcpy(path_absolute, token);

		/* absolute path */
		strcat(path_absolute, "/");

		strcat(path_absolute, *arg);
		/* Check if the absolute path exists*/
		if (stat(path_absolute, &_line_ptr) == 0)
        	{
			*arg = path_absolute;
			/*Update the command with the absolute path */

			free(path_relative);
			return (0);
		}
		/* Free the memory allocated for the absolute path*/
		free(path_absolute);

		/* Move to the next token in the PATH variable */
		token = strtok(NULL, ":");
	}

	/* Free the memory allocated for path_relative */

	token = '\0';
	free(path_relative);

	/* If no absolute path is found, return an error */
	return (-1);
}
