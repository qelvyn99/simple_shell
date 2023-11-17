#include "shell.h"


/**
 * add_alias - Add a new alias to the linked list.
 * @name: The name of the alias.
 * @value: The value of the alias.
 */

void add_alias(char *name, char *value)
{
	Alias *aliases = NULL;
	Alias *new_alias = malloc(sizeof(Alias));

	if (new_alias == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	new_alias->name = strdup(name);
	new_alias->value = strdup(value);
	new_alias->next = NULL;

	new_alias->next = aliases;
	aliases = new_alias;
}

/**
 * print_aliases - Print all aliases in the linked list.
 */
void print_aliases(void)
{
	Alias *aliases = NULL;
	Alias *current = aliases;

	while (current != NULL)
	{
		printf("%s='%s'\n", current->name, current->value);
		current = current->next;
	}
}

/**
 * alias_function - Handle the 'alias' built-in command.
 * @args: The arguments passed to the alias command.
 */
void alias_function(char *args)
{
	char *token, *saveptr;
	char *name, *value;
	Alias *aliases = NULL;

	if (args == NULL || *args == '\0')
	{
		print_aliases();
		return;
	}
	token = strtok_r(args, " ", &saveptr);
	while (token != NULL)
	{
		name = strtok(token, "=");
		value = strtok(NULL, "=");
		if (name != NULL && value != NULL)
		{
			Alias *current = aliases;

			while (current != NULL)
			{
				if (strcmp(current->name, name) == 0)
				{
					free(current->value);
					current->value = strdup(value);
					break;
				}
				current = current->next;
			}
			if (current == NULL)
			{
				add_alias(name, value);
			}
		}
		token = strtok_r(NULL, " ", &saveptr);
	}
}
