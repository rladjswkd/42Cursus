/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutexes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 23:27:02 by gyepark           #+#    #+#             */
/*   Updated: 2022/08/10 23:27:03 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>

pthread_mutex_t	*access_fork_mutex(pthread_mutex_t *initializer, int index)
{
	static pthread_mutex_t	*mutex;

	if (initializer)
		mutex = initializer;
	return (&(mutex[index]));
}

pthread_mutex_t	*access_rights_mutex(pthread_mutex_t *initializer)
{
	static pthread_mutex_t	*mutex;

	if (initializer)
		mutex = initializer;
	return (mutex);
}

pthread_mutex_t	*access_last_eat_mutex(pthread_mutex_t *initializer, int idx)
{
	static pthread_mutex_t	*mutex;

	if (initializer)
		mutex = initializer;
	return (&(mutex[idx]));
}

pthread_mutex_t	*access_n_eat_mutex(pthread_mutex_t *initializer, int idx)
{
	static pthread_mutex_t	*mutex;

	if (initializer)
		mutex = initializer;
	return (&(mutex[idx]));
}

pthread_mutex_t	*access_flag_mutex(pthread_mutex_t *initializer)
{
	static pthread_mutex_t	*mutex;

	if (initializer)
		mutex = initializer;
	return (mutex);
}
