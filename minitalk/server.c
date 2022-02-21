/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:28:22 by gyepark           #+#    #+#             */
/*   Updated: 2022/02/21 11:24:45 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_handler(int sig, siginfo_t *info, void *ucontext)
{
	static char	byte = 0;
	static int	bit = 0;

	(void)ucontext;
	byte |= (sig == SIGUSR1) << bit;
	if (++bit == 8)
	{
		if (!byte)
		{
			if (kill(info->si_pid, SIGUSR2) < 0)
				exit_on_error();
			bit = 0;
			byte = 0;
			return ;
		}
		write(1, &byte, 1);
		bit = 0;
		byte = 0;
	}
	if (kill(info->si_pid, SIGUSR1) < 0)
		exit_on_error();
}

int	main(void)
{
	struct sigaction	sigact;

	write(1, "Server's pid is ", 16);
	putnbr_fd_minitalk(getpid(), 1);
	write(1, "\n", 1);
	sigact.sa_sigaction = &sig_handler;
	sigact.sa_flags = SA_SIGINFO;
	sigemptyset(&sigact.sa_mask);
	if (sigaction(SIGUSR1, &sigact, (struct sigaction *)0) < 0)
		exit_on_error();
	if (sigaction(SIGUSR2, &sigact, (struct sigaction *)0) < 0)
		exit_on_error();
	while (1)
		pause();
	return (0);
}
