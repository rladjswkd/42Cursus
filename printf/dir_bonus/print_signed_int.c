/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_signed_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:40:40 by gyepark           #+#    #+#             */
/*   Updated: 2021/12/26 19:49:04 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
static int	print_left(char *str, int len, int len_pad, t_conv conv)
{
	static t_func_string	fp[2] = {print_left_no_prefix, print_left_prefix};
	
	return ((*fp[((conv.spec & 1 << MINUS) >> MINUS)
				|| ((conv.spec & 1 << PLUS) >> PLUS)
				|| ((conv.spec & 1 << SPACE) >> SPACE)])
			(str, len, len_pad, conv));
}

static int	print_right_no_prefix(char *str, int len, int len_pad, t_conv conv)
{
	static t_func_string	fp[2] = {print_right_space, print_right_zero};

	return ((*fp[!((conv.spec & 1 << PRECISION) >> PRECISION)
				&& (conv.spec & 1 << PADDING) >> PADDING])
			(str, len, len_pad, conv));
}

static int	print_right_prefix(char *str, int len, int len_pad, t_conv conv)
{
	static t_func_string	fp[2] = {print_right_space_prefix,
		print_right_zero_prefix};

	return ((*fp[!((conv.spec & 1 << PRECISION) >> PRECISION)
				&& (conv.spec & 1 << PADDING) >> PADDING])
			(str, len, len_pad, conv));
}

static int	print_right(char *str, int len, int len_pad, t_conv conv)
{
	static t_func_string	fp[2] = {print_right_no_prefix,
		print_right_prefix};

	return ((*fp[((conv.spec & 1 << MINUS) >> MINUS)
				|| ((conv.spec & 1 << PLUS) >> PLUS)
				|| ((conv.spec & 1 << SPACE) >> SPACE)])
			(str, len, len_pad, conv));
}

int	print_di(va_list *ap, const char **format, t_conv conv)
{
	char					str[11];
	int						flag;
	int						len;
	static t_func_string	fp[2] = {print_right, print_left};
	static t_func_conv		fp_conv[2] = {process_others, process_minus};

	get_str(ap, str, &conv);
	(*fp_conv[(conv.spec & 1 << MINUS) >> MINUS])(&conv, format);
	flag = conv.spec & 1 << PRECISION && get_len(str) < conv.precision;
	len = flag * conv.precision + !flag * get_len(str);
	flag = (conv.spec & 1 << MINUS) >> MINUS
				|| (conv.spec & 1 << PLUS) >> PLUS
				|| (conv.spec & 1 << SPACE) >> SPACE;
	return ((*fp[(conv.spec & 1 << ALIGNMENT) >> ALIGNMENT])(
		str,
		len,
		conv.field - len - flag,
		conv));
}
