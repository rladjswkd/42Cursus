/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 19:43:52 by gyepark           #+#    #+#             */
/*   Updated: 2022/02/20 17:49:27 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	atoi_minitalk(const char *str, int *ptr)
{
	int			sign;
	long long	result;

	while ((8 < *str && *str < 14) || *str == 32)
		str++;
	sign = 1;
	if (*str == '-' || *str == '+')
		if (*(str++) == '-')
			sign = -1;
	result = 0;
	while (47 < *str && *str < 58)
	{
		result = 10 * result + sign * (*(str++) - 48);
		if (result < -2147483648 || 2147483647 < result)
			return (0);
	}
	if (*str)
		return (0);
	*ptr = (int)result;
	return (1);
}

static void	helper(int n, int sign, int fd)
{
	char	val;

	if (n < -9 || n > 9)
		helper(n / 10, sign, fd);
	val = (n % 10) * sign + 48;
	write(fd, &val, 1);
}

void	putnbr_fd_minitalk(int n, int fd)
{
	char	sign;

	sign = '-';
	if (n < 0)
		write(fd, &sign, 1);
	helper(n, 1 + (-2 * (n < 0)), fd);
}

void	putstr_fd_minitalk(char *s, int fd)
{
	while (*s)
		write(fd, s++, 1);
}

void	exit_on_error(void)
{
	putstr_fd_minitalk("Error\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
}
