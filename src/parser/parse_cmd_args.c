#include "../minihell.h"

static char	*get_next_arg(char **l, char *el);
static char	*single_quote(char **l, char *el, char **head, char *r);
static char	*double_quote(char **l, char *el, char **head, char *r);
static char *dollar_sign(char **l, char *el, char **head, char *r);

// l should be the start of the cmd with the program name, el pointer to its end, before o token or etc
char	**parse_cmd_args(char *l, char *el)
{
	char	**args;
	int		i;

	i = count_args(l, el);
	if (i < 0)
		return (NULL); // NOTE this is an error on parsing maybe we should just exit here
	args = malloc(sizeof(char *) * (i + 1));
	ft_printf("args count [%d]\n", i);
	args[i] = NULL;
	i = -1;
	while (*l && l <= el)
	{
		if (ft_isspace(*l))
			l++;
		else
			args[++i] = get_next_arg(&l, el);
	}
	// NOTE when a $ expands to nothing it dosent counts as argc, maybe we need to check if args has an empty entry and push evering else
	return (args);
}

static char	*get_next_arg(char **l, char *el)
{
	char	*head;
	char	*r;

	head = *l;
	r = ft_calloc(1, 1);
	while (*l && *l <= el)
	{
		if ((ft_isspace(**l) || *l == el) && head != *l)
		{
			head = ft_strjoin(r, ft_substr(head, 0, *l - head));
			free(r);
			return (head);
		}
		if (**l == '\'')
			r = single_quote(l, el, &head, r);
		if (**l == '\"')
			r = double_quote(l, el, &head, r);
		if (**l == '$')
			r = dollar_sign(l, el, &head, r);
		if (ft_isspace(**l) || *l == el)
			break ;
		if (**l != '$' && **l != '\"' && **l != '\'' && !ft_isspace(**l))
			(*l)++;
	}
	return (r);
}

static char	*single_quote(char **l, char *el, char **head, char *r)
{
	char	*tmp;

	if (*head != *l)
	{
		tmp = ft_strjoin(r, ft_substr(*head, 0, *l - *head));
		free(r);
		r = tmp;
	}
	(*l)++;
	*head = *l;
	while (*l && *l <= el && **l != '\'')
		(*l)++;
	tmp = ft_strjoin(r, ft_substr(*head, 0, *l - *head));
	free(r);
	(*l)++;
	*head = *l;
	return (tmp);
}

static char	*double_quote(char **l, char *el, char **head, char *r)
{
	char	*tmp;

	if (*head != *l)
	{
		tmp = ft_strjoin(r, ft_substr(*head, 0, *l - *head));
		free(r);
		r = tmp;
	}
	(*l)++;
	*head = *l;
	while (*l && *l <= el && **l != '\"')
	{
		if (**l == '$')
			r = dollar_sign(l, el, head, r);
		(*l)++;
	}
	tmp = ft_strjoin(r, ft_substr(*head, 0, *l - *head));
	free(r);
	(*l)++;
	*head = *l;
	return (tmp);
}

static char	*dollar_sign(char **l, char *el, char **head, char *r)
{
	char	*tmp;
	char	*tmp2;

	if (*head != *l)
	{
		tmp = ft_strjoin(r, ft_substr(*head, 0, *l - *head));
		free(r);
		r = tmp;
		tmp = NULL;
	}
	(*l)++;
	*head = *l;
	//NOTE Check what more bash shell parameter expansion dosent allow as name
	while (*l && *l <= el && **l != '\"' && **l != '\'' && !ft_isspace(**l))
		(*l)++;
	if (*head == *l)
		return (r);
	tmp2 = ft_substr(*head, 0, *l - *head);
	tmp = ft_strjoin(r, expand_var(tmp2));
	free (tmp2);
	free (r);
	*head = *l;
	return (tmp);
}
