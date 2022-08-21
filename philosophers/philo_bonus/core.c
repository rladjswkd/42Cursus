/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 17:18:50 by gyepark           #+#    #+#             */
/*   Updated: 2022/08/15 17:18:51 by gyepark          ###   ########.kr       */
/*                                                                            */
/* ************************************************************************** */

#include <semaphore.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include "philo_semaphore.h"
#include "monitor_semaphore.h"
#include "constants.h"
#include "shared.h"
#include "subprocess.h"
#include "time.h"
#include "handle.h"
#include "destruct.h"

static int	set_environments(pid_t **pid_list)
{
	int	n;

	n = access_args(GET).n_philo;
	*pid_list = (pid_t *)malloc(sizeof(pid_t) * n);
	if (!(*pid_list))
		return (0);
	while (n--)
	{
		sem_wait(access_flag_sem(GET, n));
		sem_wait(access_finish_sem(GET, n));
	}
	access_init_time(SET);
	access_last_eat(get_init_interval() + SYNC_TIME);
	access_n_eat(access_args(GET).n_eat);
	return (1);
}

static int	fork_and_work(int current, pid_t *pid_list)
{
	int	i;

	pid_list[current] = fork();
	if (pid_list[current] == 0)
	{
		func_philo(current);
		free(pid_list);
		destruct_all();
		exit(EXIT_SUCCESS);
	}
	else if (pid_list[current] == -1)
	{
		i = -1;
		while (++i < current)
		{
			sem_post(access_flag_sem(GET, i));
			waitpid(pid_list[i], 0, 0);
		}
		free(pid_list);
		destruct_all();
		return (0);
	}
	return (1);
}

void	manage_subprocess(void)
{
	int			i;
	int			n;
	pid_t		*pid_list;

	n = access_args(GET).n_philo;
	if (!set_environments(&pid_list))
		return ;
	i = -1;
	while (++i < n)
		if (!fork_and_work(i, pid_list))
			exit(EXIT_FAILURE);
	while (n--)
		waitpid(-1, 0, 0);
	free(pid_list);
}
