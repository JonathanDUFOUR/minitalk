/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_atopid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 00:24:43 by jodufour          #+#    #+#             */
/*   Updated: 2021/06/26 18:40:48 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

pid_t	mt_atopid(char const *s)
{
	pid_t	output;

	output = 0;
	while (mt_isspace(*s))
		++s;
	while (mt_isdigit(*s))
	{
		output *= 10;
		output += *s - '0';
		++s;
	}
	return (output);
}
