#include "../minihell.h"

int	check_top_commands(char *l);

//should return first node or null
t_cmd	parse_cmd(t_data *data, char *line)
{
	t_cmd	node = {0};
	(void) data;

	check_top_commands(line);
	// parse line
	return (node);
}

//TODO better name
int	check_top_commands(char *l)
{
	// NOTE Also check there is only cd/exit on the line
	// if (!get_token) return (0);

	// TODO Change l[] = ' ' to ft_isspace
	if (!ft_strncmp("cd", l, 2) && (l[2] == ' ' || l[2] == '\0'))
	{
		ft_printf("call cd\n");
		return (1);
	}
	else if (!ft_strncmp("exit", l, 4) && (l[4] == ' ' || l[4] == '\0'))
	{
		ft_printf("exit: |%s|\n", l);
		//CLEAN memory
		//exit(EXIT_SUCCESS);
	}
	return (0);
}

//TODO move func to another file
char	*expand_var(char *var)
{
	char	*str;

	(void) var;
	//TODO expand envp var
	str = ft_calloc(1, 1);
	/* str = malloc(35); */
	/* str = "Please expand this variable xx\0"; */
	return (str);
}
