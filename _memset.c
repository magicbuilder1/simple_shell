#include "shell_main.h"

/**
 * _memset - fills memory with a constant byte
 *
 * @s: the memory address to be filled
 * @b: the value to fill the memory address with
 * @n: the number of bytes to fill
 *
 * Return: a pointer to the memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		*(s + i) = b;

	return (s);
}
