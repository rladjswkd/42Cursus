/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_signed_int_left.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 16:25:57 by gyepark           #+#    #+#             */
/*   Updated: 2021/12/26 20:13:26 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
int	print_left_prefix(char *str, int len, int len_pad, t_conv conv)
{
	int			res;
	int			len_str;
	static char	prefix[3] = {' ', '+', '-'};

	len_str = get_len(str);
	res = put_char(prefix[(((conv.spec & 1 << MINUS) >> MINUS) * 3)
			+ (((conv.spec & 1 << PLUS) >> PLUS) * 2)
			+ ((conv.spec & 1 << SPACE) >> SPACE) - 1]);
	while (len-- > len_str)
		res += put_char(48);
	res += put_str(str, len_str);
	while (len_pad-- > 0)
		res += put_char(32);
	return (res);
}

int	print_left_no_prefix(char *str, int len, int len_pad, t_conv conv)
{
	int	res;
	int	len_str;

	conv.spec = 0;
	res = 0;
	len_str = get_len(str);
	while (len-- > len_str)
		res += put_char(48);
	res += put_str(str, len_str);
	while (len_pad-- > 0)
		res += put_char(32);
	return (res);
}
