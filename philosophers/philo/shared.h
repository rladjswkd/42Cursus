/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 23:27:09 by gyepark           #+#    #+#             */
/*   Updated: 2022/08/10 23:27:10 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHARED_H
# define SHARED_H
# include "struct_args.h"

t_args	access_args(t_args *initializer);
int		*access_last_eat(int *initializer, int index);
int		*access_n_eat(int *initializer, int index);
int		access_flag(int initializer);
#endif
