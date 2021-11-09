/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_talk.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 20:50:41 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/09 08:05:06 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "colors.h"
#include "minitalk.h"
#include "type/t_data.h"

static void	mt_success(int sig)
{
	write(1, GREEN">>> MESSAGE HAS BEEN WELL RECEIVED <<<"RESET"\n\n", 49);
	exit(sig);
}

static void	mt_error(int sig)
{
	write(1, RED">>> ERROR WHILE SENDING THE MESSAGE <<<"RESET"\n\n", 50);
	exit(sig);
}

static void	mt_tell_char(char c)
{
	t_data *const	data = mt_data_get();
	int				ret;
	int				i;

	i = 0;
	while (i < 8)
	{
		if (c & (1 << i))
			data->sig_s = SIGUSR2;
		else
			data->sig_s = SIGUSR1;
		ret = kill(data->srv_pid, data->sig_s);
		if (ret == -1)
			mt_error(SIGTERM);
		usleep(USLEEP_TIME);
		++i;
	}
}

void	mt_talk(void)
{
	t_data *const	data = mt_data_get();

	signal(SIGUSR1, mt_success);
	signal(SIGUSR2, mt_error);
	while (*data->str)
		mt_tell_char(*data->str++);
	mt_tell_char(*data->str);
	pause();
}
