#include "shell.h"


/**
 * wsh_get_line - Reads user input as an argument
 * from either file stream or standard input.
 *
 * Return: Allocated buffer containing the line.
 */

char *wsh_getline(void)
{
	char *bufline;			/* Buffer for user input */
	ssize_t read;			/* Number of characters read */
	size_t buflen;			/* Length of the buffer */
	char *prompt;			/* String to prompt user */

	/*Initialization*/
	bufline = NULL;			/* Initializing bufline to NULL */
	buflen = 0;			/* Initializing buflen to 0 */
	prompt = "wicksh -\n|> ";	/* UUser input prompt */

	if (isatty(STDIN_FILENO))
	{
		/*Write prompt "$ " to the terminal */
		write(STDOUT_FILENO, prompt, 2);
	}

	/* Read a line from the file into the buffer 'line' */
	read = getline(&bufline, &buflen, stdin);

	/* Check for error [ctrl + D] or end of file [EOF] */
	if (read == -1)
	{
		free(bufline);		/* Free allocated memory */
		exit(EXIT_SUCCESS);	/* Exit successfully */

	}

	return (bufline);		/* Return the buffer containing the line (strings)*/
}
