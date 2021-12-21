/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 20:55:36 by gyepark           #+#    #+#             */
/*   Updated: 2021/12/21 21:36:13 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
static int	print_null(char *str, t_conv conv)
{
	str = "(null)";
}
static int	print_str(char *str, t_conv conv)
{

}

int	print_s(va_list *ap, const char **format, t_conv conv)
{
	char					*str;
	static t_func_string	fp[2] = {print_null, print_str};

	str = va_arg(*ap, char *);
	(*format)++;
	return ((*fp[str != 0])(str, conv));
}
