/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_lst_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 02:45:51 by jodufour          #+#    #+#             */
/*   Updated: 2021/06/28 02:50:13 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_lst.h"

void	mt_lst_clear(void)
{
	t_clt	*next;

	while (lst()->head)
	{
		next = ((t_clt *)lst()->head)->next;
		mt_lst_delone(((t_clt *)lst()->head)->pid);
		lst()->head = next;
	}
	lst()->head = NULL;
	lst()->tail = NULL;
	lst()->size = 0;
}
