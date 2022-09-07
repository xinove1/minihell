/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dienasci <dienasci@student.42sp.org.br >   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 16:22:25 by dienasci          #+#    #+#             */
/*   Updated: 2022/09/07 16:22:26 by dienasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minihell.h"

extern int errno;

int pwd(int argc, char *argv[])
{
	char	*buff;
	int		mult;

	(void)argc;
	(void)argv;
	mult = 1;
	buff = ft_calloc(4096 * mult, sizeof(char));
	getcwd(buff, 4096 * mult);
	while(errno == ERANGE)
	{
		free(buff);
		mult++;
		buff = ft_calloc(4096 * mult, sizeof(char));
		getcwd(buff, 4096 * mult);
	}
	write(1, buff, 4096 * mult);
	write(1, "\n", 1);
	free(buff);
	return 0;
}
