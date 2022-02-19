/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:28:22 by gyepark           #+#    #+#             */
/*   Updated: 2022/02/18 22:44:00 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

void	sig_handler(int sig)
{
	static unsigned char	byte;
	static int				bits = 0;

	if (sig == SIGUSR1)
	{
		byte <<= 1;
		byte |= 1;
		bits++;
	}
	else if (sig == SIGUSR2)
	{
		byte <<= 1;
		bits++;
	}
	if (bits == 8)
	{
		write(1, &byte, 1);
		bits = 0;
		byte = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	printf("Server's pid is %d\n", getpid());
	sa.sa_handler = &sig_handler;
	sa.sa_flags = SA_NODEFER;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, (struct sigaction *)0) < 0)
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	if (sigaction(SIGUSR2, &sa, (struct sigaction *)0) < 0)
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	while (1)
		pause();
	return (0);
}
