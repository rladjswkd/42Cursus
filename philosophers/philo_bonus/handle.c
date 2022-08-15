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
#include "philo_semaphore.h"
#include "constants.h"
#include "shared.h"
#include "state.h"
#include "time.h"

int	get_last_eat(void)
{
	int	res;

	sem_wait(access_last_eat_sem(GET));
	res = *access_last_eat(GET);
	sem_post(access_last_eat_sem(GET));
	return (res);
}

void	print_state(int idx, char *str, int state)
{
	sem_wait(access_rights_sem(GET));
	printf(FORMAT, get_init_interval(), idx + 1, str);
	if (state == ALIVE)
		sem_post(access_rights_sem(GET));
}
