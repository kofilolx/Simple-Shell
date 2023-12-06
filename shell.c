#include "shell.h"

/**
 * main - Entry point for the shell program
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
	char *prompt = "wicksh \n|> ";
	char *line = NULL;
	size_t buflen = 0;
	ssize_t lines = 0;
	int TRUE = 1;

	while (TRUE)
	{
		printf("%s", prompt);
		lines = getline(&line, &buflen, stdin);

		if (lines < 0)
		{
			return (-1);
		}

		printf("%s\n", line);
		/* free(line);*/
	}
	free(line);

	return (0);
}
