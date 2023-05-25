#include "shell_main.h"

/**
 * _realloc - attempts to resize the memory block
 * pointed to by ptr that was previously allocated
 * with a call to malloc or calloc
 *
 * @ptr: the memory location to be extended or earase
 * @old_size: size in byte of the old allocated memory
 * @new_size: size in byte of the newly allocated memory
 *
 * Return: a pointer to the newly allocated memory
 * or NULL if the request fail
 */
void *_realloc(void *ptr, size_t old_size, size_t new_size)
{
	size_t i;
	char *new_alloc;

	if (!ptr)
		return (malloc(new_size));

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	if (old_size == new_size)
		return (ptr);

	new_alloc = malloc(new_size);

	if (!new_alloc)
		return (NULL);

	for (i = 0; ((char *)ptr)[i]; i++)
		new_alloc[i] = ((char *)ptr)[i];

	free(ptr);
	return (new_alloc);
}
