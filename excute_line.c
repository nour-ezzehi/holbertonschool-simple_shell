#include "simple_shell.h"

/**
 * execute_line - the function to use execve while executing the line
 * @tokens: the vector with the whole input
 * @path: the command's full path
 * Return: status
 */

void execute_line(char **tokens, char *path)
{
	int status;
	pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		perror("Fork failed");
		exit(1);
	}
	if (pid == 0)
	{
		status = execve(path, tokens, environ);
		perror("execve failed");
		exit(2);
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
			status = WEXITSTATUS(status);
	}
}
