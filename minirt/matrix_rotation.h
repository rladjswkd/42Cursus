/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_rotation.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:59:03 by gyepark           #+#    #+#             */
/*   Updated: 2022/11/11 19:59:04 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_ROTATION_H
# define MATRIX_ROTATION_H
# include "structure.h"

t_mat	mat_rx(double cosine, double sine);
t_mat	mat_ry(double cosine, double sine);
t_mat	mat_rz(double cosine, double sine);
#endif
