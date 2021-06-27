/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 21:26:00 by jodufour          #+#    #+#             */
/*   Updated: 2021/06/25 21:29:44 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdint.h>

void	mt_bzero(void *s, size_t n)
{
	register char	*p;

	if (!s)
		return ;
	p = s;
	while (n >= sizeof(uint64_t))
	{
		*((uint64_t *)p) = 0;
		p += sizeof(uint64_t);
		n -= sizeof(uint64_t);
	}
	if (n >= sizeof(uint32_t))
	{
		*((uint32_t *)p) = 0;
		p += sizeof(uint32_t);
		n -= sizeof(uint32_t);
	}
	if (n >= sizeof(uint16_t))
	{
		*((uint16_t *)p) = 0;
		p += sizeof(uint16_t);
		n -= sizeof(uint16_t);
	}
	if (n)
		*p = 0;
}
