/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 00:13:25 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/09 17:46:30 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdint.h>
# include <stdbool.h>

# define USLEEP_TIME	128
# define BUFFER_SIZE	4096

int		mt_strlen(char const *str);

bool	mt_isdigit(char const c);
bool	mt_isspace(char const c);

void	mt_bzero(void *addr, size_t n);
void	mt_listen(void);
void	mt_putpid(__pid_t pid);
void	mt_quit(int sig);
void	mt_talk(void);

__pid_t	mt_atopid(char const *str) __attribute__((nonnull));

#endif
