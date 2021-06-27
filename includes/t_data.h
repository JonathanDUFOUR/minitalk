/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_data.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 18:13:24 by jodufour          #+#    #+#             */
/*   Updated: 2021/06/25 21:07:58 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_DATA_H
# define T_DATA_H

# include <signal.h>

typedef struct s_data	t_data;

struct s_data
{
	pid_t	srv_pid;
	pid_t	clt_pid;
	int		sig_s;
	int		sig_r;
	int		len;
	char	*s;
};

void	mt_putdata(void);

t_data	*data(void);

#endif
