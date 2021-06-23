/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 23:01:10 by jodufour          #+#    #+#             */
/*   Updated: 2021/06/23 09:18:56 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include "minitalk.h"

int	main(void)
{
	pid_t	server_pid;

	printf("\n\e[33m>>> RUNNING SERVER <<<\e[0m\n");
	printf(".-------------------------------------------.\n");
	printf("|\e[35m%20s\e[0m |\e[35m%20s\e[0m |\n", "VARIABLE", "VALUE");
	printf("|-------------------------------------------|\n");
	server_pid = getpid();
	printf("|%20s |%20d |\n", "server_pid", server_pid);
	printf("'-------------------------------------------'\n");
	printf("\n");
	signal(SIGUSR1, mt_listen);
	signal(SIGUSR2, mt_listen);
	pause();
	return (0);
}
