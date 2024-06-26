/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:57:47 by gyepark           #+#    #+#             */
/*   Updated: 2022/11/11 19:57:48 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H
# include "structure_bonus.h"

int	check_identifier(char *type);
int	check_comma_cnt(char *s);
int	check_rgb(t_rgb rgb);
int	check_normal(t_vec vec);
#endif
