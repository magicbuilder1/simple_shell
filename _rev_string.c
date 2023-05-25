#include "shell_main.h"

/**
 * _rev_string - reverses a string.
 *
 * @str: pointer to the string to be reversed
 *
 * Return: nothing
 */
void _rev_string(char *str)
{
	int i, j = 0, len = _get_strlen(str);
	char temp;

	i = len - 1;

	while (i > j)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		j++;
		i--;
	}

}
