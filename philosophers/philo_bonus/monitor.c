/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 17:19:08 by gyepark           #+#    #+#             */
/*   Updated: 2022/08/15 17:19:09 by gyepark          ###   ########.kr       */
/*                                                                            */
/* ************************************************************************** */

#include <semaphore.h>
#include <stdlib.h>
#include "philo_semaphore.h"
#include "shared.h"
#include "time.h"
#include "handle.h"
#include "constants.h"
#include "state.h"

static int	check_if_died(int limit)
{
	return (get_init_interval() - get_last_eat() > limit);
}

static int	check_if_done(void)
{
	int	res;

	sem_wait(access_n_eat_sem(GET));
	res = *access_n_eat(GET) < 1;
	sem_post(access_n_eat_sem(GET));
	return (res);
}

void	monitor_threads(int idx, int limit)
{
	while (1)
	{
		if (check_if_died(limit))
		{
			print_state(idx, STR_DIED, DEAD);
			sem_post(access_flag_sem(GET)); // sem_wait in main process before philosophers being forked.
		}
		if (check_if_done())
			exit(EXIT_SUCCESS);
	}
}
