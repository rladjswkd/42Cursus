/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 22:32:28 by gyepark           #+#    #+#             */
/*   Updated: 2021/12/25 22:57:56 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# define ALIGNMENT 0
# define PADDING 1
# define SHARP	2
# define SPACE 3
# define PLUS 4
# define FIELD 5
# define PRECISION 6
# define HEX_LARGE 7
typedef struct s_conv_spec
{
	int	spec;
	int	field;
	int	precision;
}	t_conv;
typedef int		(*t_func_format)(va_list *, const char **);
typedef int		(*t_func_print)(va_list *, const char **, t_conv);
typedef int		(*t_func_char)(char, char, int);
typedef int		(*t_func_string)(char *, int, int, t_conv);
typedef int		(*t_func_int)(int);
typedef void	(*t_func_conv)(t_conv *, const char **);
/*functions for each conversion specifier.*/
int		ft_printf(const char *format, ...);
int		print_di(va_list *ap, const char **format);
int		print_c(va_list *ap, const char **format, t_conv conv);
int		print_s(va_list *ap, const char **format, t_conv conv);
int		print_p(va_list *ap, const char **format, t_conv conv);
int		print_u(va_list *ap, const char **format, t_conv conv);
int		print_hex(va_list *ap, const char **format, t_conv conv);
int		print_format(va_list *ap, const char **format, t_conv conv);
/*utility functions*/
int		put_char(char c);
int		put_str(char *str, int len);
int		get_len(char *str);
void	get_str_ull(va_list *ap, char *str, const char *arr, unsigned int base);
void	get_str_ui(va_list *ap, char *str, const char *arr, unsigned int base);
/*print functions*/
int		print_left_hex(char *str, int len, int len_pad, t_conv conv);
int		print_left_prefix_hex(char *str, int len, int len_pad, t_conv conv);
int		print_right_zero_hex(char *str, int len, int len_pad, t_conv conv);
int		print_right_space_hex(char *str, int len, int len_pad, t_conv conv);
int		print_right_zero_prefix_hex(char *str, int len, int len_pad, t_conv conv);
int		print_right_space_prefix_hex(char *str, int len, int len_pad, t_conv conv);

#endif
