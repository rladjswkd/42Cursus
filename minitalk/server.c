/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:28:22 by gyepark           #+#    #+#             */
/*   Updated: 2022/02/19 21:00:30 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "minitalk.h"

void	sig_handler(int sig)
{
	/*
	static unsigned char	byte = 0;
	static int				bits = 0;

	byte <<= 1;
	if (sig == SIGUSR1)
		byte |= 1;
	if (++bits == 8)
	{
		write(1, &byte, 1);
		bits = 0;
		byte = 0;
	}
	*/
	char	c;

	if (sig == SIGUSR1)
	{
		c = 49;
		write(1, &c, 1);
	}
	else if (sig == SIGUSR2)
	{
		c = 50;
		write(1, &c, 1);
	}
}

int	main(void)
{
	struct sigaction	sigact;

	printf("Server's pid is %d\n", getpid());
	sigact.sa_handler = &sig_handler;
	sigact.sa_flags = SA_NODEFER;
	sigact.sa_flags |= SA_RESETHAND;
	sigemptyset(&sigact.sa_mask);
	if (sigaction(SIGUSR1, &sigact, (struct sigaction *)0) < 0)
	{
		write(STDERR_FILENO, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	if (sigaction(SIGUSR2, &sigact, (struct sigaction *)0) < 0)
	{
		write(STDERR_FILENO, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	while (1)
	{
	}
	return (0);
}
