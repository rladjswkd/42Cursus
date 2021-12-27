/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 22:32:35 by gyepark           #+#    #+#             */
/*   Updated: 2021/12/27 16:35:20 by gyepark          ###   ########.fr       */
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

static int	print_normal(va_list *ap, const char **format)
{
	ap = 0;
	return (put_char(*((*format)++)));
}

static int	process_percent(va_list *ap, const char **format)
{
	static t_func_specifier	fp[8] = {print_format, print_c, print_s, print_p,
		print_di, print_u, print_hex, print_format};
	t_conv				conv;

	process_conv(&conv, format);
	return (fp[get_specifier_index(**format)](ap, format, conv));
}

int	ft_printf(const char *format, ...)
{
	static t_func_format	fp[2] = {print_normal, process_percent};
	va_list					ap;
	int						res;

	res = 0;
	va_start(ap, format);
	while (*format)
		res += (fp[*format == '%'])(&ap, &format);
	va_end(ap);
	return (res);
}
