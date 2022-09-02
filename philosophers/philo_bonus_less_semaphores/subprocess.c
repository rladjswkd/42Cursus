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
#include "semaphore.h"
#include "time.h"
#include "handle.h"
#include "shared.h"
#include "constants.h"
#include "state.h"
#include "cycle.h"
#include "monitor.h"

static void	*routine_checker(void *param)
{
	synchronize_start_time();
	while (1)
	{
		if (check_if_died())
		{
			print_state(*((int *)param), STR_DIED, DEAD);
			sem_post(access_flag_sem(GET));			
			break ;
		}
		if (check_n_eat() < 1)
			break ;
	}
	return (0);
}

void	func_philo(int idx)
{
	pthread_t	primary_monitor;

	if (pthread_create(&primary_monitor, 0, &routine_checker, &idx))
		return ;
	synchronize_start_time();
	if (idx & 1)
		usleep_splitted(access_args(GET).time_eat / 2);
	while (check_n_eat() > 0)
		philo_cycle(idx);
	pthread_join(primary_monitor, 0);
}
