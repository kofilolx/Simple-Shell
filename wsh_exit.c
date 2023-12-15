#include "shell.h"

/**
 * wsh_exit - Exits the shell.
 *
 * This function acts as a built-in command
 * to gracefully terminate the shell.
 * @args: User input
 *
 * Return: Always returns -1 to indicate to the main shell loop that the
 *         program should exit.
 */
void wsh_exit(char **args)
{
	/*
	 * Return -1 to signal the main shell loop that the program
	 * should terminate.
	 */
	(void)args;
	exit(0);
}
