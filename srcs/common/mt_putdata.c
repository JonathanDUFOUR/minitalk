/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_putdata.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 16:02:33 by jodufour          #+#    #+#             */
/*   Updated: 2021/06/28 08:04:06 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include "minitalk.h"
#include "t_data.h"

void	mt_putdata(void)
{
	write(1, "-----------------------------------------\n", 43);
	write(1, "      \e[35mVARIABLE\e[0m     |       \e[35mVALUE\e[0m        \n", 60);
	write(1, "-----------------------------------------\n", 43);
	write(1, "     server_pid    |       ", 28);
	mt_putpid(data()->srv_pid);
	write(1, "\n", 1);
	write(1, "-----------------------------------------\n", 43);
	if (data()->clt_pid >= 0)
	{
		write(1, "     client_pid    |       ", 28);
		mt_putpid(data()->clt_pid);
		write(1, "\n", 1);
		write(1, "-----------------------------------------\n", 43);
	}
	write(1, "\n", 1);
}
