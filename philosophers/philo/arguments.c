/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 23:23:31 by gyepark           #+#    #+#             */
/*   Updated: 2022/08/10 23:27:47 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_args.h"
#include "shared.h"

static int	get_sign(char **str)
{
	int	sign;

	sign = 1;
	if (**str == '-' || **str == '+')
		if (*((*str)++) == '-')
			sign = -1;
	if (48 > **str || **str > 57)
		return (0);
	return (sign);
}

static int	get_int(char *str, int *val)
{
	int	sign;

	sign = get_sign(&str);
	if (sign < 1)
		return (0);
	*val = 0;
	while (47 < *str && *str < 58)
		*val = *val * 10 + sign * (*(str++) - 48);
	if (*str != '\0')
		return (0);
	return (1);
}

int	parse_arguments(int argc, char **argv)
{
	t_args	args;

	if (argc != 5 && argc != 6)
		return (0);
	if (!get_int(argv[1], &(args.n_philo)))
		return (0);
	if (!get_int(argv[2], &(args.time_die)))
		return (0);
	if (!get_int(argv[3], &(args.time_eat)))
		return (0);
	if (!get_int(argv[4], &(args.time_sleep)))
		return (0);
	if (argc == 5)
		args.n_eat = 2147483647;
	else if (argc == 6 && !get_int(argv[5], &(args.n_eat)))
		return (0);
	access_args(&args);
	return (1);
}
