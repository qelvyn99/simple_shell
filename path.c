#include "shell.h"

void arg(void);
/**
 * find_path - Get the full path of a command.
 * @command: The command for which to find the full path.
 * Return: the full path or NULL.
 */
char *find_path(char *command)
{
	char *token;
	char *path;
	char *full_path;
	char *command_copy;
	char *path_env = getenv("PATH");

	if (path_env == NULL || command == NULL)
	{
		fprintf(stderr, "Invalid input\n");
		return (NULL);
	}


	command_copy = strdup(command);
	if (command_copy == NULL)
	{
		perror("strdup");
		return (NULL);
	}

	token = strtok(path_env, ":");

	while (token != NULL)
	{
		path = strdup(token);
		if (path == NULL)
		{
			perror("strdup");
			free(command_copy);
			return (NULL);
		}

		full_path = malloc(strlen(path) + strlen(command_copy) + 2);
		if (full_path == NULL)
		{
			perror("malloc");
			free(command_copy);
			free(path);
			return (NULL);
		}

		sprintf(full_path, "%s/%s", path, command_copy);

		if (access(full_path, X_OK) == 0)
		{
			free(command_copy);
			free(path);
			return (full_path);
		}

		free(path);
		free(full_path);

		token = strtok(NULL, ":");
	}

	free(command_copy);

	return (NULL);
}
