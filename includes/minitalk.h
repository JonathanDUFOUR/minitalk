/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 00:13:25 by jodufour          #+#    #+#             */
/*   Updated: 2021/06/26 18:43:55 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdint.h>
# include <stdbool.h>

# define SLEEP_TIME	128

int		mt_strlen(char const *s);

bool	mt_isdigit(char const c);
bool	mt_isspace(char const c);

void	mt_bzero(void *s, size_t n);
void	mt_listen(void);
void	mt_putbyte(uint8_t byte);
void	mt_talk(void);

pid_t	mt_atopid(char const *s) __attribute__((nonnull));

#endif
