/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   construct.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 23:26:38 by gyepark           #+#    #+#             */
/*   Updated: 2022/08/10 23:26:39 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTRUCT_H
# define CONSTRUCT_H
# include <pthread.h>

int	init_mutex_all(void);
int	construct_threads(pthread_t **thread_p, int len);
int	construct_ints(int **int_p, int len);
#endif
