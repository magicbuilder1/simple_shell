#include "shell_main.h"

/**
 * main - entry point
 *
 * @ac: command line argument count
 * @av: command line argument vector
 *
 * description : reads and executes commands typed by
 * the user just as the native shell program.
 *
 * Return: always 0 (Success)
 */
int main(int ac, char **av)
{
	char *prompt = "#:user@cisfun$", *line_ptr, **tokens;
	size_t n = 0, prompt_len = 15, err_count = 1;
	ssize_t command_len;
	int is_builtin = 0, exit_status = 0;

	if (ac != 1)
		return (write(STDOUT_FILENO, "Usage [ ./hsh ]", 15), 0);

	do {
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, prompt, prompt_len);

		command_len = getline(&line_ptr, &n, stdin);

		if (command_len == EOF)
			break;
		if (*line_ptr == '\n')
			continue;

		is_builtin = _execute_builtins(line_ptr, exit_status);

		if (!is_builtin)
			continue;

		tokens = _get_tokens(av[0], line_ptr, &err_count);

		if (!tokens)
			continue;

		exit_status = _create_process(av[0], line_ptr, tokens);
	} while (1);

	free(line_ptr);
	return (0);
}
