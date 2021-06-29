/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_lst_delone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 00:22:10 by jodufour          #+#    #+#             */
/*   Updated: 2021/06/28 02:22:39 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <signal.h>
#include "minitalk.h"
#include "t_lst.h"

static void	mt_clean_free(t_clt *dent)
{
	mt_bzero(dent->buff, BUFF_SIZE);
	dent->i = 0;
	dent->pid = 0;
	dent->next = NULL;
	free(dent);
	dent = NULL;
}

static void	mt_lst_delhead(void)
{
	t_clt	*dent;

	if (lst()->head == lst()->tail)
		lst()->tail = NULL;
	dent = (t_clt *)lst()->head;
	lst()->head = ((t_clt *)lst()->head)->next;
	mt_clean_free(dent);
	dent = NULL;
	--lst()->size;
}

static void	mt_lst_deltail(void)
{
	t_clt	*dent;

	dent = (t_clt *)lst()->head;
	while (dent->next != (t_clt *)lst()->tail)
		dent = dent->next;
	lst()->tail = dent;
	dent = dent->next;
	mt_clean_free(dent);
	dent = NULL;
	--lst()->size;
}

void	mt_lst_delone(pid_t clt_pid)
{
	t_clt	*clt;
	t_clt	*prev;

	if (clt_pid == ((t_clt *)lst()->head)->pid)
		mt_lst_delhead();
	else if (clt_pid == ((t_clt *)lst()->tail)->pid)
		mt_lst_deltail();
	else
	{
		prev = (t_clt *)lst()->head;
		clt = prev->next;
		while (clt != (t_clt *)lst()->tail && clt->pid != clt_pid)
		{
			prev = clt;
			clt = prev->next;
		}
		prev->next = clt->next;
		mt_clean_free(clt);
		clt = NULL;
	}
}
