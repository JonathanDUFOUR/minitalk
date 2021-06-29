/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_quit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 02:32:40 by jodufour          #+#    #+#             */
/*   Updated: 2021/06/28 08:01:55 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "t_lst.h"

void	mt_quit(int sig)
{
	write(1, "\n\e[33m>>> SERVER SHUTDOWN <<<\e[0m\n\n", 36);
	mt_lst_clear();
	exit(sig);
}
