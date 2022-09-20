#include "minihell.h"

static void	shell_loop(t_data *data);

int	main(int argc, char *argv[], char *envp[])
{
	t_data	data;

	(void) argv;
	(void) envp;

	for (int i=0; i < argc;i++)
		ft_printf("%s\n", argv[i]);
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

static void test_parse(char *line);

static void	shell_loop(t_data *data)
{
	char	*line;

	while (1)
	{
		//pwd(1, NULL);
		//NOTE prompt
		line = readline("minishell >");
		add_history(line);
		ft_printf("line count: %d | line: %s\n", count_args(line, line + ft_strlen(line)), line);
		test_parse(line);
		//ft_printf("line[0]: %c line[strlen]: %c\n", line[0], line[ft_strlen(line) - 1]);
		parse_cmd(data, line);
		//Exec tree
		free(line);
	}
}

static void test_parse(char *line)
{
	char **args;
	int		i;

	ft_printf("Testing parse_cmd_args with line\n");
	ft_printf("--------------------------------\n");
	i = 0;
	args = parse_cmd_args(line, line + ft_strlen(line));
	if (!args)
	{
		ft_printf("Error on parsing\n");
		return ;
	}
	ft_printf("args:\n");
	while (args[i])
	{
		ft_printf("\t%s\n", args[i]);
		i++;
	}
	ft_printf("--------------------------------\n");
	free_2darray(args);
}
