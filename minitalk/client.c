/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:28:27 by gyepark           #+#    #+#             */
/*   Updated: 2022/02/21 11:05:47 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	sig_handler(int sig, siginfo_t *info, void *ucontext)
{
	static int	count;

	(void)ucontext;
	if (sig == SIGUSR1)
		count++;
	else
	{
		putnbr_fd_minitalk(count - 7, 1);
		putstr_fd_minitalk(" signals is sent to server", 1);
		putnbr_fd_minitalk(info->si_pid, 1);
		putstr_fd_minitalk("\n", 1);
	}
}

static void	send_bit(int server, int sig)
{
	if (kill(server, sig) < 0)
		exit_on_error();
}

static void	send_char(int server, char c)
{
	int	bit_counter;

	bit_counter = 0;
	while (bit_counter++ < 8)
	{
		if (1 & c)
			send_bit(server, SIGUSR1);
		else
			send_bit(server, SIGUSR2);
		c >>= 1;
		usleep(10000);
	}
}

int	main(int argc, char **argv)
{
	pid_t				server;
	struct sigaction	sigact;

	if (!(argc == 3 && atoi_minitalk(argv[1], (int *)(&server))))
		exit_on_error();
	sigact.sa_sigaction = &sig_handler;
	sigact.sa_flags = SA_SIGINFO;
	sigemptyset(&(sigact.sa_mask));
	if (sigaction(SIGUSR1, &sigact, (struct sigaction *)0) < 0)
		exit_on_error();
	if (sigaction(SIGUSR2, &sigact, (struct sigaction *)0) < 0)
		exit_on_error();
	while (*(argv[2]))
		send_char(server, *(argv[2]++));
	send_char(server, 0);
	return (0);
}
