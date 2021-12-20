/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_others.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 20:55:36 by gyepark           #+#    #+#             */
/*   Updated: 2021/12/20 23:18:51 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
static int	print_null(char *str)
{
	str = 0;
	return (put_str("(null)"));
}

int	print_c(va_list *ap, const char **format)
{
	(*format)++;
	return (put_char((char)va_arg(*ap, int)));
}

int	print_s(va_list *ap, const char **format)
{
	char					*str;
	static t_func_string	fp[2] = {print_null, put_str};

	str = va_arg(*ap, char *);
	(*format)++;
	return ((*fp[str != 0])(str));
}

int	print_format(va_list *ap, const char **format)
{
	ap = 0;
	return (put_char(*((*format)++)));
}
