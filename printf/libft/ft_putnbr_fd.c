/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:33:23 by gyepark           #+#    #+#             */
/*   Updated: 2021/11/23 22:54:55 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
static void	helper(int n, int sign, int fd)
{
	if (n < -9 || n > 9)
		helper(n / 10, sign, fd);
	ft_putchar_fd(48 + (n % 10) * sign, fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
		ft_putchar_fd('-', fd);
	helper(n, 1 + (-2 * (n < 0)), fd);
}
