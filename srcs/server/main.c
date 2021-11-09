/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 23:01:10 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/09 17:40:08 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include "colors.h"
#include "minitalk.h"
#include "type/t_data.h"

int	main(void)
{
	t_data *const	data = mt_data_get();

	write(1, "\n"YELLOW">>> RUNNING SERVER <<<"RESET"\n", 33);
	data->srv_pid = getpid();
	mt_data_print();
	mt_listen();
	return (0);
}
