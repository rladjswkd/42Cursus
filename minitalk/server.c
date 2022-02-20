/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:28:22 by gyepark           #+#    #+#             */
/*   Updated: 2022/02/19 22:47:32 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "minitalk.h"

void	sig_handler(int sig)
{
	static char	byte = 0;
	static int		bit = 0;

	if (sig == SIGUSR1)
		byte |= 1 << bit;
	if (++bit == 8)
	{
		write(1, &byte, 1);
		bit = 0;
		byte = 0;
	}
}

int	main(void)
{
	struct sigaction	sigact;

	printf("Server's pid is %d\n", getpid());
	sigact.sa_handler = &sig_handler;
	sigact.sa_flags = SA_RESTART;
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
		if (pause() != -1)
			break ;
	return (0);
}
