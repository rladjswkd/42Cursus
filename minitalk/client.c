/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:28:27 by gyepark           #+#    #+#             */
/*   Updated: 2022/02/20 16:28:48 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <time.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	pid_t	server;
	int	bit_counter;

	if (!(argc == 3 && atoi_minitalk(argv[1], (int *)(&server))))
		exit(EXIT_FAILURE);
	clock_t t = clock();
	while (*(argv[2]))
	{
		bit_counter = 0;
		while (bit_counter++ < 8)
		{
			if (1 & (*(argv[2])))
			{
				if (kill(server, SIGUSR1) < 0)
					exit_on_error();
			}
			else
			{
				if (kill(server, SIGUSR2) < 0)
					exit_on_error();
			}
			*(argv[2]) >>= 1;
			usleep(100);
		}
		argv[2]++;
	}
	clock_t f = clock();
	printf("%lf\n", (double)(f - t)/CLOCKS_PER_SEC);
	return (0);
}
