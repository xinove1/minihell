/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dienasci <dienasci@student.42sp.org.br >   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 16:22:17 by dienasci          #+#    #+#             */
/*   Updated: 2022/09/07 16:25:10 by dienasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minihell.h"

int	cd(int argc, char *argv[])
{
	int	ret;

	// TODO cd without args defaults to cd "./~" (verify on bash docs)
	if (argc != 2)
		return (EXIT_FAILURE);
	ret = chdir(argv[1]);
	if (ret < 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
