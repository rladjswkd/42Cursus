/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 23:26:55 by gyepark           #+#    #+#             */
/*   Updated: 2022/08/10 23:26:56 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "mutexes.h"
#include "constants.h"
#include "shared.h"
#include "time.h"

int	is_flag_set(void)
{
	int	res;

	pthread_mutex_lock(access_flag_mutex(GET));
	res = access_flag(GET);
	pthread_mutex_unlock(access_flag_mutex(GET));
	return (res);
}

void	set_flag(void)
{
	pthread_mutex_lock(access_flag_mutex(GET));
	access_flag(SET);
	pthread_mutex_unlock(access_flag_mutex(GET));
}

int	get_last_eat(int idx)
{
	int	res;

	pthread_mutex_lock(access_last_eat_mutex(GET, idx));
	res = *access_last_eat(GET, idx);
	pthread_mutex_unlock(access_last_eat_mutex(GET, idx));
	return (res);
}

void	print_state(int idx, char *str, int state)
{
	pthread_mutex_lock(access_rights_mutex(GET));
	if (!is_flag_set() || state)
		printf(FORMAT, get_init_interval(), idx + 1, str);
	pthread_mutex_unlock(access_rights_mutex(GET));
}
