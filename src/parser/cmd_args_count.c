#include "../minihell.h"

static int	substr(char *l, char *el);

int	count_args(char *l, char *el)
{
	int	i;
	int	count;
	int	r;

	i = 0;
	count = 0;
	while (l[i] && &l[i] < el)
	{
		if (ft_isspace(l[i]))
		{
			i++;
			continue ;
		}
		r = substr(&l[i], el);
		if (r < 0)
			return (-1);
		i = r + i;
		count++;
	}
	return (count);
}

static int	substr(char *l, char *el)
{
	int		i;
	char	mode;

	mode = 0;
	i = 0;
	while (l[i] && &l[i] < el)
	{
		if (!mode && ft_isspace(l[i]))
			break ;
		if (mode && l[i] == mode)
			mode = 0;
		else if (!mode && l[i] == '\'')
			mode = '\'';
		else if (!mode && l[i] == '\"')
			mode = '\"';
		i++;
	}
	if (mode)
		return (-1);
	return (i);
}
