/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_talk.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 20:50:41 by jodufour          #+#    #+#             */
/*   Updated: 2021/06/26 18:43:32 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "minitalk.h"
#include "t_data.h"

static void	mt_tell_char(char c)
{
	int	i;

	i = -1;
	while (++i < 8)
	{
		if (c & (1 << i))
			data()->sig_s = SIGUSR2;
		else
			data()->sig_s = SIGUSR1;
		kill(data()->srv_pid, data()->sig_s);
		usleep(SLEEP_TIME);
	}
}

void	mt_talk(void)
{
	while (*data()->s)
		mt_tell_char(*data()->s++);
	mt_tell_char(*data()->s);
}
