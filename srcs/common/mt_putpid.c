/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_putpid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 03:14:15 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/09 08:13:33 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>

void	mt_putpid(__pid_t const pid)
{
	char	digit;

	if (pid < 0)
		return ;
	else
	{
		digit = pid % 10 + '0';
		if (pid > 9)
			mt_putpid(pid / 10);
		write(1, &digit, 1);
	}
}
