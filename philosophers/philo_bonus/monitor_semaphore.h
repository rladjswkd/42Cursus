/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_semaphore.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 00:26:39 by gyepark           #+#    #+#             */
/*   Updated: 2022/08/21 00:26:40 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MONITOR_SEMAPHORE_H
# define MONITOR_SEMAPHORE_H
# include <semaphore.h>

sem_t	**access_flag_addr(sem_t **initializer);
sem_t	**access_finish_addr(sem_t **initializer);
sem_t	*access_flag_sem(sem_t **initializer, int index);
sem_t	*access_finish_sem(sem_t **initializer, int index);
sem_t	*access_died_sem(sem_t *initializer);
#endif
