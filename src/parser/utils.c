#include "../minihell.h"

char	*next_space(char *l)
{
	while (!ft_isspace(*l))
		l++;
	return (l);
}

char	*next_cset(char *l, char *set)
{
	int	i;
	int	set_sz;
	int	found;

	set_sz = ft_strlen(set);
	found = 0;
	while (l)
	{
		i = -1;
		while (++i < set_sz)
		{
			if (*l == set[i])
			{
				found = 1;
				break ;
			}
		}
		l++;
	}
	if (found)
		return (l);
	else
		return (0);
}
