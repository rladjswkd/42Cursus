/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 23:56:16 by gyepark           #+#    #+#             */
/*   Updated: 2021/12/29 00:15:03 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
static int	print_left(va_list *ap, const char **format, t_conv conv)
{
	int	res;

	ap = 0;
	res = put_char(*((*format)++));
	while (conv.field-- > 1)
		res += put_char(32);
	return (res);
}

static int	print_right(va_list *ap, const char **format, t_conv conv)
{
	int		res;
	int		flag;
	char	padding;

	ap = 0;
	res = 0;
	flag = (conv.spec & 1 << PADDING) >> PADDING;
	padding = flag * 48 | !flag * 32;
	while (conv.field-- > 1)
		res += put_char(padding);
	res += put_char(*((*format)++));
	return (res);
}

int	print_format(va_list *ap, const char **format, t_conv conv)
{
	static t_func_specifier	fp[2] = {print_right, print_left};

	return ((*fp[(conv.spec & 1 << ALIGNMENT) >> ALIGNMENT])(ap, format, conv));
}
