/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 21:26:00 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/09 07:54:50 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdint.h>

void	mt_bzero(void *addr, size_t n)
{
	register void	*ptr;

	if (!addr)
		return ;
	ptr = addr;
	while (n >= sizeof(uint64_t))
	{
		*(uint64_t *)ptr = 0;
		ptr += sizeof(uint64_t);
		n -= sizeof(uint64_t);
	}
	if (n >= sizeof(uint32_t))
	{
		*(uint32_t *)ptr = 0;
		ptr += sizeof(uint32_t);
		n -= sizeof(uint32_t);
	}
	if (n >= sizeof(uint16_t))
	{
		*(uint16_t *)ptr = 0;
		ptr += sizeof(uint16_t);
		n -= sizeof(uint16_t);
	}
	if (n)
		*(uint8_t *)ptr = 0;
}
