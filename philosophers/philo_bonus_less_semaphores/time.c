/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 23:27:14 by gyepark           #+#    #+#             */
/*   Updated: 2022/08/10 23:27:15 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <unistd.h>
#include "constants.h"
#include "monitor.h"

struct timeval	access_init_time(int flag)
{
	static struct timeval	init;

	if (flag)
		gettimeofday(&init, (struct timezone *)0);
	return (init);
}

static int	convert_to_ms(struct timeval t)
{
	return (t.tv_sec * 1000 + t.tv_usec / 1000);
}

static struct timeval	get_time_now(void)
{
	struct timeval	t;

	gettimeofday(&t, (struct timezone *)0);
	return (t);
}

int	get_init_interval(void)
{
	return (convert_to_ms(get_time_now())
		- convert_to_ms(access_init_time(GET)));
}

void	usleep_splitted(int time)
{
	int	bound;
	int	usec;
	int	current;

	if (check_n_eat() < 1)
		return ;
	bound = convert_to_ms(get_time_now()) + time;
	usec = time * WEIGHT;
	while (1)
	{
		current = convert_to_ms(get_time_now());
		if (current >= bound)
			return ;
		if (bound - current <= usec)
			usec /= 2;
		usleep(usec);
	}
}
