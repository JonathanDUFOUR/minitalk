/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_listen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 09:12:49 by jodufour          #+#    #+#             */
/*   Updated: 2021/06/23 09:39:30 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "minitalk.h"
#include "t_ctx.h"

void	mt_listen(int sig)
{
	t_ctx *const	ctx = mt_get_ctx();

	(void)sig;
	(void)ctx;
}
