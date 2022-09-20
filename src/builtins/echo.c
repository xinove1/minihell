/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dienasci <dienasci@student.42sp.org.br >   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 16:22:05 by dienasci          #+#    #+#             */
/*   Updated: 2022/09/07 16:22:43 by dienasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minihell.h"

int	echo(int argc, char *argv[])
{
	char	endline;
	int		i;

	(void) argc;
	endline = '\n';
	i = 0;
	if (argv[1] && argv[1][0] == '-' && argv[1][1] == 'n' && argv[1][2] == '\0')
	{
		endline = 0;
		i++;
	}
	while (argv[++i])
	{
		write(1, argv[i], ft_strlen(argv[i]));
		if (argv[i + 1] != NULL)
			write(1, " ", 1);
	}
	if (endline)
		write(1, &endline, 1);
	return (EXIT_SUCCESS);
}
