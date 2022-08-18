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

static void	*monitor_subprocess(void *param)
{
	synchronize_start_time();
	while (1)
	{
		if (check_if_died())
		{
			print_state(*((int *)param), STR_DIED, DEAD);
//			sem_post(access_flag_sem(GET));
//			pthread_detach(access_monitor_thread(GET));
//			sem_wait(access_rights_sem(GET));
		}
		if (check_if_done())
		{
//			pthread_detach(access_monitor_thread(GET));
//			exit(EXIT_SUCCESS);
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
