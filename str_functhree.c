#include "shell.h"

/**
 * strcpy_function - Copy the contents of the source string
 * to the destination string.
 * @dest: The destination string.
 * @source: The source string.
 *
 * Return: A pointer to the destination string.
 */
char *strcpy_function(char *dest, const char *source)
{
	char *orig_dest;

	if (dest == NULL || source == NULL)
		return (NULL);

	orig_dest = dest;

	while ((*dest++ = *source++))
		;

	return (orig_dest);
}


/**
 * strncpy_function - Copy up to n characters from source to destination.
 * @dest: The destination string.
 * @source: The source string.
 * @num: The maximum number of characters to copy.
 *
 * Return: A pointer to the destination string.
 */
char *strncpy_function(char *dest, const char *source, int num)
{
	char *orig_dest = dest;

	while (num > 0 && *source)
	{
		*dest = *source;
		dest++;
		source++;
		num--;
	}

	while (num > 0)
	{
		*dest = '\0';
		dest++;
		num--;
	}

	return (orig_dest);
}


/**
 * stmstr_function- Trim leading and trailing whitespaces from a string.
 * @str: The input string.
 *
 * Return: A pointer to the trimmed string.
 */
char *stmstr_function(char *str)
{
	char *end;

	if (str == NULL)
		return (NULL);

	while (isspace(*str))
		str++;

	if (*str == '\0')
		return (str);

	end = str + strlen(str) - 1;
	while (end > str && isspace(*end))
		end--;

	*(end + 1) = '\0';

	return (str);
}
