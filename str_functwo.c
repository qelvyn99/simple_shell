#include "shell.h"

/**
 * strdup_function - Duplicate a string.
 * @str: The string to duplicate.
 *
 * Return: A pointer to the duplicated string, or NULL if allocation fails.
 */
char *strdup_function(const char *str)
{
	char *dup; /* The duplicate string*/
	size_t len;

	if (str == NULL)
		return (NULL);

	len = strlen_function(str);
	dup = (char *)malloc(len + 1);

	if (dup == NULL)
		return (NULL);

	strcpy(dup, str);
	return (dup);
}


/**
 * strncmp_function - Compare the first n characters of two strings.
 * @str1: The first string.
 * @str2: The second string.
 * @num: The number of characters to compare.
 *
 * Return:
 *   - 0 if the first n characters of the strings are equal.
 *   - A negative value if s1 is less than s2.
 *   - A positive value if s1 is greater than s2.
 */
int strncmp_function(const char *str1, const char *str2, size_t num)
{
	while (num && *str1 && (*str1 == *str2))
	{
		str1++;
		str2++;
		num--;
	}

	if (num == 0)
		return (0);

	return (*(unsigned char *)str1 - *(unsigned char *)str2);
}
