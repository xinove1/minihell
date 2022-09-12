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
	int		index;

	//NOTE echo does not seem to exit with error when no args are given, confirm
	if (argc == 1)
		return (EXIT_FAILURE);
	endline = '\n';
	index = 0;
	if (ft_strncmp("-n", argv[1], 2) == 0)
	{
		endline = 0;
		index++;
	}
	while (argv[++index])
	{
		write(1, argv[index], ft_strlen(argv[index]));
		if (argv[index + 1] != NULL)
			write(1, " ", 1);
	}
	if (endline)
		write(1, &endline, 1);
	return (EXIT_SUCCESS);
}
