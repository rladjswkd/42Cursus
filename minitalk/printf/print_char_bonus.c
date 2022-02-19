/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 19:38:50 by gyepark           #+#    #+#             */
/*   Updated: 2021/12/29 00:02:00 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
static int	print_left_aligned(char arg, char padding, int cnt)
{
	int	res;

	res = put_char(arg);
	while (cnt-- > 0)
		res += put_char(padding);
	return (res);
}

static int	print_right_aligned(char arg, char padding, int cnt)
{
	int	res;

	res = 0;
	while (cnt-- > 0)
		res += put_char(padding);
	res += put_char(arg);
	return (res);
}

int	print_c(va_list *ap, const char **format, t_conv conv)
{
	static t_func_char	fp[2] = {print_right_aligned, print_left_aligned};
	char				is_zero;

	(*format)++;
	is_zero = (conv.spec & 1 << PADDING) >> PADDING
		&& !(conv.spec & 1 << ALIGNMENT) >> ALIGNMENT;
	return (fp[(conv.spec & 1 << ALIGNMENT) >> ALIGNMENT](
		(char)va_arg(*ap, int),
		is_zero * 48 + !is_zero * 32,
		conv.field - 1));
}
