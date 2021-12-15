/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 14:00:35 by gyepark           #+#    #+#             */
/*   Updated: 2021/12/15 14:31:17 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
int	print_flag(va_list *ap, const char **format)
{
	ap = NULL;
	ft_putchar_fd(**format, 1);
	(*format)++;
	return (1);
}
