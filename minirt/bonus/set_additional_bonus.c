/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_additional_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:56:52 by gyepark           #+#    #+#             */
/*   Updated: 2022/11/11 19:56:53 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure_bonus.h"
#include "linked_list_bonus.h"
#include "set_essential_bonus.h"
#include "checker_bonus.h"
#include "converter_bonus.h"

int	set_plane(char **info, int cnt, t_world *world)
{
	t_pl	*pl;

	if (cnt != 4)
		return (0);
	pl = (t_pl *)(get_last_node(world->pl)->data);
	if (!set_coordinate(info[1], &(pl->coord)))
		return (0);
	if (!set_coordinate(info[2], &(pl->norm))
		|| !check_normal(pl->norm))
		return (0);
	if (!set_rgb(info[3], &(pl->rgb)))
		return (0);
	pl->status = 0;
	pl->longi = 0;
	pl->lati = 0;
	pl->norm_const = pl->norm;
	return (1);
}

int	set_sphere(char **info, int cnt, t_world *world)
{
	double	diameter;
	t_sp	*sp;

	if (cnt != 4)
		return (0);
	sp = (t_sp *)(get_last_node(world->sp)->data);
	if (!set_coordinate(info[1], &(sp->coord)))
		return (0);
	if (!get_double(info[2], &diameter) || diameter < 0)
		return (0);
	if (!set_rgb(info[3], &(sp->rgb)))
		return (0);
	sp->diameter = diameter;
	sp->status = 0;
	return (1);
}

int	set_cylinder(char **info, int cnt, t_world *world)
{
	double	diameter;
	double	height;
	t_cy	*cy;

	if (cnt != 6)
		return (0);
	cy = (t_cy *)(get_last_node(world->cy)->data);
	if (!set_coordinate(info[1], &(cy->coord)))
		return (0);
	if (!set_coordinate(info[2], &(cy->norm))
		|| !check_normal(cy->norm))
		return (0);
	if (!get_double(info[3], &diameter) || diameter < 0)
		return (0);
	if (!get_double(info[4], &height) || height < 0)
		return (0);
	if (!set_rgb(info[5], &(cy->rgb)))
		return (0);
	cy->lati = 0;
	cy->longi = 0;
	cy->norm_const = cy->norm;
	cy->diameter = diameter;
	cy->height = height;
	cy->status = 0;
	return (1);
}

int	set_cone(char **info, int cnt, t_world *world)
{
	double	diameter;
	double	height;
	t_cn	*cn;

	if (cnt != 6)
		return (0);
	cn = (t_cn *)(get_last_node(world->cn)->data);
	if (!set_coordinate(info[1], &(cn->coord)))
		return (0);
	if (!set_coordinate(info[2], &(cn->norm))
		|| !check_normal(cn->norm))
		return (0);
	if (!get_double(info[3], &diameter) || diameter < 0)
		return (0);
	if (!get_double(info[4], &height) || height < 0)
		return (0);
	if (!set_rgb(info[5], &(cn->rgb)))
		return (0);
	cn->lati = 0;
	cn->longi = 0;
	cn->norm_const = cn->norm;
	cn->diameter = diameter;
	cn->height = height;
	cn->status = 0;
	return (1);
}
