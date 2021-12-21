/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 22:32:35 by gyepark           #+#    #+#             */
/*   Updated: 2021/12/21 21:19:57 by gyepark          ###   ########.fr       */
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
		+ (48 < c && c < 58) * 6
		+ (c == '.') * 7);
}

static void	process_alignment(t_conv *conv, const char **format)
{
	format = 0;
	conv->flag |= ALIGNMENT;
}

static void	process_padding(t_conv *conv, const char **format)
{
	format = 0;
	conv->flag |= PADDING;
}

static void	process_sharp(t_conv *conv, const char **format)
{
	format = 0;
	conv->flag |= SHARP;
}

static void	process_space(t_conv *conv, const char **format)
{
	format = 0;
	conv->flag |= SPACE;
}

static void	process_plus(t_conv *conv, const char **format)
{
	format = 0;
	conv->flag |= PLUS;
}

static void	process_num(const char **format, unsigned int *val)
{
	while (47 < **format && **format < 58)
		*val = *val * 10 + (*((*format)++) - 48);
	(*format)--;
}

static void	process_field(t_conv *conv, const char **format)
{
	process_num(format, &(conv->field));
}

static void	process_precision(t_conv *conv, const char **format)
{
	(*format)++;
	process_num(format, &(conv->precision));
}

static void	process_conv(t_conv *conv, const char **format)
{
	static t_func_conv	fp[7] = {process_alignment, process_padding,
		process_sharp, process_space, process_plus, process_field,
		process_precision};
	int					index;

	conv->field = 0;
	conv->precision = 1;
	conv->flag = 0;
	index = get_conv_spec_index(*(++(*format)));
	while (index > 0)
	{
		fp[index - 1](conv, format);
		index = get_conv_spec_index(*(++(*format)));
	}
}

static int	process_percent(va_list *ap, const char **format)
{
	static t_func_print	fp[8] = {print_format, print_c, print_s, print_p,
		print_di, print_u, print_hex, print_format};
	t_conv				conv;

	process_conv(&conv, format);
	return (fp[get_specifier_index(**format)](ap, format, conv));
}

int	print_format(va_list *ap, const char **format)
{
	ap = 0;
	return (put_char(*((*format)++)));
}

int	ft_printf(const char *format, ...)
{
	static t_func_format	fp[2] = {print_format, process_percent};
	va_list					ap;
	int						res;

	res = 0;
	va_start(ap, format);
	while (*format)
		res += (fp[*format == '%'])(&ap, &format);
	va_end(ap);
	return (res);
}
