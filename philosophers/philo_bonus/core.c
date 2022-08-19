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
#include "constants.h"
#include "shared.h"
#include "subprocess.h"
#include "time.h"

static void	close_sem_all(void)
{
	sem_close(access_fork_sem(GET));
	sem_close(access_rights_sem(GET));
	sem_close(access_last_eat_sem(GET));
	sem_close(access_n_eat_sem(GET));
	sem_close(access_flag_sem(GET));
}

static void	set_environments(void)
{
	access_init_time(SET);
	access_last_eat(get_init_interval() + SYNC_TIME);
	access_n_eat(access_args(GET).n_eat);
}

int	manage_subprocess(void)
{
	int			i;
	int			n;
	pid_t		*pid_list;

	sem_wait(access_flag_sem(GET));
	set_environments();
	n = access_args(GET).n_philo;
	pid_list = (pid_t *)malloc(sizeof(pid_t) * n);
	if (!pid_list)
		return (0);
	i = -1;
	while (++i < n)
	{
		pid_list[i] = fork();
		if (pid_list[i] == 0) // free pid_list for child processes.
			func_philo(i);
	}
	while (n--)
		waitpid(-1, 0, 0);
	free(pid_list);
	close_sem_all();
	return (1);
}
