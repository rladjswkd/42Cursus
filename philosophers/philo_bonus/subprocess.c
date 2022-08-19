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
#include "monitor.h"

static void	set_n_eat(int val)
{
	sem_wait(access_n_eat_sem(GET));
	*(access_n_eat(GET)) = val;
	sem_post(access_n_eat_sem(GET));
}

static void	*monitor_checker(void *param)
{
	synchronize_start_time();
	while (1)
	{
		if (check_if_died())
		{
			print_state(*((int *)param), STR_DIED, DEAD, get_init_interval());
			set_n_eat(0);
			sem_post(access_rights_sem(GET));
			sem_post(access_flag_sem(GET));
			sem_post(access_fork_sem(GET));
			break ;
		}
		if (check_n_eat() < 1)
			break ;
	}
	return (0);
}

static void	*monitor_terminator(void *param)
{
	(void)param;
	synchronize_start_time();
	sem_wait(access_flag_sem(GET));
	set_n_eat(0);
	sem_post(access_flag_sem(GET));
	return (0);
}

void	func_philo(int idx, pid_t *pid_list)
{
	pthread_t	primary_monitor;
	pthread_t	secondary_monitor;

	free(pid_list);
	if (pthread_create(&primary_monitor, 0, &monitor_checker, &idx))
		sem_post(access_flag_sem(GET));
	if (pthread_create(&secondary_monitor, 0, &monitor_terminator, 0))
		sem_post(access_flag_sem(GET));
	synchronize_start_time();
	if (idx & 1)
		usleep_splitted(access_args(GET).time_eat / 2);
	while (check_n_eat() > 0)
		philo_cycle(idx);
	pthread_join(primary_monitor, 0);
	pthread_join(secondary_monitor, 0);
	close_sem_all();
	exit(EXIT_SUCCESS);
}
