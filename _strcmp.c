#include "shell_main.h"

/**
 * _strcmp - compares two strings and returns the difference
 *
 * @str1: pointer to the first string
 * @str2: pointer to the second string
 *
 * Return: 0 if equal, signed difference between both otherwise
 */
int _strcmp(char *str1, char *str2)
{
	int i = 0;

	while ((str1[i] && str2[i]) && (str1[i] == str2[i]))
		i++;

	return (str1[i] - str2[i]);
}
