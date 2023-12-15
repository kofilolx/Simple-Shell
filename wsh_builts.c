#include "shell.h"

/**
 * wsh_builts - Returns the number of built-in commands.
 *
 * Description: This function calculates the number of built-in commands
 * by dividing the total size of the builtins array by the size of a single
 * struct built_s element.
 *
 * Return: The number of built-in commands.
 */
struct built_s
{
	char *nom;
	void (*ops)(char **args);
}; 

struct built_s builtins[] = {
		{"exit", wsh_exit},
		{"env", wsh_ctrl},
		{"cd", wsh_cdir},
		{"help", wsh_help},
		{NULL, NULL}
	};

int wsh_builts(void)
{
	return sizeof(builtins) / sizeof(struct built_s);
}
