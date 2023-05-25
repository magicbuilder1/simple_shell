#include "shell_main.h"

/**
 * _cmd_filter - filters a user entry command in the PATH
 *
 * @cmd: value to be filtered in the PATH
 *
 * Return: 1 if the command was successfully filtered,
 * 0 if the command couldn't be filtered,
 * -1 if an error occured
 */
int _cmd_filter(char **cmd)
{
	char *token = NULL, *path_cmd = NULL,
		 *path_data = _getenv("PATH"), *path_copy = NULL;
	unsigned int cmd_full_len, cmd_len = _get_strlen(*cmd);

	if ((*cmd[0] != '/' && *cmd[0] != '.') && path_data == NULL)
		return (0);

	if (access(*cmd, F_OK) == 0)
		return (1);

	path_copy = _strdup(path_data);

	if (!path_copy)
		return (-1);

	token = strtok(path_copy, ":");
	while (token)
	{
		cmd_full_len = _get_strlen(token) + cmd_len + 1;
		path_cmd = malloc(sizeof(char) * cmd_full_len + 1);
		if (!path_cmd)
			return (-1);
		_strcpy(path_cmd, token);
		_strcat(path_cmd, "/");
		_strcat(path_cmd, *cmd);

		if (access(path_cmd, F_OK) == 0)
		{
			free(*cmd);
			*cmd = path_cmd;
			free(path_copy);
			return (1);
		}
		token = strtok(NULL, ":");
		free(path_cmd);
	}

	free(path_copy);
	return (0);
}

/**
 * _free_tokens - frees space allocated for each token
 * and the whole array of token itself
 *
 * @tokens: tokens to be freed
 *
 * Return: nothing
 */
void _free_tokens(char **tokens)
{
	size_t i = 0;

	if (!tokens)
		return;

	while (tokens[i])
		free(tokens[i++]);

	free(tokens);
}
