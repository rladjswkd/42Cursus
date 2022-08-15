/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 23:27:15 by gyepark           #+#    #+#             */
/*   Updated: 2022/08/10 23:27:17 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIME_H
# define TIME_H
# include <sys/time.h>

struct timeval	access_init_time(int flag);
int				get_init_interval(void);
void			usleep_splitted(int time);
#endif
