/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_data.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 18:13:24 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/09 07:59:18 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_DATA_H
# define T_DATA_H

# include <unistd.h>

typedef struct s_data	t_data;

struct s_data
{
	__pid_t	srv_pid;
	__pid_t	clt_pid;
	int		sig_s;
	int		sig_r;
	int		len;
	char	*str;
};

void	mt_data_init(char const *av1, char const *av2);
void	mt_data_print(void);

t_data	*mt_data_get(void);

#endif
