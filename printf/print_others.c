/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_others.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 20:55:36 by gyepark           #+#    #+#             */
/*   Updated: 2021/12/17 16:01:00 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
static int	print_null(char *str)
{
	str = NULL;
	ft_putstr_fd("(null)", 1);
	return (6);
}

static int	print_str(char *str)
{
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

int	print_c(va_list *ap, const char **format)
{
	ft_putchar_fd((char)va_arg(*ap, int), 1);
	(*format)++;
	return (1);
}

int	print_s(va_list *ap, const char **format)
{
	char	*str;
	int		(*fp[2])(char *);

	fp[0] = print_null;
	fp[1] = print_str;
	str = va_arg(*ap, char *);
	(*format)++;
	return ((*fp[str != 0])(str));
}

int	print_format(va_list *ap, const char **format)
{
	ap = NULL;
	ft_putchar_fd(**format, 1);
	(*format)++;
	return (1);
}
