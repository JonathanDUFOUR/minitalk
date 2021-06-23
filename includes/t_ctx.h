/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_ctx.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 09:29:29 by jodufour          #+#    #+#             */
/*   Updated: 2021/06/23 10:39:34 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_CTX_H
# define T_CTX_H

# define BUFF_SIZE 32

typedef struct s_ctx	t_ctx;

struct s_ctx
{
	char	buff[BUFF_SIZE + 1];
	int		i;
};

t_ctx	*mt_get_ctx(void);

#endif
