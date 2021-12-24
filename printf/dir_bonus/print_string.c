/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 20:55:36 by gyepark           #+#    #+#             */
/*   Updated: 2021/12/24 16:59:48 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
static int	print_left_aligned(char *str, int len, int len_pad, t_conv conv)
{
	int		is_zero;
	char	padding;
	int		res;

	res = put_str(str, len);
	while (len_pad-- > 0)
		res += put_char(32);
	return (res);
}

static int	print_right_aligned(char *str, int len, int len_pad, t_conv conv)
{
	int		is_zero;
	char	padding;
	int		res;

	is_zero = (conv.spec & PADDING) >> PADDING_SHIFT
		&& !(conv.spec & ALIGNMENT);
	padding = is_zero * 48 + !is_zero * 32;
	res = 0;
	while (len_pad-- > 0)
		res += put_char(padding);
	res += put_str(str, len);
	return (res);
}

int	print_s(va_list *ap, const char **format, t_conv conv)
{
	char					*strs[2];
	char					*str;
	static t_func_string	fp[2] = {print_right_aligned, print_left_aligned};
	int						flag;
	int						len;

	strs[0] = va_arg(*ap, char *);
	strs[1] = "(null)";
	str = strs[strs[0] == 0];
	flag = conv.spec & PRECISION && get_len(str) > conv.precision;
	len = flag * conv.precision + !flag * get_len(str);
	flag = conv.field >= len;
	(*format)++;
	return ((*fp[(conv.spec & ALIGNMENT) > 0])(
		str,
		len,
		flag * (conv.field - len),
		conv));
}
