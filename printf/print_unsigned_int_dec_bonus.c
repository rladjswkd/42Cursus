/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_int_dec_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 15:40:52 by gyepark           #+#    #+#             */
/*   Updated: 2021/12/27 16:36:40 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
static int	print_left(char *str, int len, int len_pad, t_conv conv)
{
	int	res;
	int	len_str;

	conv.spec = 0;
	len_str = get_len(str);
	res = 0;
	while (len-- > len_str)
		res += put_char(48);
	res += put_str(str, len_str);
	while (len_pad-- > 0)
		res += put_char(32);
	return (res);
}

static int	print_right(char *str, int len, int len_pad, t_conv conv)
{
	int		res;
	int		len_str;
	int		is_zero;
	char	padding;

	len_str = get_len(str);
	res = 0;
	is_zero = (conv.spec & 1 << PADDING) >> PADDING
		&& !((conv.spec & 1 << PRECISION) >> PRECISION);
	padding = is_zero * 48 + !is_zero * 32;
	while (len_pad-- > 0)
		res += put_char(padding);
	while (len-- > len_str)
		res += put_char(48);
	res += put_str(str, len_str);
	return (res);
}

int	print_u(va_list *ap, const char **format, t_conv conv)
{
	char					str[11];
	int						flag;
	int						len;
	static t_func_printer	fp[2] = {print_right, print_left};
	static const char		decimal[10] = {
		48, 49, 50, 51, 52, 53, 54, 55, 56, 57};

	get_str_ui(ap, str, decimal, 10);
	str[0] -= str[0] * ((conv.spec & 1 << PRECISION) >> PRECISION
			&& !(conv.precision) && str[0] == 48);
	flag = conv.spec & 1 << PRECISION && get_len(str) < conv.precision;
	len = flag * conv.precision + !flag * get_len(str);
	(*format)++;
	return ((*fp[(conv.spec & 1 << ALIGNMENT) >> ALIGNMENT])(
		str,
		len,
		conv.field - len,
		conv));
}
