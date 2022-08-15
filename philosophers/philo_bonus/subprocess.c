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
#include "time.h"
#include "handle.h"
#include "shared.h"
#include "constants.h"
#include "state.h"
#include "cycle.h"

static int	check_if_died(void)
{
	return (get_init_interval() - get_last_eat() > access_args(GET).time_die);
}

static int	check_if_done(void)
{
	int	flag;

	sem_wait(access_n_eat_sem(GET));
	flag = *access_n_eat(GET);
	sem_post(access_n_eat_sem(GET));
	return (flag < 1);
}

static void	synchronize_start_time(void)
{
	while (get_init_interval() < 0)
		usleep(SYNC_USEC);
}

static void	*monitor_subprocess(void *param)
{
	synchronize_start_time();
	while (1)
	{
		if (check_if_died())
		{
			print_state(*((int *)param), STR_DIED, DEAD);
			sem_post(access_flag_sem(GET));
			pthread_detach(access_monitor_thread(GET));
			sem_wait(access_rights_sem(GET));
		}
		if (check_if_done())
		{
			pthread_detach(access_monitor_thread(GET));
			exit(EXIT_SUCCESS);
		}
	}
	return (0);
}

void	func_philo(int idx)
{
	pthread_t	sub_monitor;

	if (pthread_create(&sub_monitor, 0, &monitor_subprocess, &idx))
		sem_post(access_flag_sem(GET));
	access_monitor_thread(sub_monitor);
	synchronize_start_time();
	if (idx & 1)
		usleep_splitted(access_args(GET).time_eat / 2);
	while (1)
		philo_cycle(idx);
}
