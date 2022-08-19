/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 17:19:17 by gyepark           #+#    #+#             */
/*   Updated: 2022/08/15 17:19:18 by gyepark          ###   ########.kr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHARED_H
# define SHARED_H
# include <pthread.h>
# include "struct_args.h"

t_args		access_args(t_args *initializer);
int			*access_last_eat(int initializer);
int			*access_n_eat(int initializer);

#endif
