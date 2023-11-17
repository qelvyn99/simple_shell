#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stddef.h>
#include <sys/wait.h>

extern char **environ;
#define MAX_INPUT_LEN 1024

/* String functions*/
int strlen_function(const char *str);
int strcmp_function(char *str1, char *str2);
char *strdup_function(const char *str);
char *strcpy_function(char *dest, const char *source);
char *strncpy_function(char *dest, const char *source, int num);
int strncmp_function(const char *str1, const char *str2, size_t num);
char *stmstr_function(char *str);


/* Other functions*/
void error(char *command);
void print_env(void);
void cd_function(char *path);
int exec_cmd(char *command_with_args);
void exec_cp(char *command, char *args[]);
void builtins(char *input);
void prompt(void);
char *find_path(char *command);


#endif
