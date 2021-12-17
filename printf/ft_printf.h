/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 22:32:28 by gyepark           #+#    #+#             */
/*   Updated: 2021/12/17 15:31:32 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft/libft.h"
typedef int	(*t_func)(va_list *, const char **);
int	ft_printf(const char *format, ...);
int	print_di(va_list *ap, const char **format);
int	print_c(va_list *ap, const char **format);
int	print_s(va_list *ap, const char **format);
int	print_p(va_list *ap, const char **format);
int	print_u(va_list *ap, const char **format);
int	print_hex(va_list *ap, const char **format);
int	print_format(va_list *ap, const char **format);
#endif
