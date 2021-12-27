/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_processor_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 20:42:57 by gyepark           #+#    #+#             */
/*   Updated: 2021/12/27 16:35:13 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
void	add_alignment(t_conv *conv, const char **format)
{
	format = 0;
	conv->spec |= 1 << ALIGNMENT;
}

void	add_padding(t_conv *conv, const char **format)
{
	format = 0;
	conv->spec |= 1 << PADDING;
}

void	add_sharp(t_conv *conv, const char **format)
{
	format = 0;
	conv->spec |= 1 << SHARP;
}

void	add_space(t_conv *conv, const char **format)
{
	format = 0;
	conv->spec |= 1 << SPACE;
}

void	add_plus(t_conv *conv, const char **format)
{
	format = 0;
	conv->spec |= 1 << PLUS;
}
