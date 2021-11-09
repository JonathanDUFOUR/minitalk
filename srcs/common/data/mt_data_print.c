/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_data_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 16:02:33 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/09 17:41:23 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "colors.h"
#include "minitalk.h"
#include "type/t_data.h"

void	mt_data_print(void)
{
	t_data *const	data = mt_data_get();

	write(1, "-----------------------------------------\n", 42);
	write(1, "      "MAGENTA"VARIABLE"RESET"     |       "\
	MAGENTA"VALUE"RESET"        \n", 59);
	write(1, "-----------------------------------------\n", 42);
	write(1, "     server_pid    |       ", 27);
	mt_putpid(data->srv_pid);
	write(1, "\n", 1);
	write(1, "-----------------------------------------\n", 42);
	if (data->clt_pid >= 0)
	{
		write(1, "     client_pid    |       ", 27);
		mt_putpid(data->clt_pid);
		write(1, "\n", 1);
		write(1, "-----------------------------------------\n", 42);
	}
	write(1, "\n", 1);
}
