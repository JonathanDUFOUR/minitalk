/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_ctx.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 09:29:29 by jodufour          #+#    #+#             */
/*   Updated: 2021/06/23 09:38:02 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_CTX_H
# define T_CTX_H

typedef struct s_ctx	t_ctx;

struct s_ctx
{
	char	*s;
};

t_ctx	*mt_get_ctx(void);

#endif
