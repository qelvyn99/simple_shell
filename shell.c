#include "shell.h"

void prompt(void);

/**
 * main - Entry point of the shell program.
 * Return: Always returns 0.
 */
int main(void)
{
	char *path, *input = NULL;
	size_t input_size = 0;
	ssize_t read_size;
	int loop;
	int result;

	loop = 1;
	while (loop)
	{
		if (isatty(STDIN_FILENO) == 1)
		{
			write(STDOUT_FILENO, "cisfun$ ", 8);
			fflush(stdout);
		}
		read_size = getline(&input, &input_size, stdin);
		if (read_size == -1)
		{
			free(input);
			return (0);
		}
		if (strncmp_function(input, "alias", 5) == 0)
		{
			alias_function(stmstr_function(input + 5));
		}
		else
		{
			builtins(input);
			if (strncmp_function(input, "cd", 2) == 0)
			{
				path = stmstr_function(input + 2);
				cd_function(path);
				free(input);
				input = NULL;
				input_size = 0;

			}
			if (read_size > 1)
			{
				result = exec_cmd(stmstr_function(input));
				if (result == -1)
					break;
			}
		}
	}
	free(input);
	return (0);
}
