/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_data_get.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 18:31:40 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/08 16:57:09 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "type/t_data.h"

t_data	*mt_data_get(void)
{
	static t_data	data = {-1, -1, 0, 0, 0, NULL};

	return (&data);
}
