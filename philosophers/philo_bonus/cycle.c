/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 17:18:57 by gyepark           #+#    #+#             */
/*   Updated: 2022/08/15 17:18:58 by gyepark          ###   ########.kr       */
/*                                                                            */
/* ************************************************************************** */

#include <semaphore.h>
#include <unistd.h>
#include "philo_semaphore.h"
#include "handle.h"
#include "constants.h"
#include "state.h"
#include "shared.h"
#include "time.h"

static void	philo_pickup(int idx)
{
	sem_wait(access_fork_sem(GET));
	print_state(idx, STR_FORK, ALIVE);
}

static void	philo_eat_sleep(int idx, int time, int flag)
{
	if (flag == EAT)
	{
		print_state(idx, STR_EAT, ALIVE);
		sem_wait(access_last_eat_sem(GET));
		*access_last_eat(GET) = get_init_interval();
		sem_post(access_last_eat_sem(GET));
		sem_wait(access_n_eat_sem(GET));
		(*access_n_eat(GET))--;
		sem_post(access_n_eat_sem(GET));
	}
	else
		print_state(idx, STR_SLEEP, ALIVE);
	usleep_splitted(time);
}

static void	philo_putdown(void)
{
	sem_post(access_fork_sem(GET));
}

static void	philo_think(int idx)
{
	print_state(idx, STR_THINK, ALIVE);
	usleep(SYNC_USEC);
}

void	philo_cycle(int idx)
{
	philo_pickup(idx);
	philo_pickup(idx);
	philo_eat_sleep(idx, access_args(GET).time_eat, EAT);
	philo_putdown();
	philo_putdown();
	philo_eat_sleep(idx, access_args(GET).time_sleep, SLEEP);
	philo_think(idx);
}
