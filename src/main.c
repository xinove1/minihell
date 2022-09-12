#include "minihell.h"

static void	shell_loop(t_data *data);
void	parse_cmd(t_data *data, char *line);

int	main(int argc, char *argv[], char *envp[])
{
	t_data	data;

	(void) argv;
	(void) envp;
	if (argc > 1)
	{
		ft_putstr_fd("Error\nMinishell does not accept any arguments. Please check the README.\n", 2);
		exit(1);
	}

	// TODO init data
	// TODO parse envp, hash table maybe?
	// TODO setup signals

	shell_loop(&data);
	return (0);
}

static void	shell_loop(t_data *data)
{
	char	*line;

	while (1)
	{
		pwd(1, NULL);
		//NOTE prompt
		line = readline("minishell >");
		add_history(line);
		parse_cmd(data, line);
		//Exec tree
		free(line);
	}
}

//should return first node or null
void	parse_cmd(t_data *data, char *line)
{
	(void) data;

	// NOTE Also check there is only cd/exit on the line
	// cd/exit followed by newline should work too
	if (!ft_strncmp("cd ", line, 3))
	{
		cd(2, (char *[2]){"cd", line + 3});
		return ;
	}
	else if (!ft_strncmp("exit ", line, 5))
	{
		//CLEAN memory
		exit(EXIT_SUCCESS);
	}
	// parse line
	// return node
}
