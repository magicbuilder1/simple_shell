#include "shell_main.h"

/**
 * *_strcpy - copies the string pointed to by src,
 * including the terminating null byte (\0),
 * to the buffer pointed to by dest.
 *
 * @dest: a pointer to the destisnation string
 * @src: a pointer to the source string
 *
 * Return: a pointer to the destination string
 */
char *_strcpy(char *dest, char *src)
{
	int i, n = 0;

	while (src[n])
		n++;

	for (i = 0; i < n && src[i]; i++)
		dest[i] = src[i];

	dest[i] = '\0';
	return (dest);
}
