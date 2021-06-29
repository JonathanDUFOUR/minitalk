/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 23:00:26 by jodufour          #+#    #+#             */
/*   Updated: 2021/06/28 07:26:22 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "minitalk.h"
#include "t_data.h"

static void	mt_data_init(char const *av1, char const *av2)
{
	data()->srv_pid = mt_atopid(av1);
	data()->clt_pid = getpid();
	data()->s = (char *)av2;
	data()->len = mt_strlen(data()->s);
}

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		write(1, "\n\e[33m>>> RUNNING CLIENT <<<\e[0m\n", 34);
		mt_data_init(av[1], av[2]);
		mt_putdata();
		mt_talk();
	}
	else
	{
		write(1, "\e[31mError:\n\e[0m", 17);
		write(1, "\e[33mUsage: ./client <server_pid> <string>\e[0m\n", 48);
	}
	return (0);
}
