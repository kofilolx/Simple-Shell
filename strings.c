#include "shell.h"

/**
 * wsh_str_cmp - Compares two strings character by character up to the specified length.
 * @name: Name supplied by the user to search for.
 * @variable: Variable to compare against.
 * @length: Length of the name.
 * Return: 1 if strings are not equal, -1 if lengths are different, 0 if strings are equal.
 */

int wsh_str_cmp(char *name, char *variable, unsigned int length)
{
	unsigned int var_length;
	unsigned int i;

	/* Get the length of the variable string. */

	var_length = wsh_str_len(variable);

	/* If lengths are not equal, strings can't be the same. */

	if (var_length != length)
		return (-1);

	i = 0;

	/* Compare characters until a mismatch or end of the strings. */

	while (name[i] != '\0' && variable[i] != '\0')
	{
		if (name[i] != variable[i])
			return (1); /* Unequal Strings */

		i++;
	}

	return (0); /* Strings are equal. */
}

/**
 * wsh_str_ncmp - Compares two strings up to a specified length.
 * @name: Name supplied by the user for comparison.
 * @variable: Variable to compare against.
 * @length: Length to compare up to.
 * Return: 1 if strings are equal, -1 if they are not.
 */
int wsh_str_ncmp(char *name, char *variable, unsigned int length)
{
	unsigned int i;
	i = 0;

	/* Compare characters up to the specified length. */
        while (i < length)
        {
                if (name[i] != variable[i])
                        return (-1); /* Strings are not equal. */
                i++;
        }
        return (1); /* Strings are equal. */
}

/**
 * wsh_str_cpy - Copies the string from src to dest buffer.
 * @dest: String destination.
 * @src: String source.
 * Return: Pointer to dest.
 */
char *wsh_str_cpy(char *dest, char *src)
{
	int i;
	int j = wsh_str_len(src);

	/* Copy characters from src to dest. */
	for (i = 0; i <= j; i++)
                dest[i] = src[i];
        return (dest);
}

/**
 * wsh_str_len - Returns the length of the input string.
 * @s: String to be evaluated.
 * Return: Length of the string.
 */
int wsh_str_len(char *s)
{
        int i = 0;

	/* Count characters until the null terminator is encountered. */

	while (s[i] != '\0')
		i++;

	return (i);
}
