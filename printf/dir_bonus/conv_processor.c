/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_specification_processor.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 20:40:24 by gyepark           #+#    #+#             */
/*   Updated: 2021/12/26 20:48:24 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.c"
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

static void	process_num(const char **format, int *val)
{
	while (47 < **format && **format < 58)
		*val = *val * 10 + (*((*format)++) - 48);
	(*format)--;
}

static void	process_field(t_conv *conv, const char **format)
{
	conv->spec |= 1 << FIELD;
	process_num(format, &(conv->field));
}

static void	process_precision(t_conv *conv, const char **format)
{
	(*format)++;
	conv->spec |= 1 << PRECISION;
	process_num(format, &(conv->precision));
}

void	process_conv(t_conv *conv, const char **format)
{
	static t_func_conv	fp[7] = {add_alignment, add_padding,
		add_sharp, add_space, add_plus, process_field,
		process_precision};
	int					index;

	conv->field = 0;
	conv->precision = 0;
	conv->spec = 0;
	index = get_conv_spec_index(*(++(*format)));
	while (index > 0)
	{
		fp[index - 1](conv, format);
		index = get_conv_spec_index(*(++(*format)));
	}
}
