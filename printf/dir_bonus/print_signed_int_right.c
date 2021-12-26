/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_signed_int_right.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 18:56:16 by gyepark           #+#    #+#             */
/*   Updated: 2021/12/26 19:57:35 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
int	print_right_zero(char *str, int len, int len_pad, t_conv conv)
{
	int		res;

	conv.spec = 0;
	res = 0;
	while (len_pad-- > 0)
		res += put_char(48);
	res += put_str(str, len);
	return (res);
}

int	print_right_space(char *str, int len, int len_pad, t_conv conv)
{
	int		res;
	int		len_str;

	conv.spec = 0;
	len_str = get_len(str);
	res = 0;
	while (len_pad-- > 0)
		res += put_char(32);
	while (len-- > len_str)
		res += put_char(48);
	res += put_str(str, len_str);
	return (res);
}

int	print_right_zero_prefix(char *str, int len, int len_pad, t_conv conv)
{
	int			res;
	static char	prefix[3] = {' ', '+', '-'};

	res = put_char(prefix[(((conv.spec & 1 << MINUS) >> MINUS) * 3)
			+ (((conv.spec & 1 << PLUS) >> PLUS) * 2)
			+ ((conv.spec & 1 << SPACE) >> SPACE) - 1]);
	while (len_pad-- > 0)
		res += put_char(48);
	res += put_str(str, len);
	return (res);
}

int	print_right_space_prefix(char *str, int len, int len_pad, t_conv conv)
{
	int			res;
	int			len_str;
	static char	prefix[3] = {' ', '+', '-'};

	len_str = get_len(str);
	res = 0;
	while (len_pad-- > 0)
		res += put_char(32);
	res += put_char(prefix[(((conv.spec & 1 << MINUS) >> MINUS) * 3)
			+ (((conv.spec & 1 << PLUS) >> PLUS) * 2)
			+ ((conv.spec & 1 << SPACE) >> SPACE) - 1]);
	while (len-- > len_str)
		res += put_char(48);
	res += put_str(str, len_str);
	return (res);
}
