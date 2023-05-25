#include "shell_main.h"

/**
 * _notfound_error_mess - prints an error if a command does not exist
 *
 * @program_name: program Name executing
 * @cmd: name of the notfound command to be printed
 * @err_count: number of error occurred in runtime
 *
 * Return: nothing
 */
void _notfound_error_mess(char *program_name, char *cmd, size_t *err_count)
{
	char *num = NULL, *error_msg = NULL;
	size_t len;

	num = malloc(sizeof(char) * _get_digit_count(*err_count) + 1);
	if (!num)
		return;
	num = _itoa(*err_count, num);
	len = _get_strlen(cmd) + _get_strlen(num) + _get_strlen(program_name) + 16;

	error_msg = malloc(sizeof(char) * len + 1);
	if (!error_msg)
		return;

	_strcpy(error_msg, program_name);
	_strcat(error_msg, ": ");
	_strcat(error_msg, num);
	_strcat(error_msg, ": ");
	_strcat(error_msg, cmd);
	_strcat(error_msg, ": not found\n");

	write(STDERR_FILENO, error_msg, len);

	(*err_count)++;
	free(num);
	free(error_msg);
}

/**
 * _print_error - prints a system error message
 *
 * @err_mess: the message to be printed
 *
 * Return: always 1 (error)
 */
int _print_error(char *err_mess)
{
	perror(err_mess);
	return (1);
}
