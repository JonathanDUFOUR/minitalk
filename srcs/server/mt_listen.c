/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_listen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 09:12:49 by jodufour          #+#    #+#             */
/*   Updated: 2022/10/06 18:42:43 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"
#include "minitalk.h"
#include "type/t_sig.h"
#include "enum/e_ret.h"

static void	flush(char *buff, int *i, __pid_t client_pid)
{
	write(1, buff, *i / 8);
	mt_bzero(buff, BUFFER_SIZE);
	if (*i && !(*i % 8) && !buff[*i / 8 - 1])
	{
		write(1, "\n"CYAN_FG"From: ", 12);
		mt_putpid(client_pid);
		write(1, RESET"\n\n", 6);
		kill(client_pid, SIGUSR1);
	}
	*i = 0;
}

static void	takenote(int sig, siginfo_t *si, void *uctx)
{
	static char	buff[BUFFER_SIZE] = {0};
	static int	i = 0;

	(void)uctx;
	if (sig == SIGUSR2)
		buff[i / 8] |= (1 << (i % 8));
	++i;
	if ((i / 8) == BUFFER_SIZE || (i && !(i % 8) && !buff[i / 8 - 1]))
		flush(buff, &i, si->si_pid);
}

void	mt_listen(void)
{
	t_sig	sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = takenote;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	signal(SIGINT, mt_quit);
	while (1)
		pause();
}
