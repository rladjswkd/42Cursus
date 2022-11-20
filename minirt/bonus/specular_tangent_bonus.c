/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specular_tangent_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:57:04 by gyepark           #+#    #+#             */
/*   Updated: 2022/11/11 19:57:05 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure_bonus.h"
#include "constant_bonus.h"
#include "vector_operation_bonus.h"
#include "uv_mapper_bonus.h"
#include <math.h>

static t_vec	get_tangent_norm_sp(t_sp *sp, t_coord p, t_vec ray_dir)
{
	t_vec	n;

	n = vec_sub(p, sp->coord);
	if (vec_dot(ray_dir, n) > 0)
		return (vec_normalize(vec_sub(sp->coord, p)));
	return (vec_normalize(n));
}

static t_vec	get_tangent_norm_cy(t_cy *cy, t_coord p, t_vec ray_dir)
{
	double	a;
	double	b;
	t_coord	t_c;

	a = vec_dot(p, cy->norm);
	b = vec_dot(vec_add(cy->coord, vec_scale(cy->norm, cy->height)), cy->norm);
	if (fabs(a - b) < 1e-6)
	{
		if (vec_dot(ray_dir, cy->norm) > 0)
			return (vec_scale(cy->norm, -1));
		return (cy->norm);
	}
	b = vec_dot(cy->coord, cy->norm);
	if (fabs(a - b) < 1e-6)
	{
		if (vec_dot(ray_dir, cy->norm) > 0)
			return (vec_scale(cy->norm, -1));
		return (cy->norm);
	}
	t_c = vec_add(cy->coord, vec_scale(cy->norm, fabs(a - b)));
	if (vec_dot(ray_dir, vec_sub(p, t_c)) > 0)
		return (vec_normalize(vec_sub(t_c, p)));
	return (vec_normalize(vec_sub(p, t_c)));
}

static t_vec	get_tangent_norm_pl(t_pl *pl, t_vec ray_dir)
{
	if (vec_dot(ray_dir, pl->norm) > 0)
		return (vec_scale(pl->norm, -1));
	return (pl->norm);
}

static t_vec	get_tangent_norm_cn(t_cn *cn, t_coord p, t_vec ray_dir)
{
	double	a;
	double	b;
	t_vec	ret;

	a = vec_dot(p, cn->norm);
	b = vec_dot(vec_add(cn->coord, vec_scale(cn->norm, cn->height)), cn->norm);
	if (fabs(a - b) < 1e-6)
	{
		if (vec_dot(ray_dir, cn->norm) > 0)
			return (vec_scale(cn->norm, -1));
		return (cn->norm);
	}
	b = vec_dot(cn->coord, cn->norm);
	if (fabs(a - b) < 1e-6)
	{
		if (vec_dot(ray_dir, cn->norm) > 0)
			return (vec_scale(cn->norm, -1));
		return (cn->norm);
	}
	ret = get_cone_body_norm(p, *cn);
	if (vec_dot(ray_dir, ret) > 0)
		return (vec_scale(ret, -1));
	return (ret);
}

t_vec	get_tangent_norm(t_obj obj, t_coord p, t_vec ray_dir)
{
	t_vec	n;

	n = (t_vec){0, 0, 0};
	if (obj.type == SPHERE)
		n = get_tangent_norm_sp(obj.object, p, ray_dir);
	else if (obj.type == CYLINDER)
		n = get_tangent_norm_cy(obj.object, p, ray_dir);
	else if (obj.type == PLANE)
		n = get_tangent_norm_pl(obj.object, ray_dir);
	else if (obj.type == CONE)
		n = get_tangent_norm_cn(obj.object, p, ray_dir);
	return (n);
}
