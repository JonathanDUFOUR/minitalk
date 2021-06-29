/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_clt.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 09:29:29 by jodufour          #+#    #+#             */
/*   Updated: 2021/06/28 07:03:49 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_CLT_H
# define T_CLT_H

# include <signal.h>

# define BUFF_SIZE 1024

typedef struct s_clt	t_clt;

struct s_clt
{
	char	buff[BUFF_SIZE];
	int		i;
	pid_t	pid;
	t_clt	*next;
};

t_clt	*mt_get_clt(pid_t clt_pid);

#endif
