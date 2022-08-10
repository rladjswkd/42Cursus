/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutexes.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 23:27:03 by gyepark           #+#    #+#             */
/*   Updated: 2022/08/10 23:27:04 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTEXES_H
# define MUTEXES_H
# include <pthread.h>

pthread_mutex_t	*access_fork_mutex(pthread_mutex_t *initializer, int index);
pthread_mutex_t	*access_rights_mutex(pthread_mutex_t *initializer);
pthread_mutex_t	*access_last_eat_mutex(pthread_mutex_t *initializer, int idx);
pthread_mutex_t	*access_n_eat_mutex(pthread_mutex_t *initializer, int idx);
pthread_mutex_t	*access_flag_mutex(pthread_mutex_t *initializer);
#endif
