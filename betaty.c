#include "shell.h"
/**
 *display_prompt - symbol $ the print
 */
void display_prompt(void)
{
	fprintf(stdout, "$ ");
	fflush(stdout);
}

#define MAX_ARGUMENTS 64

/**
 *read_command - you can read command  write for the user and look it
 *Return: NULL or LINE
 */
char *read_command()
{
	char *line = NULL;
	size_t bufsize = 0;
	ssize_t characters_read = getline(&line, &bufsize, stdin);

	if (characters_read == -1)
	{
		free(line);
		return (NULL);
	}
	line[strcspn(line, "\n")] = '\0';

	return (line);
}
