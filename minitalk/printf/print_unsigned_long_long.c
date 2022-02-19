/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_long_long.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 13:57:15 by gyepark           #+#    #+#             */
/*   Updated: 2021/12/26 23:09:22 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
static int	print_left(char *str, int len, int len_pad, t_conv conv)
{
	int	res;
	int	len_str;

	conv.spec = 0;
	len_str = get_len(str);
	res = put_str("0x", 2);
	while (len-- > len_str)
		res += put_char(48);
	res += put_str(str, len_str);
	while (len_pad-- > 0)
		res += put_char(32);
	return (res);
}

static int	print_zero_padding(char *str, int len, int len_pad, t_conv conv)
{
	int	res;
	int	len_str;

	conv.spec = 0;
	len_str = get_len(str);
	res = put_str("0x", 2);
	while (len_pad-- > 0)
		res += put_char(48);
	while (len-- > len_str)
		res += put_char(48);
	res += put_str(str, len_str);
	return (res);
}

static int	print_space_padding(char *str, int len, int len_pad, t_conv conv)
{
	int	res;
	int	len_str;

	conv.spec = 0;
	res = 0;
	len_str = get_len(str);
	while (len_pad-- > 0)
		res += put_char(32);
	res += put_str("0x", 2);
	while (len-- > len_str)
		res += put_char(48);
	res += put_str(str, len_str);
	return (res);
}

static int	print_right(char *str, int len, int len_pad, t_conv conv)
{
	static t_func_printer	fp[2] = {print_space_padding, print_zero_padding};

	return (fp[!((conv.spec & 1 << PRECISION) >> PRECISION)
			&& (conv.spec & 1 << PADDING) >> PADDING]
		(str, len, len_pad, conv));
}

int	print_p(va_list *ap, const char **format, t_conv conv)
{
	char					str[17];
	int						flag;
	int						len;
	static t_func_printer	fp[2] = {print_right, print_left};
	static const char		hexadecimal[16] = {
		48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 97, 98, 99, 100, 101, 102};

	get_str_ull(ap, str, hexadecimal, 16);
	str[0] -= str[0] * ((conv.spec & 1 << PRECISION) >> PRECISION
			&& !(conv.precision) && str[0] == 48);
	flag = conv.spec & 1 << PRECISION && get_len(str) < conv.precision;
	len = flag * conv.precision + !flag * get_len(str);
	(*format)++;
	return ((*fp[(conv.spec & 1 << ALIGNMENT) >> ALIGNMENT])(
		str,
		len,
		conv.field - 2 - len,
		conv));
}
