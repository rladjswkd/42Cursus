/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 22:32:28 by gyepark           #+#    #+#             */
/*   Updated: 2021/12/20 23:22:38 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
// prefix 0 : nothing, 1 : "0x", 2 : "0X", 3 : ' ', 4 : '+'
typedef struct s_conv_spec
{
	unsigned int		aligned;
	char				padding;
	unsigned int		field;
	unsigned int		precision;
	unsigned int		prefix;
}	t_conv;
typedef int	(*t_func_print)(va_list *, const char **);
typedef int	(*t_func_string)(char *);
typedef int	(*t_func_int)(int);
typedef int	(*t_func_conv)(t_conv);

int	ft_printf(const char *format, ...);
int	print_di(va_list *ap, const char **format);
int	print_c(va_list *ap, const char **format);
int	print_s(va_list *ap, const char **format);
int	print_p(va_list *ap, const char **format);
int	print_u(va_list *ap, const char **format);
int	print_hex(va_list *ap, const char **format);
int	print_format(va_list *ap, const char **format);
int	put_char(char c);
int	put_str(char *str);
#endif
