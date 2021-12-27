/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_signed_int_conv_utils.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 18:46:58 by gyepark           #+#    #+#             */
/*   Updated: 2021/12/26 19:20:46 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
static void	process_nothing(t_conv *conv, const char **format)
{
	conv = 0;
	(*format)++;
}

static void	process_plus(t_conv *conv, const char **format)
{
	conv->spec ^= conv->spec & 1 << SPACE;
	(*format)++;
}

void	process_minus(t_conv *conv, const char **format)
{
	conv->spec ^= (conv->spec & 1 << PLUS) | (conv->spec & 1 << SPACE);
	(*format)++;
}

void	process_others(t_conv *conv, const char **format)
{
	static t_func_conv	fp[2] = {process_nothing, process_plus};

	return ((*fp[(conv->spec & 1 << PLUS) >> PLUS])(conv, format));
}
