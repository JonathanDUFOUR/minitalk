/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_quit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 02:32:40 by jodufour          #+#    #+#             */
/*   Updated: 2022/10/06 18:41:47 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "colors.h"
#include "minitalk.h"

void	mt_quit(int sig)
{
	write(1, "\n"YELLOW_FG">>> SERVER SHUTDOWN <<<"RESET"\n\n", 35);
	exit(sig);
}
