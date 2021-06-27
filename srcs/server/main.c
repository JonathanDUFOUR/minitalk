/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 23:01:10 by jodufour          #+#    #+#             */
/*   Updated: 2021/06/25 21:08:09 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include "minitalk.h"
#include "t_data.h"
#include "t_sig.h"

int	main(void)
{
	printf("\n\e[33m>>> RUNNING SERVER <<<\e[0m\n");
	data()->srv_pid = getpid();
	mt_putdata();
	mt_listen();
	return (0);
}
