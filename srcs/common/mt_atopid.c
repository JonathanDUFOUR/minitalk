/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_atopid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 00:24:43 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/09 07:42:50 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

__pid_t	mt_atopid(char const *str)
{
	__pid_t	output;

	output = 0;
	while (mt_isspace(*str))
		++str;
	while (mt_isdigit(*str))
	{
		output *= 10;
		output += *str - '0';
		++str;
	}
	return (output);
}
