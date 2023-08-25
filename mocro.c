#include "shell.h"
/**
*pased_arguments - you can see that arguments are passed by function
*@line: Create a function that takes a string text as input, tokenizes it, and returns a pointer.
*Return: argumentz
*/
char **pased_arguments(char *line)
{
	char **arguments = malloc(MAX_ARGUMENTS * sizeof(char *));
	char *token = strtok(line, " \t\n");
	int arg_index = 0;
	int i;

	if (!arguments)
	{
		perror("error memory allocation");

		for (i = 0; i < arg_index; i++)
		{
			free(arguments[i]);
		}
		free(arguments);
		exit(EXIT_FAILURE);
	}
	while (token != NULL)
	{
		arguments[arg_index] = strdup(token);
		arg_index++;

		if (arg_index >= MAX_ARGUMENTS - 1)
		{
			fprintf(stderr, "too many arguments\n");

			for (i = 0; i < arg_index; i++)
			{
				free(arguments[i]);
			}
			free(arguments);
			break;
		}
		token = strtok(NULL, " \t\n");
	}
	arguments[arg_index] = NULL;
	return (arguments);
}
/**
*recreated_getenv - function that use recrates at the of the getenv command
*@name: environ name
*Return: Environ or NULL
*/
char *recreated_getenv(const char *name)
{
	int i;

	for (i = 0; environ[i] != NULL; ++i)
	{
		if (strncmp(environ[i], name, strlen(name)) == 0)
		{
			if (environ[i][strlen(name)] == '=')
			return (environ[i] + strlen(name) + 1);
		}
	}
	return (NULL);
}
