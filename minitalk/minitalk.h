/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 21:00:05 by gyepark           #+#    #+#             */
/*   Updated: 2022/02/21 19:52:38 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <sys/types.h>
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

int		atoi_minitalk(const char *str, int *ptr);
void	putnbr_fd_minitalk(int n, int fd);
void	exit_on_error(void);
#endif
