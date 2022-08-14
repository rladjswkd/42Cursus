/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destruct.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 23:26:53 by gyepark           #+#    #+#             */
/*   Updated: 2022/08/10 23:26:54 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DESTRUCT_H
# define DESTRUCT_H

int		destroy_mutex(pthread_mutex_t *mutexes, int error_idx);
void	free_all(pthread_t *threads, int is_error);
#endif
