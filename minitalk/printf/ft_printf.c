/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 22:32:35 by gyepark           #+#    #+#             */
/*   Updated: 2021/12/29 22:07:38 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
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

static int	exit_invalid(va_list *ap, const char **f, const char **t, t_conv c)
{
	ap = 0;
	c.spec = 0;
	*t = (char *)0;
	*f = (const char *)0;
	return (-1);
}

static int	process_spec(va_list *ap, const char **f, const char **t, t_conv c)
{
	static t_func_specifier	fp[8] = {print_format, print_c, print_s, print_p,
		print_di, print_u, print_hex, print_format};
	int						res;

	res = put_str((char *)(*f), find_percent(*f) - (char *)(*f));
	*f = *t;
	return (res + fp[get_specifier_index(**f)](ap, f, c));
}

static int	process_percent(va_list *ap, const char **format)
{
	t_conv				conv;
	const char			*percent;
	static t_checker	fp[2] = {process_spec, exit_invalid};

	percent = (const char *)(find_percent(*format));
	process_conv(&conv, &percent);
	return (fp[conv.field == -1 || conv.precision == -1]
		(ap, format, &percent, conv));
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
	while (format && *format)
	{
		cur = (fp[*(find_percent(format)) == '%'])(&ap, &format);
		res = (res + cur) * (cur != -1) + -1 * (cur == -1);
	}
	va_end(ap);
	return (res);
}
