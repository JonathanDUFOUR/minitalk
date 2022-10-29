/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 23:00:26 by jodufour          #+#    #+#             */
/*   Updated: 2022/10/06 18:41:47 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"
#include "minitalk.h"
#include "type/t_data.h"

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		write(1, "\n"YELLOW_FG">>> RUNNING CLIENT <<<"RESET"\n", 33);
		mt_data_init(av[1], av[2]);
		mt_data_print();
		mt_talk();
	}
	else
	{
		write(1, RED_FG"Error:"RESET"\n", 16);
		write(1, YELLOW_FG"Usage: ./client <server_pid> <string>"RESET"\n", 47);
	}
	return (0);
}
