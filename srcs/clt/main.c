/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 23:00:26 by jodufour          #+#    #+#             */
/*   Updated: 2021/06/23 11:16:40 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include "minitalk.h"

static void	print_data(pid_t server_pid, pid_t client_pid, char const *string)
{
	printf("\n\e[33m>>> RUNNING CLIENT <<<\e[0m\n");
	printf(".-------------------------------------------.\n");
	printf("|\e[35m%20s\e[0m |\e[35m%20s\e[0m |\n", "VARIABLE", "VALUE");
	printf("|-------------------------------------------|\n");
	printf("|%20s |%20d |\n", "server_pid", server_pid);
	printf("|-------------------------------------------|\n");
	printf("|%20s |%20d |\n", "client_pid", client_pid);
	printf("|-------------------------------------------|\n");
	printf("|%20s |%20s |\n", "string", string);
	printf("'-------------------------------------------'\n");
	printf("\n");
}

int	main(int ac, char **av)
{
	pid_t		server_pid;
	pid_t		client_pid;
	char const	*string;
	int			sig;
	int			i;

	if (ac == 3)
	{
		server_pid = mt_atopid(av[2]);
		client_pid = getpid();
		string = av[1];
		print_data(server_pid, client_pid, string);
		while (*string)
		{
			i = -1;
			while (++i < 8)
			{
				if (*string & (1 << i))
					sig = SIGUSR1;
				else
					sig = SIGUSR2;
				kill(server_pid, sig);
				sleep(1);
				printf("Sent %d\n", sig);
			}
			printf("*string -> '%c' -> ", *string);
			mt_putbyte(*string);
			puts("");
			++string;
		}
	}
	return (0);
}
