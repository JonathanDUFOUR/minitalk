/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_putpid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 03:14:15 by jodufour          #+#    #+#             */
/*   Updated: 2021/06/28 07:40:43 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>

void	mt_putpid(pid_t pid)
{
	char	d;

	if (pid < 0)
		return ;
	else
	{
		d = pid % 10 + '0';
		if (pid > 9)
			mt_putpid(pid / 10);
		write(1, &d, 1);
	}
}
