/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphore.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 17:19:14 by gyepark           #+#    #+#             */
/*   Updated: 2022/08/15 17:19:15 by gyepark          ###   ########.kr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_SEMAPHORE_H
# define PHILO_SEMAPHORE_H
# include <semaphore.h>

sem_t	*access_fork_sem(sem_t *initializer);
sem_t	*access_rights_sem(sem_t *initializer);
sem_t	*access_last_eat_sem(sem_t *initializer);
sem_t	*access_n_eat_sem(sem_t *initializer);
#endif
