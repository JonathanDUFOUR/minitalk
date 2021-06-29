/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lst.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 21:59:03 by jodufour          #+#    #+#             */
/*   Updated: 2021/06/28 03:31:01 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_LST_H
# define T_LST_H

# include <stdbool.h>
# include <signal.h>
# include <string.h>
# include "t_clt.h"

typedef struct s_lst	t_lst;

struct s_lst
{
	void	*head;
	void	*tail;
	size_t	size;
};

int		mt_lst_addback(pid_t clt_pid);

void	mt_lst_delone(pid_t clt_pid);
void	mt_lst_clear(void);

t_lst	*lst(void);

#endif
