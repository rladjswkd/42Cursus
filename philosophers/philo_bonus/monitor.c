/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 23:26:59 by gyepark           #+#    #+#             */
/*   Updated: 2022/08/10 23:27:00 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mutexes.h"
#include "time.h"
#include "shared.h"
#include "state.h"
#include "handle.h"
#include "constants.h"

static int	check_if_died(int idx, int limit)
{
	int	now;

	now = get_init_interval();
	if (now - get_last_eat(idx) > limit)
	{
		set_flag();
		print_state(idx, STR_DIED, DEAD);
		return (1);
	}
	return (0);
}

static int	check_if_done(int idx)
{
	int	res;

	pthread_mutex_lock(access_n_eat_mutex(GET, idx));
	res = *access_n_eat(GET, idx);
	pthread_mutex_unlock(access_n_eat_mutex(GET, idx));
	return (res < 1);
}

void	monitor_threads(int n, int limit)
{
	int	i;
	int	done_cnt;

	while (1)
	{
		done_cnt = 0;
		i = -1;
		while (++i < n)
		{
			if (check_if_died(i, limit))
				return ;
			if (check_if_done(i))
				done_cnt++;
		}
		if (done_cnt == access_args(GET).n_philo)
		{
			set_flag();
			return ;
		}
	}
}
