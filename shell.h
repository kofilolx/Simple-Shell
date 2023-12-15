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

/*----------------Function Prototype | Shell Main-------------------------*/
int main(int argc, char **argv, char **env);
int wsh_process(char **arg, char **av, char **env, char *line_ptr, int p_id, int check);
char *wsh_path(char **envp);
char *wsh_getline(void);
char **wsh_tokenize(char *line_ptr);
void wsh_get_environ(char **env);
int wsh_val_path(char **arg, char **env);
void cleanup(char *lines, char **bufline);
void handle__env_cmd(char **env);
void handle_cmd(char **bufline, char **arg, char **env, char *lines, int p_val);
int wsh_builtins_count(void);

/*============================= Builtins ====================*/

int wsh_cdir(char **args);
int wsh_exit(char **args);
int wsh_help(char **args);
int wsh_ctrl(char **args);

/*============================== Struct | ====================*/
/**
 * built_s - Structure representing a built-in command
 *
 * @name: The name of the built-in command.
 * @p: Pointer to the corresponding function
 * to execute for the built-in command.
 */

char *builtin_lineptr[] = {"cd", "help", "exit", "NULL"};

int (*function_built[]) (char **) = {
        &wsh_help,
        &wsh_exit,
        &wsh_ctrl,
        /* &wsh_cdir */
};

#endif /* SHELL_H */
