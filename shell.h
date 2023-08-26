#ifndef SHELL_H
#define SHELL_H

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 64

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

void execute_command(char *command, char **arguments, char **line);
void print_environment(void);
char *find_executable_path(const char *command, const char *path);
char *get_recreated_env(const char *name);
ssize_t get_line(char **lineptr, size_t *n, FILE *stream);
extern char **environ;
void display_prompt(void);
char *read_command();
char **parsed_arguments(char *line);

#endif
