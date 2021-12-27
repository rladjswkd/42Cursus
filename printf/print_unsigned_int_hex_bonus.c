/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_int_hex_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 01:22:46 by gyepark           #+#    #+#             */
/*   Updated: 2021/12/27 16:36:46 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
static int	print_left(char *str, int len, int len_pad, t_conv conv)
{
	static t_func_printer	fp[2] = {print_l_hex, print_l_prefix_hex};

	return ((*fp[(conv.spec & 1 << SHARP) >> SHARP])(str, len, len_pad, conv));
}

static int	print_r_no_sharp(char *str, int len, int len_pad, t_conv conv)
{
	static t_func_printer	fp[2] = {print_r_space_hex, print_r_zero_hex};

	return ((*fp[!((conv.spec & 1 << PRECISION) >> PRECISION)
				&& (conv.spec & 1 << PADDING) >> PADDING])
		(str, len, len_pad, conv));
}

static int	print_r_sharp(char *str, int len, int len_pad, t_conv conv)
{
	static t_func_printer	fp[2] = {print_r_space_prefix_hex,
		print_r_zero_prefix_hex};

	return ((*fp[!((conv.spec & 1 << PRECISION) >> PRECISION)
				&& (conv.spec & 1 << PADDING) >> PADDING])
		(str, len, len_pad, conv));
}

static int	print_right(char *str, int len, int len_pad, t_conv conv)
{
	static t_func_printer	fp[2] = {print_r_no_sharp, print_r_sharp};

	return ((*fp[(conv.spec & 1 << SHARP) >> SHARP])(str, len, len_pad, conv));
}

int	print_hex(va_list *ap, const char **format, t_conv conv)
{
	char					str[9];
	int						flag;
	int						len;
	static t_func_printer	fp[2] = {print_right, print_left};
	static const char		hexadecimal[2][16] = {
		{48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 97, 98, 99, 100, 101, 102},
		{48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 65, 66, 67, 68, 69, 70}
	};

	get_str_ui(ap, str, hexadecimal[**format == 'X'], 16);
	str[0] -= str[0] * ((conv.spec & 1 << PRECISION) >> PRECISION
			&& !(conv.precision) && str[0] == 48);
	flag = conv.spec & 1 << PRECISION && get_len(str) < conv.precision;
	len = flag * conv.precision + !flag * get_len(str);
	conv.spec &= ~((str[0] == 48) << SHARP);
	conv.spec |= ((*((*format)++) == 'X')
			&& (conv.spec & 1 << SHARP) >> SHARP) << HEX_LARGE;
	return ((*fp[(conv.spec & 1 << ALIGNMENT) >> ALIGNMENT])(
		str,
		len,
		conv.field - len - ((conv.spec & 1 << SHARP) >> 1),
		conv));
}
