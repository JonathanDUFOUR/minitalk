/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 23:00:26 by jodufour          #+#    #+#             */
/*   Updated: 2021/06/23 09:23:53 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include "minitalk.h"

int	main(int ac, char **av)
{
	pid_t		server_pid;
	pid_t		client_pid;
	char const	*string;

	if (ac == 3)
	{
		printf("\n\e[33m>>> RUNNING CLIENT <<<\e[0m\n");
		printf(".-------------------------------------------.\n");
		printf("|\e[35m%20s\e[0m |\e[35m%20s\e[0m |\n", "VARIABLE", "VALUE");
		printf("|-------------------------------------------|\n");
		server_pid = mt_atopid(av[2]);
		client_pid = getpid();
		string = av[1];
		printf("|%20s |%20d |\n", "server_pid", server_pid);
		printf("|-------------------------------------------|\n");
		printf("|%20s |%20d |\n", "client_pid", client_pid);
		printf("|-------------------------------------------|\n");
		printf("|%20s |%20s |\n", "string", string);
		printf("'-------------------------------------------'\n");
		printf("\n");
		kill(server_pid, SIGUSR1);
	}
	return (0);
}
