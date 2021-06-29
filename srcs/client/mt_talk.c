/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_talk.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 20:50:41 by jodufour          #+#    #+#             */
/*   Updated: 2021/06/28 07:28:24 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include "minitalk.h"
#include "t_data.h"

static void	mt_success(int sig)
{
	write(1, "\e[32m>>> MESSAGE HAS BEEN WELL RECEIVED <<<\e[0m\n\n", 50);
	exit(sig);
}

static void	mt_error(int sig)
{
	write(1, "\e[31m>>> ERROR WHILE SENDING THE MESSAGE <<<\e[0m\n\n", 51);
	exit(sig);
}

static void	mt_tell_char(char c)
{
	int	ret;
	int	i;

	i = -1;
	while (++i < 8)
	{
		if (c & (1 << i))
			data()->sig_s = SIGUSR2;
		else
			data()->sig_s = SIGUSR1;
		ret = kill(data()->srv_pid, data()->sig_s);
		if (ret == -1)
			mt_error(SIGINT);
		usleep(USLEEP_TIME);
	}
}

void	mt_talk(void)
{
	signal(SIGUSR1, mt_success);
	signal(SIGUSR2, mt_error);
	while (*data()->s)
		mt_tell_char(*data()->s++);
	mt_tell_char(*data()->s);
	pause();
}
