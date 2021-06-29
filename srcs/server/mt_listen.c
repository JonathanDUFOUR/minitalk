/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_listen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 09:12:49 by jodufour          #+#    #+#             */
/*   Updated: 2021/06/28 07:12:41 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include "minitalk.h"
#include "t_lst.h"
#include "t_clt.h"

static void	mt_flush(t_clt *clt, pid_t clt_pid)
{
	write(1, clt->buff, clt->i / 8);
	mt_bzero(clt->buff, BUFF_SIZE);
	if (clt->i && !(clt->i % 8) && !clt->buff[clt->i / 8 - 1])
	{
		write(1, "\n\e[36mFrom: ", 12);
		mt_putpid(clt_pid);
		write(1, "\e[0m\n\n", 6);
		kill(clt_pid, SIGUSR1);
		mt_lst_delone(clt_pid);
	}
	else
		clt->i = 0;
}

static void	mt_takenote(int sig, siginfo_t *si, void *uctx)
{
	t_clt	*clt;
	int		ret;

	(void)uctx;
	clt = mt_get_clt(si->si_pid);
	if (!clt)
	{
		ret = mt_lst_addback(si->si_pid);
		if (ret != SUCCESS)
			mt_quit(SIGINT);
		clt = (t_clt *)lst()->tail;
	}
	if (sig == SIGUSR2)
		clt->buff[clt->i / 8] |= (1 << (clt->i % 8));
	++clt->i;
	if ((clt->i / 8) == BUFF_SIZE
		|| (clt->i && !(clt->i % 8) && !clt->buff[clt->i / 8 - 1]))
	{
		mt_flush(clt, si->si_pid);
	}
}

void	mt_listen(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = mt_takenote;
	while (1)
	{
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		signal(SIGINT, mt_quit);
		pause();
	}
}
