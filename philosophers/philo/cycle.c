/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 23:26:49 by gyepark           #+#    #+#             */
/*   Updated: 2022/08/10 23:26:49 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "mutexes.h"
#include "time.h"
#include "shared.h"
#include "handle.h"
#include "state.h"
#include "constants.h"

static int	philo_pickup(int fork, int idx)
{
	if (is_flag_set())
		return (0);
	pthread_mutex_lock(access_fork_mutex(GET, fork));
	print_state(idx, STR_FORK, ALIVE);
	return (1);
}

static int	philo_eat_sleep(int idx, int time, int flag)
{
	if (is_flag_set())
		return (0);
	if (flag == EAT)
	{
		print_state(idx, STR_EAT, ALIVE);
		pthread_mutex_lock(access_last_eat_mutex(GET, idx));
		*access_last_eat(GET, idx) = get_init_interval();
		pthread_mutex_unlock(access_last_eat_mutex(GET, idx));
		pthread_mutex_lock(access_n_eat_mutex(GET, idx));
		(*access_n_eat(GET, idx))--;
		pthread_mutex_unlock(access_n_eat_mutex(GET, idx));
	}
	else
		print_state(idx, STR_SLEEP, ALIVE);
	usleep_splitted(time);
	return (1);
}

static void	philo_putdown(int fork)
{
	pthread_mutex_unlock(access_fork_mutex(GET, fork));
}

static int	philo_think(int idx)
{
	if (is_flag_set())
		return (0);
	print_state(idx, STR_THINK, ALIVE);
	usleep(access_args(GET).time_eat);
	return (1);
}

int	philo_cycle(int fork1, int fork2, int idx)
{
	int	state;

	if (!philo_pickup(fork1, idx))
		return (0);
	if (fork1 == fork2 || !philo_pickup(fork2, idx))
	{
		philo_putdown(fork1);
		return (0);
	}
	state = philo_eat_sleep(idx, access_args(GET).time_eat, EAT);
	philo_putdown(fork2);
	philo_putdown(fork1);
	if (!state)
		return (0);
	if (!philo_eat_sleep(idx, access_args(GET).time_sleep, SLEEP))
		return (0);
	if (!philo_think(idx))
		return (0);
	return (1);
}
