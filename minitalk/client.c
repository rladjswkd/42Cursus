/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:28:27 by gyepark           #+#    #+#             */
/*   Updated: 2022/02/19 21:10:02 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (!(argc == 3 && atoi_minitalk(argv[1], (int *)(&pid))))
		exit(EXIT_FAILURE);
	kill(pid, SIGINT);
	return (0);
}
