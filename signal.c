#include "simple_shell.h"

/**
 * sig_handler - handler of cntr c
 * @signum: int
*/


void sig_handler(int signum)
{

	if (signum == SIGINT)
	{
		write(STDOUT_FILENO, "\n$ ", 3);
	}
}
