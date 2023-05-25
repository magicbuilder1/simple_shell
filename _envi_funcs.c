#include "shell_main.h"

/**
 * _print_env - prints the environment where the program
 * is run
 *
 * Return: nothing
 */
void _print_env(void)
{
	unsigned int i = 0;

	while (environ[i])
	{
		write(STDOUT_FILENO, environ[i], _get_strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}

/**
 * _getenv - gets an environment variable
 *
 * @name: the environment variable to get the value from
 *
 * Return: a pointer to the corresponding value string
 * or NULL if not found
 */
char *_getenv(const char *name)
{
	unsigned int i, j, it_exists = 1;

	for (i = 0; environ[i] != NULL; i++)
	{
		for (j = 0; environ[i][j] != '='; j++)
		{
			if (name[j] == '\0' || name[j] != environ[i][j])
			{
				it_exists = 0;
				break;
			}
		}
		if (it_exists)
			return (*(environ + i) + j + 1);

		it_exists = 1;
	}
	return (NULL);
}
