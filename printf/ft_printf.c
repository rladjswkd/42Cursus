/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 22:32:35 by gyepark           #+#    #+#             */
/*   Updated: 2021/12/12 22:59:17 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft.h"
int	ft_printf(const char *format, ...)
{
	const char	*valid_set = "cspdiuxX%";
	void		(*fp)[9](va_list*);
	va_list		ap;
	int			index;

	index = 0;
	va_start(ap, format);
	while (format[index])
	{
		
}
