/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 17:19:08 by gyepark           #+#    #+#             */
/*   Updated: 2022/08/15 17:19:09 by gyepark          ###   ########.kr       */
/*                                                                            */
/* ************************************************************************** */

#include <semaphore.h>
#include <stdlib.h>
#include "semaphore.h"
#include "shared.h"
#include "time.h"
#include "handle.h"
#include "constants.h"
#include "state.h"

int	check_if_died(void)
{
	return (get_init_interval() - get_last_eat() > access_args(GET).time_die);
}

int	check_n_eat(void)
{
	int	res;

	sem_wait(access_n_eat_sem(GET));
	res = *access_n_eat(GET);
	sem_post(access_n_eat_sem(GET));
	return (res);
}
