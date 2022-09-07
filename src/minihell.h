#ifndef MINIHELL_H
# define MINIHELL_H
# include "../libft/libft.h"
# include <errno.h>

# define PATH_MAX 1024

//Built-ins
int echo(int argc, char *argv[]);
int pwd(int argc, char *argv[]);
int cd(int argc, char *argv[]);

#endif // MINIHELL_H_
