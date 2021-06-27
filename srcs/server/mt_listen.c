/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_listen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 09:12:49 by jodufour          #+#    #+#             */
/*   Updated: 2021/06/26 18:19:05 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include "minitalk.h"
#include "t_ctx.h"
#include "t_sig.h"

static void	mt_takenote(int sig, siginfo_t *si, void *pouic)
{
	t_ctx *const	ctx = mt_get_ctx();

	(void)sig;
	(void)pouic;
	if (si->si_signo == SIGUSR2)
		ctx->buff[ctx->i / 8] |= (1 << (ctx->i % 8));
	++ctx->i;
}

void	mt_listen(void)
{
	t_ctx *const	ctx = mt_get_ctx();
	t_sig			sa;
	int				i;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = mt_takenote;
	mt_bzero(ctx->buff, BUFF_SIZE);
	while (1)
	{
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		pause();
		i = 0;
		if ((ctx->i / 8) == BUFF_SIZE
			|| (ctx->i && !(ctx->i % 8) && !ctx->buff[ctx->i / 8 - 1]))
		{
			write(1, ctx->buff, ctx->i / 8);
			if (ctx->i && !(ctx->i % 8) && !ctx->buff[ctx->i / 8 - 1])
				write(1, "\n", 1);
			mt_bzero(ctx->buff, BUFF_SIZE);
			ctx->i = 0;
		}
	}
}
