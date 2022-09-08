#include "minihell.h"

int main(int argc, char *argv[])
{
	//TODO deal with user passing args to minishell
	(void) argc;
	(void) argv;

	char *line;
	while (1)
	{
		line = readline("minishell >");
		add_history(line);
		free(line);
	}
	return (0);
}
