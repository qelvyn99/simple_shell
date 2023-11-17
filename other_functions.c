#include "shell.h"

/**
 * error - print error message
 * @command: the command
 * this is to print the erro message
*/
void error(char *command)
{
	char *error_message;
	char *error_message2;

	error_message = "Command '";
	write(STDERR_FILENO, error_message, strlen_function(error_message));
	write(STDERR_FILENO, command, strlen_function(command));
	error_message2 = "' not found\n";
	write(STDERR_FILENO, error_message2, strlen_function(error_message2));
	exit(EXIT_FAILURE);

}


/**
 * exec_cp - Execute a command in a child process with full path.
 * @command: The command to execute.
 * @args: The arguments for the command.
 */
void exec_cp(char *command, char *args[])
{
	char *path = find_path(command);

	if (path == NULL)
	{
		if (access(command, X_OK) == 0)
		{
			path = command;
		}
		else
		{
			error(command);
			_exit(EXIT_FAILURE);
		}
	}

	if (execve(path, args, NULL) == -1)
	{
		perror("execve");
	}

	free(path);

	_exit(EXIT_FAILURE);
}

/**
 * print_env - Print all environment variables.
 *
 * This function prints all environment variables along with their values.
 */
void print_env(void)
{
	char **env;

	if (environ == NULL)
	{
		write(STDOUT_FILENO, "Environment variables are not set.\n", 36);
		return;
	}

	for (env = environ; *env != NULL; env++)
	{
		write(STDOUT_FILENO, *env, strlen_function(*env));
		write(STDOUT_FILENO, "\n", 1);
	}
}

/**
 * exec_cmd - Execute a command
 * @cmd_args: The command with its arguments.
 * Return: 0 on success, -1 on failure.
 */
int exec_cmd(char *cmd_args)
{
	pid_t child_pid;
	int status;
	char *token, *args[MAX_INPUT_LEN / 2 + 2];
	int arg_count = 0;
	const char *delimiters = NULL;

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("fork");
		return (-1);
	}

	if (child_pid == 0)
	{
		delimiters = " \n\t\r\a";
		token = strtok(cmd_args, delimiters);

		while (token != NULL && arg_count < MAX_INPUT_LEN / 2 + 1)
		{
			args[arg_count++] = token;
			token = strtok(NULL, delimiters);
		}

		args[arg_count] = NULL;

		exec_cp(args[0], args);
	}
	else
	{
		wait(&status);
	}

	return (0);
}
