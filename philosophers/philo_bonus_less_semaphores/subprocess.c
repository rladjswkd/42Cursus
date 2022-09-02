/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subprocess.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 17:19:27 by gyepark           #+#    #+#             */
/*   Updated: 2022/08/15 17:19:28 by gyepark          ###   ########.kr       */
/*                                                                            */
/* ************************************************************************** */

#include <semaphore.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include "philo_semaphore.h"
#include "monitor_semaphore.h"
#include "time.h"
#include "handle.h"
#include "shared.h"
#include "constants.h"
#include "state.h"
#include "cycle.h"
#include "monitor.h"

static void	terminate_all(void)
{
	int	i;
	int	n;

	i = -1;
	n = access_args(GET).n_philo;
	while (++i < n)
		sem_post(access_flag_sem(GET));
	while (i--)
		sem_wait(access_finish_sem(GET));
}

static void	*routine_checker(void *param)
{
	synchronize_start_time();
	while (1)
	{
		if (check_if_died())
		{
			sem_wait(access_died_sem(GET));
			if (*access_n_eat(GET) > PHILO_DIED)
			{
				print_state(*((int *)param), STR_DIED, DEAD);
				terminate_all();
				sem_post(access_rights_sem(GET));
				sem_post(access_fork_sem(GET));
			}
			sem_post(access_died_sem(GET));
			break ;
		}
		if (check_n_eat() < 1)
		{
			sem_post(access_flag_sem(GET));
			break ;
		}
	}
	return (0);
}

static void	*routine_terminator(void *param)
{
	(void)param;
	sem_wait(access_flag_sem(GET));
	set_n_eat(PHILO_DIED);
	sem_post(access_finish_sem(GET));
	sem_post(access_flag_sem(GET));
	return (0);
}

void	func_philo(int idx)
{
	pthread_t	primary_monitor;
	pthread_t	secondary_monitor;

	if (pthread_create(&primary_monitor, 0, &routine_checker, &idx))
		return ;
	if (pthread_create(&secondary_monitor, 0, &routine_terminator, 0))
		return ;
	synchronize_start_time();
	if (idx & 1)
		usleep_splitted(access_args(GET).time_eat / 2);
	while (check_n_eat() > PHILO_DONE)
		philo_cycle(idx);
	pthread_join(primary_monitor, 0);
	pthread_join(secondary_monitor, 0);
}
