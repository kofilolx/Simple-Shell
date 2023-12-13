#include "shell.h"

/* BUffer MACRO */
#define BUFFER 1024

/**
 * wsh_tokenize - This function turns a string into an array of tokens.
 *
 * Function description: Accepts an input string (string) entered by the user.
 * Uses the malloc function to allocate memory
 * for a token array (tokens) dynamically.
 *
 * Tokenizes the input string using the strtok function in accordance with the
 * designated separators ("\n\t\r").
 *
 * Puts every token in the array of tokens.
 * A NULL pointer marks the end of the token array,
 * signifying that there are no more tokens.
 *
 * @line_ptr: User-input character to be tokenized.
 *
 * Return: A pointer to a token array.
 */


char **wsh_tokenize(char *line_ptr)
{
	char **toks;		/* variable pointer to store the array of tokens */
	char *token;		/* variable to store tokenised string temporary */
	unsigned int itr;	/* Index variable for iteration */
	int val;
	char *delims = "\n\t\r";

	itr = 0;		/* Initializating itr to 0 */
	token = NULL;
	toks = NULL;
	val = 0;

	if (line_ptr == NULL)
	{
		return (NULL);
	}

	/* Initialization of malloc */
	toks = malloc(sizeof(char *) * BUFFER);

	/* Error handling */
	for (itr = 0; line_ptr[itr]; itr++)
	{
		if (line_ptr[itr] == ' ')
			val++;
	}

	/* Initialization of tokeninzer */
	token = strtok(line_ptr, delims);		/* Extract tokens with strtok */


	/* Iterate through the tokens and store them in the specified tok array */

	for (itr = 0; token != NULL; itr++)
	{
		toks[itr] = token;	/* Token storage */
		token = strtok(NULL, delims); /* Get the next token */
	}

	toks[itr] = NULL;			/* NUllifies the last element of the array */

	return (toks);	/* Return the pointer to the array of toks */
}
