/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 22:32:35 by gyepark           #+#    #+#             */
/*   Updated: 2021/12/15 13:40:10 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
// if c is '%', va_arg shouldn't be called.
static int	get_index(char c)
{
	return (-1
		+ (c == 'c')
		+ ((c == 's') * 2)
		+ ((c == 'p') * 3)
		+ ((c == 'd' || c == 'i') * 4)
		+ ((c == 'u') * 5)
		+ ((c == 'x') * 6)
		+ ((c == 'X') * 7)
		+ ((c == '%') * 8));
}

static int	process_normal(va_list *ap, const char **format)
{
	ap = NULL;
	ft_putchar_fd(*((*format)++), 1);
	return (1);
}

static int	process_percent(va_list *ap, const char **format)
{
	static t_func	fp[9] = {print_c, print_s, print_p, print_di, print_u, print_x, print_X, print_di}/*{print_c, print_s, print_p, print_di,
		print_u, print_x, print_X, print_percent}*/;

	(*format)++;
	return (fp[get_index(*((*format)++))](ap));
}

int	ft_printf(const char *format, ...)
{
	int		(*fp[2])(va_list *, const char **);
	va_list	ap;
	int		res;

	res = 0;
	fp[0] = process_normal;
	fp[1] = process_percent;
	va_start(ap, format);
	while (*format)
		res += (fp[*format == '%'])(&ap, &format);
	va_end(ap);
	return (res);
}
