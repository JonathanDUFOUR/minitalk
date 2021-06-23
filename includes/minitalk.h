/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 00:13:25 by jodufour          #+#    #+#             */
/*   Updated: 2021/06/23 11:04:58 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdint.h>
# include <stdbool.h>

bool	mt_isdigit(char const c);
bool	mt_isspace(char const c);

void	mt_listen(int sig);
void	mt_putbyte(uint8_t byte);

pid_t	mt_atopid(char const *s) __attribute__((nonnull));

#endif
