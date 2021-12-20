/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 22:32:35 by gyepark           #+#    #+#             */
/*   Updated: 2021/12/20 23:25:21 by gyepark          ###   ########.fr       */
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

static int	get_conv_spec_index(char c)
{
	return ((c == '-')
		+ (c == '0') * 2
		+ (c == '#') * 3
		+ (c == ' ') * 4
		+ (c == '+') * 5
		+ (47 < c && c < 58) * 6
		+ (c == '.') * 7);
}

static t_conv_spec	process_spec(const char **format)
{
	static t_func_conv	fp[7] = {;
	t_conv_spec			cs;
	int					ch;

	cs.aligned = 0;
	cs.padding = ' ';
	cs.field = 0;
	cs.precision = 1;
	cs.prefix = 0;
	ch = get_conv_spec_index(**format);
	while (ch > 0)
	{

}

static int	process_percent(va_list *ap, const char **format)
{
	static t_func_print	fp[8] = {print_format, print_c, print_s, print_p,
		print_di, print_u, print_hex, print_format};
	t_conv_spec		cs;

	(*format)++;
	cs = process_spec(format);
	return (fp[get_specifier_index(**format)](ap, format));
}

int	ft_printf(const char *format, ...)
{
	static t_func_print	fp[2] = {print_format, process_percent};
	va_list				ap;
	int					res;

	res = 0;
	va_start(ap, format);
	while (*format)
		res += (fp[*format == '%'])(&ap, &format);
	va_end(ap);
	return (res);
}
