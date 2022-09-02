/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_semaphore.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 00:26:34 by gyepark           #+#    #+#             */
/*   Updated: 2022/08/21 00:26:35 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>

sem_t	*access_flag_sem(sem_t *initializer)
{
	static sem_t	*sem;

	if (initializer)
		sem = initializer;
	return (sem);
}

sem_t	*access_finish_sem(sem_t *initializer)
{
	static sem_t	*sem;

	if (initializer)
		sem = initializer;
	return (sem);
}

sem_t	*access_died_sem(sem_t *initializer)
{
	static sem_t	*sem;

	if (initializer)
		sem = initializer;
	return (sem);
}
