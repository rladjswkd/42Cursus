/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 23:27:05 by gyepark           #+#    #+#             */
/*   Updated: 2022/08/10 23:27:06 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "constants.h"
#include "shared.h"
#include "time.h"
#include "cycle.h"

static void	synchronize_start_time(void)
{
	while (get_init_interval() < 0)
		usleep(SYNC_USEC);
}

void	*routine(void *param)
{
	int		idx;
	int		fork1;
	int		fork2;

	synchronize_start_time();
	idx = *((int *)param);
	fork1 = idx;
	fork2 = (idx + 1) % access_args(GET).n_philo;
	if (idx & 1)
		usleep_splitted(access_args(GET).time_eat / 2);
	while (philo_cycle(fork1, fork2, idx))
		continue ;
	return (0);
}
