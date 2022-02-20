/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:28:27 by gyepark           #+#    #+#             */
/*   Updated: 2022/02/20 21:52:52 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	sig_handler(int sig, siginfo_t *info, void *ucontext)
{
	(void)ucontext;
	putnbr_fd_minitalk(info->si_pid, 1);
	putstr_fd_minitalk(" server received signal ", 1);
	if (sig == SIGUSR1)
		putstr_fd_minitalk("SIGUSR1", 1);
	else
		putstr_fd_minitalk("SIGUSR2", 1);
	putstr_fd_minitalk("\n", 1);
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
		usleep(5500);
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
	sleep(1);
	return (0);
}
