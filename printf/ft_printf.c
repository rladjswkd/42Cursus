/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 22:32:35 by gyepark           #+#    #+#             */
/*   Updated: 2021/12/13 17:19:08 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft.h"
static void	initialize_fp(void *(*fp[9])(va_list *))
{
	*(fp[0]) = print_c;
	*(fp[1]) = print_s;
	*(fp[2]) = print_p;
	*(fp[3]) = print_di;
	*(fp[4]) = print_u;
	*(fp[5]) = print_x;
	*(fp[6]) = print_X;
	*(fp[7]) = print_percent;
}

// if c is '%', va_arg shouldn't be called.
static int	get_fp_index(char c)
{
	return ((c == 'c') + (c == 's') + (c == 'p') + (c == 'd' || c == 'i')
		+ (c == 'u') + (c == 'x') + (c == 'X') + (c == '%'));
}

static int	
int	ft_printf(const char *format, ...)
{
	void		(*fp[2])(const char *);
	va_list		ap;

	fp[0] = ft_putchar_fd;
	fp[1] = process_percent;
	va_start(ap, format);
	while (*format)
	{
		
	}
}
