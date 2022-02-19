/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 23:50:02 by gyepark           #+#    #+#             */
/*   Updated: 2022/02/17 22:35:00 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_type_range(char *str, int *current)
{
	int			sign;
	long long	value;

	if (*str == 0)
		return (0);
	while ((8 < *str && *str < 14) || *str == 32)
		str++;
	sign = 1;
	if (*str == '-' || *str == '+')
		if (*(str++) == '-')
			sign = -1;
	if (!(*str))
		return (0);
	value = 0;
	while (47 < *str && *str < 58)
	{
		value = value * 10 + sign * (*(str++) - 48);
		if (value < INT_MIN || value > INT_MAX)
			return (0);
	}
	if (*str)
		return (0);
	*current = (int)value;
	return (1);
}

static int	check_duplication(int *arr, int idx)
{
	int	current;

	current = -1;
	while (++current < idx)
		if (arr[current] == arr[idx])
			return (0);
	return (1);
}

int	*get_ints(int argc, char **argv)
{
	int	*arr;
	int	i_argv;
	int	i_arr;

	i_argv = 0;
	i_arr = -1;
	arr = (int *)malloc(sizeof(int) * (argc - 1));
	if (!arr)
		return (0);
	while (++i_argv < argc)
	{
		if (!(check_type_range(argv[i_argv], &(arr[++i_arr]))
				&& check_duplication(arr, i_arr)))
		{
			free(arr);
			return ((int *)0);
		}
	}
	return (arr);
}
