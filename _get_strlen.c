#include "shell_main.h"

/**
 * _get_strlen - measure and return the lenght of a string
 *
 * @str: the given string, null termined
 *
 * Return: the number of valid characters in the given string
 */
int _get_strlen(char *str)
{
	int len;

	for (len = 0; *str++; len++)
		;

	return (len);
}
