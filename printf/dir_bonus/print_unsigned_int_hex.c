/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_int_hex.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 01:22:46 by gyepark           #+#    #+#             */
/*   Updated: 2021/12/26 20:02:42 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
static int	print_left_aligned(char *str, int len, int len_pad, t_conv conv)
{
	static t_func_string	fp[2] = {print_left_hex, print_left_prefix_hex};

	return ((*fp[(conv.spec & 1 << SHARP) >> SHARP])(str, len, len_pad, conv));
}

static int	print_right_no_sharp(char *str, int len, int len_pad, t_conv conv)
{
	static t_func_string	fp[2] = {print_right_zero_hex, print_right_space_hex};

	return ((*fp[(conv.spec & 1 << PRECISION) >> PRECISION])
		(str, len, len_pad, conv));
}

static int	print_right_sharp(char *str, int len, int len_pad, t_conv conv)
{
	static t_func_string	fp[2] = {print_right_zero_prefix_hex, print_right_space_prefix_hex};

	return ((*fp[(conv.spec & 1 << PRECISION) >> PRECISION])
		(str, len, len_pad, conv));
}

static int	print_right_aligned(char *str, int len, int len_pad, t_conv conv)
{
	static t_func_string	fp[2] = {print_right_no_sharp, print_right_sharp};

	return ((*fp[(conv.spec & 1 << SHARP) >> SHARP])(str, len, len_pad, conv));
}

int	print_hex(va_list *ap, const char **format, t_conv conv)
{
	char					str[9];
	int						flag;
	int						len;
	static t_func_string	fp[2] = {print_right_aligned, print_left_aligned};
	static const char		hexadecimal[2][16] = {
		{48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 97, 98, 99, 100, 101, 102},
		{48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 65, 66, 67, 68, 69, 70}
	};

	get_str_ui(ap, str, hexadecimal[**format == 'X'], 16);
	flag = conv.spec & 1 << PRECISION && get_len(str) < conv.precision;
	len = flag * conv.precision + !flag * get_len(str);
	conv.spec |= ((*((*format)++) == 'X')
			&& (conv.spec & 1 << SHARP) >> SHARP) << HEX_LARGE;
	return ((*fp[(conv.spec & 1 << ALIGNMENT) >> ALIGNMENT])(
		str,
		len,
		conv.field - len - ((conv.spec & 1 << SHARP) >> 1),
		conv));
}
