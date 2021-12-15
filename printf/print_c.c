/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 20:55:36 by gyepark           #+#    #+#             */
/*   Updated: 2021/12/15 14:28:38 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
int	print_c(va_list *ap, const char **format)
{
	ft_putchar_fd((char)va_arg(*ap, int), 1);
	(*format)++;
	return (1);
}
