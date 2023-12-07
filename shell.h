#ifndef SHELL_H
#define SHELL_H


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <strings.h>


/*----------------Function Prototype | Strings----------------------------*/
char *wsh_str_cpy(char *dest, char *src);
int wsh_str_len(char *s);
int wsh_str_cmp(char *name, char *variable, unsigned int length);
int wsh_str_ncmp(char *name, char *variable, unsigned int length);

/*----------------Function Prototype | Shell Main-------------------------*/
#endif /* SHELL_H */
