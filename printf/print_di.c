/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_di.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:40:40 by gyepark           #+#    #+#             */
/*   Updated: 2021/12/13 19:43:08 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
int	print_di(va_list *ap)
{
	char	*n_str;

	n_str = ft_itoa(va_arg(*ap, int));
	ft_putstr_fd(n_str, 1);
	return (ft_strlen(n_str));
}
