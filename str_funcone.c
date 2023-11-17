#include "shell.h"

/**
 * strlen_function - the length of astring.
 * @str:  the input string.
 *
 * Return: Length of string that was taken as an input
 */
int strlen_function(const char *str)
{
	int len = 0;

	while (*str)
	{
		len++;
		str++;
	}

	return (len);
}


/**
 * strcmp_function - Compare two strings.
 * @str1: The first string.
 * @str2: The second string.
 *
 * Return: int
*/
int strcmp_function(char *str1, char *str2)
{
	while (*str1 && (*str1 == *str2))
	{
		str1++;
		str2++;
	}

	return (*(unsigned char *)str1 - *(unsigned char *)str2);
}
