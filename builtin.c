#include "shell.h"
/**
 * builtins - A function to check for builtins
 * @input: the command
 * return: void
*/
void builtins(char *input)
{

	size_t input_size = 0;

	if (strncmp_function(input, "exit", 4) == 0)
	{
		free(input);
		input = NULL;
		input_size = 0;
		exit(EXIT_SUCCESS);
	}
	if (strcmp_function(stmstr_function(input), "env") == 0)
	{
		print_env();
	}
(void)input_size;
}

/**
 * cd_function - Change current directory.
 * @path: The path .
 */
void cd_function(char *path)
{
	char *new_dir;

	if (!path || *path == '\0')
		path = getenv("HOME");
	else if (strcmp_function(path, "-") == 0)
		path = getenv("OLDPWD");

	if (chdir(path) != 0)
	{
		perror("chdir");
		return;
	}

	new_dir = getcwd(NULL, 0);

	if (new_dir != NULL)
	{
		setenv("PWD", new_dir, 1);
		free(new_dir);
	}
	else
	{
		perror("change directory failed");
	}
}
