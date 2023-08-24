#include "shell.h"
	int 
main(void)
{		
	int i = 0;
	char *lide = NULL;
	char *command = NULL;
	char **argumentz = NULL;
	char *line_cypy = NULL;
	int interactive = isatty(STDIN_FILENO);

	while (1)
	{
		if (interactive)
		{
			display_prompt();
		}
		lide = read_command();

		if (lide == NULL)
		{
			break;
		}
		line_cypy = strdup(lide);
		command = strtok(line_cypy, " \t\n");

		if (command != NULL)
		{
			argumentz = pased_argumentz(lide);

			if (strcmp(command, "exit") == 0)
			{
				while (argumentz[i])
				{
					free(argumentz[i]);
					i++;
				}
				free(argumentz);
				free(lide);
				free(line_cypy);
				return (0);
			}
			else if (strcmp(command, "ls") == 0)
			{
				char command_path[] = "/bin/ls";

				execute_command(command_path, argumentz, &lide);
			}
			else if (strcmp(command, "env") == 0)
			{
				print_environment();
			}
			else
			{
				execute_command(command, argumentz, &lide);
			}
			i = 0;
			while (argumentz[i])
			{
				free(argumentz[i]);
				i++;
			}
			free(argumentz);
		}
		free(lide);
		free(line_cypy);
	}
	return (0);
}
