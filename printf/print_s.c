/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 20:55:10 by gyepark           #+#    #+#             */
/*   Updated: 2021/12/13 20:55:16 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
int	print_s(va_list *ap)
{
	char	*str;

	str = va_arg(*ap, char *);
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}
