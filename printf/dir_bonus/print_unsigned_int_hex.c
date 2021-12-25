/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_int_hex.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 01:22:46 by gyepark           #+#    #+#             */
/*   Updated: 2021/12/25 13:40:17 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
static int	print_left_aligned(char *str, int len, int len_pad, t_conv conv)
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

static int	print_right_aligned(char *str, int len, int len_pad, t_conv conv)
{
	int		res;
	int		len_str;
	int 	is_zero;
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

static int	print_prefixed_left(char *str, int len, int len_pad, t_conv conv)
{
	int			res;
	int			len_str;
	static char	prefix[2] = {'x', 'X'};

	len_str = get_len(str);
	res = put_char(48);
	res += put_char(prefix[(conv.spec & 1 << HEX_LARGE) >> HEX_LARGE]);
	while (len-- > len_str)
		res += put_char(48);
	res += put_str(str, len_str);
	while (len_pad-- > 0)
		res += put_char(32);
	return (res);
}

static int	print_prefixed_right(char *str, int len, int len_pad, t_conv conv)
{
	int			res;
	int			len_str;
	int		 	is_zero;
	char		padding;
	static char	prefix[2] = {'x', 'X'};

	len_str = get_len(str);
	res = 0;
	is_zero = (conv.spec & 1 << PADDING) >> PADDING
		&& !((conv.spec & 1 << PRECISION) >> PRECISION);
	padding = is_zero * 48 + !is_zero * 32;
	while (len_pad-- > 0)
		res += put_char(padding);
	res += put_char(48);
	res += put_char(prefix[(conv.spec & 1 << HEX_LARGE) >> HEX_LARGE]);
	while (len-- > len_str)
		res += put_char(48);
	res += put_str(str, len_str);
	return (res);
}

int	print_hex(va_list *ap, const char **format, t_conv conv)
{
	char					str[9];
	int						flag;
	int						len;
	static t_func_string	fp[4] = {print_right_aligned, print_left_aligned,
		print_prefixed_right, print_prefixed_left};
	static const char		hexadecimal[2][16] = {
		{48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 97, 98, 99, 100, 101, 102},
		{48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 65, 66, 67, 68, 69, 70}
	};
	get_str_ui(ap, str, hexadecimal[**format == 'X'], 16);
	flag = conv.spec & 1 << PRECISION && get_len(str) < conv.precision;
	len = flag * conv.precision + !flag * get_len(str);
	conv.spec |= ((*((*format)++) == 'X')
			&& (conv.spec & 1 << SHARP) >> SHARP) << HEX_LARGE;
	return ((*fp[((conv.spec & 1 << ALIGNMENT) >> ALIGNMENT)
		+ ((conv.spec & 1 << SHARP) >> SHARP) * 2])(
		str,
		len,
		conv.field - len - ((conv.spec & 1 << SHARP) >> 1),
		conv));
}
