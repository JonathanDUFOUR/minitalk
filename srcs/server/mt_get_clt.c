/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 23:26:09 by jodufour          #+#    #+#             */
/*   Updated: 2021/06/28 04:04:32 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "t_lst.h"

t_clt	*mt_get_clt(pid_t clt_pid)
{
	t_clt	*clt;

	clt = (t_clt *)lst()->head;
	while (clt)
	{
		if (clt->pid == clt_pid)
			return (clt);
		clt = clt->next;
	}
	return (NULL);
}
