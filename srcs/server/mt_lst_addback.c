/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_lst_addback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 23:38:01 by jodufour          #+#    #+#             */
/*   Updated: 2021/06/28 02:27:48 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <signal.h>
#include "minitalk.h"
#include "t_lst.h"

int	mt_lst_addback(pid_t clt_pid)
{
	t_clt	*new;

	new = malloc(sizeof(t_clt));
	if (!new)
		return (MALLOC_ERRNO);
	mt_bzero(new->buff, BUFF_SIZE);
	new->i = 0;
	new->pid = clt_pid;
	new->next = NULL;
	if (lst()->tail)
		((t_clt *)lst()->tail)->next = new;
	else
	{
		lst()->head = new;
		lst()->tail = new;
	}
	lst()->tail = new;
	++lst()->size;
	return (SUCCESS);
}
