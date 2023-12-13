#include "shell.h"

/**
 * wsh_path - Retrieve the value of
 * the PATH environment variable.
 * @envp: The local environment.
 *
 * Description Function:
 * This function extracts and returns the
 * value of the PATH variable from
 * the provided local environment.
 *
 * @return: A pointer to the value of the
 * PATH variable.
 */

char *wsh_path(char **envp)
{
	size_t itr;			/* Iterator for array traversal */
	size_t nam;			/* terator for extracting PATH value */
	size_t count;			/* Counter for calculating the length of the PATH value */
	char *path;			/* Pointer to the allocated memory for PATH */

	itr = 0;
	nam = 0;
	count = 5;			/* Initialize count to 5 for "PATH=" */

	path = NULL;			/* Initialize path to NULL */

	/* Find the index of the environment variable "PATH" */
	for (itr = 0; strncmp(envp[itr], "PATH=", 5); itr++)
		;
	if (envp[itr] == NULL)
	{
		return (NULL);
	}

	/* Calculate the length of the PATH value */
	for (count = 5; envp[itr][nam]; nam++, count++)
		;

	/* Allocate memory for the PATH string */
	path = malloc(sizeof(char) * (count + 1));

	/* Check if memory allocation is successful */
	if (path == NULL)
	{
		return (NULL);
	}

	/* Extract the PATH value from the environment variable */
	for (nam = 5, count = 0; envp[itr][nam]; nam++, count++)
	{
		path[count] = envp[itr][nam];
	}

	/* Null-terminate the PATH string */
	path[count] = '\0';

	/* Return the dynamically allocated PATH string */
	return (path);
}
