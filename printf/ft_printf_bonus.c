/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 22:32:35 by gyepark           #+#    #+#             */
/*   Updated: 2021/12/29 12:41:52 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
static int	get_specifier_index(char c)
{
	return ((c == 'c')
		+ (c == 's') * 2
		+ (c == 'p') * 3
		+ (c == 'd' || c == 'i') * 4
		+ (c == 'u') * 5
		+ (c == 'x' || c == 'X') * 6
		+ (c == '%') * 7);
}

static int	return_invalid(va_list *ap, const char **format, t_conv conv)
{
	ap = 0;
	conv.spec = 0;
	*format += get_len(*format);
	return (-1);
}

static int	process_specifier(va_list *ap, const char **format, t_conv conv)
{
	static t_func_specifier	fp[8] = {print_format, print_c, print_s, print_p,
		print_di, print_u, print_hex, print_format};

	return (fp[get_specifier_index(**format)](ap, format, conv));
}


static int	process_percent(va_list *ap, const char **format)
{
	t_conv					conv;
	static t_func_specifier	fp[2] = {process_specifier, return_invalid};

	process_conv(&conv, format);
	return (fp[conv.field == -1 || conv.precision == -1](ap, format, conv));
}

int	ft_printf(const char *format, ...)
{
	static t_func_format	fp[2] = {print_normal, process_percent};
	va_list					ap;
	int						res;
	int						cur;

	res = 0;
	cur = 0;
	va_start(ap, format);
	while (*format)
	{
		cur = (fp[*format == '%'])(&ap, &format);
		res = (res + cur) * (cur != -1) + -1 * (cur == -1);
	}
	va_end(ap);
	return (res);
}
