/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_di.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:40:40 by gyepark           #+#    #+#             */
/*   Updated: 2021/12/14 22:40:30 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
int	print_di(va_list *ap)
{
	char	*n_str;
	int		res;

	n_str = ft_itoa(va_arg(*ap, int));
	res = ft_strlen(n_str);
	ft_putstr_fd(n_str, 1);
	free(n_str);
	return (res);
}
