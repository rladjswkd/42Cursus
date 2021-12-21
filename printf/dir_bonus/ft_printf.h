/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 22:32:28 by gyepark           #+#    #+#             */
/*   Updated: 2021/12/21 21:21:32 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# define ALIGNMENT 1
# define PADDING 2
# define SHARP	4
# define SPACE 8
# define PLUS 16
# define PADDING_SHIFT 1
# define SHARP_SHIFT 2
# define SPACE_SHIFT 3
# define PLUS_SHIFT 4
// prefix 0 : nothing, 1 : "0x", 2 : "0X", 3 : ' ', 4 : '+'
typedef struct s_conv_spec
{
	unsigned int	field;
	unsigned int	precision;
	unsigned int	flag;
}	t_conv;

typedef int		(*t_func_format)(va_list *, const char **);
typedef int		(*t_func_print)(va_list *, const char **, t_conv);
typedef int		(*t_func_char)(char, char, int);
typedef int		(*t_func_string)(char *, t_conv);
typedef int		(*t_func_int)(int);
typedef void	(*t_func_conv)(t_conv *, const char **);

int	ft_printf(const char *format, ...);
int	print_di(va_list *ap, const char **format);
int	print_c(va_list *ap, const char **format, t_conv);
int	print_s(va_list *ap, const char **format);
int	print_p(va_list *ap, const char **format);
int	print_u(va_list *ap, const char **format);
int	print_hex(va_list *ap, const char **format);
int	print_format(va_list *ap, const char **format);
int	put_char(char c);
int	put_str(char *str);
#endif
