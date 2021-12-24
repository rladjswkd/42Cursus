/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 15:40:52 by gyepark           #+#    #+#             */
/*   Updated: 2021/12/24 19:24:49 by gyepark          ###   ########.fr       */
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
	is_zero = (conv.precision & PRECISION) >> PRECISION_SHIFT;
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
	char					str[17];
	int						flag;
	int						len;
	static t_func_string	fp[2] = {print_right_aligned, print_left_aligned};
	static const char		decimal[10] = {
		48, 49, 50, 51, 52, 53, 54, 55, 56, 57};
	
	get_str_ui(ap, str, decimal, 16);
	flag = conv.spec & PRECISION && get_len(str) < conv.precision;
	len = flag * conv.precision + !flag * get_len(str);
	flag = conv.field >= len;
	(*format)++;
	return ((*fp[(conv.spec & ALIGNMENT) > 0])(
		str,
		len,
		flag * (conv.field - len),
		conv));
}

int	print_hex(va_list *ap, const char **format)
{
/*	static const char	hexadecimal[2][16] = {
		{48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 97, 98, 99, 100, 101, 102},
		{48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 65, 66, 67, 68, 69, 70}
	};

	return (print(ap, hexadecimal[*((*format)++) == 'X'], 16));*/
	return (0);
}
