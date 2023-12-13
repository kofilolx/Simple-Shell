#ifndef SHELL_H
#define SHELL_H
#define BUF 200


/*------------------Inclusion Guards | Headers ----------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>


/*----------------Function Prototype | Strings----------------------------
char *wsh_str_cpy(char *dest, char *src);
int wsh_str_len(char *s);
int wsh_str_cmp(char *name, char *variable, unsigned int length);
int wsh_str_ncmp(char *name, char *variable, unsigned int length);
*/

/*----------------Function Prototype | Shell Main-------------------------*/
int main(int argc, char **argv, char **env);
int wsh_process(char **arg, char **av, char **env, char *line_ptr, int p_id, int check);
char *wsh_path(char **envp);
char *wsh_getline(void);
char **wsh_tokenize(char *line_ptr);
void wsh_get_environ(char **env);
int wsh_val_path(char**arg,  char **env);


/*============================= Builtins ====================*/

/* int wsh_cdir(char **args); */
int wsh_exit(char **args);
int wsh_help(char **args);
int wsh_ctrl(char **args);


#endif /* SHELL_H */
