#include "simple_shell.h"

/**
 * main - our shell
 * Return: 0
*/

int main(void)
{
	char *readline = NULL, **tokens = NULL, *path = NULL;

	signal(SIGINT, sig_handler);
	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("$ ");
		readline = read_line();
		if (strcmp("env\n", readline) == 0)
		{
			free(readline);
			_env();
			continue;
		}
		if (strcmp(readline, "exit\n") == 0)
		{
			free(readline);
			exit(0);
		}
		tokens = parse_the_line(readline, TOK_DELIM);
		if (*tokens == NULL)
		{
			free_d_p(tokens);
			continue;
		}
		path = check_path(*tokens);
		if (!path)
		{
			perror("command not found");
			free_d_p(tokens);
			continue;
		}
		else if (path)
		{
			execute_line(tokens, path);
			free(path);
		}
		free_d_p(tokens);
		fflush(stdin);
	}

	return (0);
}
