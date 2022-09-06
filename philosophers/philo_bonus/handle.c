/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 17:19:01 by gyepark           #+#    #+#             */
/*   Updated: 2022/08/15 17:19:03 by gyepark          ###   ########.kr       */
/*                                                                            */
/* ************************************************************************** */

#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>
#include "philo_semaphore.h"
#include "monitor_semaphore.h"
#include "constants.h"
#include "shared.h"
#include "state.h"
#include "time.h"
#include "monitor.h"

int	get_last_eat(void)
{
	int	res;

	sem_wait(access_last_eat_sem(GET));
	res = *access_last_eat(GET);
	sem_post(access_last_eat_sem(GET));
	return (res);
}

void	set_n_eat(int val)
{
	sem_wait(access_n_eat_sem(GET));
	*(access_n_eat(GET)) = val;
	sem_post(access_n_eat_sem(GET));
}

void	synchronize_start_time(void)
{
	while (get_init_interval() < SYNC_TIME)
		usleep(SYNC_USEC);
}

void	print_state(int idx, char *str, int state)
{
	sem_wait(access_rights_sem(GET));
	printf(FORMAT, get_init_interval() - SYNC_TIME, idx + 1, str);
	if (state == ALIVE)
		sem_post(access_rights_sem(GET));
}

void	close_sem_all(void)
{
	int	i;
	int	n;

	sem_close(access_fork_sem(GET));
	sem_close(access_rights_sem(GET));
	sem_close(access_last_eat_sem(GET));
	sem_close(access_n_eat_sem(GET));
	sem_close(access_died_sem(GET));
	i = -1;
	n = access_args(GET).n_philo;
	while (++i < n)
	{
		sem_close(access_flag_sem(GET, i));
		sem_close(access_finish_sem(GET, i));
	}
}
