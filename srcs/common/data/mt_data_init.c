/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_data_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 17:13:31 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/09 08:05:40 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "type/t_data.h"

void	mt_data_init(char const *av1, char const *av2)
{
	t_data *const	data = mt_data_get();

	data->srv_pid = mt_atopid(av1);
	data->clt_pid = getpid();
	data->str = (char *)av2;
	data->len = mt_strlen(data->str);
}
