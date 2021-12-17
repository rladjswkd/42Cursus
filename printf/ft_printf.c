/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 22:32:35 by gyepark           #+#    #+#             */
/*   Updated: 2021/12/17 19:36:52 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
static int	get_index(char c)
{
	return ((c == 'c')
		+ ((c == 's') * 2)
		+ ((c == 'p') * 3)
		+ ((c == 'd' || c == 'i') * 4)
		+ ((c == 'u') * 5)
		+ ((c == 'x' || c == 'X') * 6)
		+ ((c == '%') * 7));
}

static int	process_normal(va_list *ap, const char **format)
{
	ap = NULL;
	put_char(*((*format)++));
	return (1);
}

static int	process_percent(va_list *ap, const char **format)
{
	static t_func	fp[8] = {print_format, print_c, print_s, print_p, print_di,
		print_u, print_hex, print_format};

	(*format)++;
	return (fp[get_index(**format)](ap, format));
}

int	ft_printf(const char *format, ...)
{
	static t_func	fp[2] = {process_normal, process_percent};
	va_list			ap;
	int				res;

	res = 0;
	va_start(ap, format);
	while (*format)
		res += (fp[*format == '%'])(&ap, &format);
	va_end(ap);
	return (res);
}
