#include "shell_main.h"

/**
 * _strcat - concatenates two strings and return a pointer
 * to the destination string
 *
 * @dest: pointer to the first (destination) string
 * @src: pointer to the second (source) string
 *
 * Return: a pointer to the resulting string @dest
 */
char *_strcat(char *dest, char *src)
{
	int d_len = 0, s_len = 0, i, j;

	while (dest[d_len] != '\0')
		d_len++;

	while (src[s_len] != '\0')
		s_len++;

	for (i = d_len, j = 0; (i < d_len + s_len) && (j < s_len); i++, j++)
		dest[i] = src[j];

	dest[i] = '\0';

	return (dest);
}
