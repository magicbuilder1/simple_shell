#include "shell_main.h"

/**
 * _calloc - allocates memory for an array, using malloc
 * and the fills the space with 0
 *
 * @nmemb: size of the array
 * @size: amount of bytes for each element of the array
 *
 * Return: a pointer to the allocated memory space
 * or  NULL if it fails
 */
void *_calloc(size_t nmemb, size_t size)
{
	size_t i;
	char *ptr = NULL;

	if (nmemb == 0  || size == 0)
		return (NULL);

	ptr = malloc(nmemb * size);

	if (ptr == NULL)
		return (NULL);

	for (i = 0; i < nmemb * size; i++)
		ptr[i] = 0;

	return (ptr);
}
