/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_listen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 09:12:49 by jodufour          #+#    #+#             */
/*   Updated: 2021/06/23 11:40:43 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include "minitalk.h"
#include "t_ctx.h"

static void	mt_flush(void)
{
	t_ctx *const	ctx = mt_get_ctx();

	printf("%s", ctx->buff);
	ctx->i = -1;
	while (++ctx->i < BUFF_SIZE)
		ctx->buff[ctx->i] = 0;
	ctx->i = 0;
}

void	mt_listen(int sig)
{
	t_ctx *const	ctx = mt_get_ctx();

	printf("Entered mt_listen()\n");
	if (ctx->i && !(ctx->i % 8) && !((ctx->i / 8) % BUFF_SIZE))
		mt_flush();
	else if (ctx->i && !(ctx->i % 8) && !(ctx->buff[ctx->i / 8]))
	{
		mt_flush();
		return ;
	}
	if (sig == SIGUSR1)
	{
		ctx->buff[ctx->i / 8] |= (1 << (ctx->i % 8));
	}
	else if (sig == SIGUSR2)
	{
		ctx->buff[ctx->i / 8] &= ~(1 << (ctx->i % 8));
	}
	++ctx->i;
	signal(SIGUSR1, mt_listen);
	signal(SIGUSR2, mt_listen);
	printf("Just before pause()\n");
	mt_putbyte(ctx->buff[ctx->i / 8]);
	pause();
}
