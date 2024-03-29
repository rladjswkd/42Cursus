/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_int_hex_left.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 21:44:23 by gyepark           #+#    #+#             */
/*   Updated: 2021/12/26 20:28:30 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
int	print_l_hex(char *str, int len, int len_pad, t_conv conv)
{
	int	res;
	int	len_str;

	conv.spec = 0;
	len_str = get_len(str);
	res = 0;
	while (len-- > len_str)
		res += put_char(48);
	res += put_str(str, len_str);
	while (len_pad-- > 0)
		res += put_char(32);
	return (res);
}

int	print_l_prefix_hex(char *str, int len, int len_pad, t_conv conv)
{
	int			res;
	int			len_str;
	static char	prefix[2] = {'x', 'X'};

	len_str = get_len(str);
	res = put_char(48);
	res += put_char(prefix[(conv.spec & 1 << HEX_LARGE) >> HEX_LARGE]);
	while (len-- > len_str)
		res += put_char(48);
	res += put_str(str, len_str);
	while (len_pad-- > 0)
		res += put_char(32);
	return (res);
}
