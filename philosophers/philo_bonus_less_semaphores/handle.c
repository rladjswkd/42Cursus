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
#include "semaphore.h"
#include "constants.h"
#include "shared.h"
#include "state.h"
#include "time.h"

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

int	close_sem_all(void)
{
	sem_close(access_fork_sem(GET));
	sem_close(access_rights_sem(GET));
	sem_close(access_last_eat_sem(GET));
	sem_close(access_n_eat_sem(GET));
	sem_close(access_flag_sem(GET));
	return (0);
}
