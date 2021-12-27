/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_int_hex_right_bonus.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 21:49:40 by gyepark           #+#    #+#             */
/*   Updated: 2021/12/27 16:37:01 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
int	print_r_zero_hex(char *str, int len, int len_pad, t_conv conv)
{
	int		res;

	conv.spec = 0;
	res = 0;
	while (len_pad-- > 0)
		res += put_char(48);
	res += put_str(str, len);
	return (res);
}

int	print_r_space_hex(char *str, int len, int len_pad, t_conv conv)
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

int	print_r_zero_prefix_hex(char *str, int len, int len_pad, t_conv conv)
{
	int			res;
	static char	prefix[2] = {'x', 'X'};

	res = put_char(48);
	res += put_char(prefix[(conv.spec & 1 << HEX_LARGE) >> HEX_LARGE]);
	while (len_pad-- > 0)
		res += put_char(48);
	res += put_str(str, len);
	return (res);
}

int	print_r_space_prefix_hex(char *str, int len, int len_pad, t_conv conv)
{
	int			res;
	int			len_str;
	static char	prefix[2] = {'x', 'X'};

	len_str = get_len(str);
	res = 0;
	while (len_pad-- > 0)
		res += put_char(32);
	res += put_char(48);
	res += put_char(prefix[(conv.spec & 1 << HEX_LARGE) >> HEX_LARGE]);
	while (len-- > len_str)
		res += put_char(48);
	res += put_str(str, len_str);
	return (res);
}
