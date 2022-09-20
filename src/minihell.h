#ifndef MINIHELL_H
# define MINIHELL_H
# include "../libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <errno.h>

// LIMITS
# define PATH_MAX 1024

typedef enum e_cmd_types {EXEC, PIPE, REDIR}	t_cmd_types;

// Structs
typedef struct s_cmd
{
	t_cmd_types	type;
}	t_cmd;

typedef struct s_execcmd
{
	t_cmd_types	type;
	int			builtin;
	char		*exec;
	char		**args;
}	t_execcmd;

typedef struct s_pipecmd
{
	t_cmd_types	type;
	t_cmd		*left;
	t_cmd		*right;
}	t_pipecmd;

typedef struct s_redircmd
{
	t_cmd_types	type;
	t_cmd		*cmd;
	char		*file;
	int			mode;
	int			fd;
}	t_redircmd;

typedef struct s_doccmd
{
	t_cmd_types	type;
	t_cmd		*cmd;
	char		*eof;
}	t_doccmd;

typedef struct s_data
{
	// envp in whatever format
	// pointer to first node for freeing later
	// current node?
	// Exit code from last node?
}	t_data;

//Built-ins
int	echo(int argc, char *argv[]);
int	pwd(int argc, char *argv[]);
int	cd(int argc, char *argv[]);

//Parsing
t_cmd	parse_cmd(t_data *data, char *line);
int	count_args(char *l, char *el);
char	**parse_cmd_args(char *l, char *el);
char	*expand_var(char *var);

//Extra
void	free_2darray(char **array);

#endif // MINIHELL_H_
