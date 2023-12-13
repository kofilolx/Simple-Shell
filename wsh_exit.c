#include "shell.h"

/**
 * wsh_exit - Exits the shell.
 *
 * This function acts as a built-in command to gracefully terminate the shell.
 *
 * Return: Always returns -1 to indicate to the main shell loop that the
 *         program should exit.
 */
int wsh_exit(void)
{
	/*
	 * Return -1 to signal the main shell loop that the program
	 * should terminate.
	 */

	return (-1);
}
