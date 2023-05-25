#include "shell_main.h"

/**
 * _get_args_count - counts the number of arguments and returns it
 *
 * @str: the string which arguments are to be counted
 * @delim: the delimiter to be considered
 *
 * Return: the number of arguments or 0 if the fails
 */
size_t _get_args_count(const char *str, const char *delim)
{
	char *str_copy = NULL, *token = NULL;
	size_t count = 0;

	str_copy = _strdup(str);
	if (!str_copy)
		return (0);

	token = strtok(str_copy, delim);

	while (token)
	{
		count++;
		token = strtok(NULL, delim);
	}

	free(str_copy);
	return (count);
}

/**
 * _str_splitter - splits a long string in an array of arguments
 *
 * @str: the string to be splitted
 * @delim: the delimiter to be considered
 *
 * Return: a pointer to an array of arguments
 */
char **_str_splitter(char *str, const char *delim)
{
	char **tokens = NULL, *token = NULL;
	unsigned int i = 0, j, count;

	count = _get_args_count(str, delim);
	if (count == 0)
		return (NULL);

	tokens = _calloc(count + 1, sizeof(char *));
	if (!tokens)
		return (NULL);

	token = strtok(str, delim);

	while (token)
	{
		tokens[i] = malloc(sizeof(char) * _get_strlen(token) + 1);
		if (!tokens[i])
		{
			for (j = 0; j < i; j++)
				free(tokens[j]);
			free(tokens);
			return (NULL);
		}

		_strcpy(tokens[i++], token);

		token = strtok(NULL, delim);
	}

	return (tokens);
}

/**
 * _get_tokens - creates an array strings, which consist to
 * command arguments
 *
 * @program_name: the corresponding program
 * @buffer: the command typed by the user
 * @err_count: pointer to the number of error occured in runtime
 *
 * Return: a ointer to an array of arguments if it succeeds, NULL otherwise
 */
char **_get_tokens(char *program_name, char *buffer, size_t *err_count)
{
	char **tokens = NULL;

	tokens = _str_splitter(buffer, " \t\r\n");
	if (tokens == NULL || tokens[0] == NULL)
	{
		_free_tokens(tokens);

		return (NULL);
	}

	if (!_cmd_filter(&tokens[0]))
	{
		_notfound_error_mess(program_name, tokens[0], err_count);

		_free_tokens(tokens);

		if (!isatty(STDIN_FILENO))
		{
			free(buffer);
			exit(127);
		}

		return (NULL);
	}

	return (tokens);
}

/**
 * _create_process - creates a child process to execute a program
 *
 * @program_name: the name of the program
 * @buffer: the command typed by the user
 * @tokens: an array of arguments
 *
 * Return: exit status
 */
int _create_process(char *program_name, char *buffer, char **tokens)
{
	pid_t new_process;
	int status = 0, exit_status = 0;

	new_process = fork();

	if (new_process == EOF)
	{
		_free_tokens(tokens);
		free(buffer);
		exit(_print_error(program_name));
	}

	if (new_process == 0)
	{
		execve(tokens[0], tokens, environ);

		_free_tokens(tokens);
		free(buffer);

		exit(_print_error(program_name));
	}
	else
		wait(&status);

	_free_tokens(tokens);

	if (WIFEXITED(status))
		exit_status = WEXITSTATUS(status);

	return (exit_status);
}

/**
 * _execute_builtins - executes the builtins commandes of the shell
 *
 * @buffer: command typed by the and user
 * @exit_status: exit status of the current process
 *
 * Return: 1 if it succeeds, otherwise 0
 */
int _execute_builtins(char *buffer, int exit_status)
{
	if (!_strcmp(buffer, "exit\n"))
	{
		free(buffer);
		exit(exit_status);
	}

	if (!_strcmp(buffer, "env\n"))
	{
		_print_env();
		return (0);
	}

	return (1);
}
