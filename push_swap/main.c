/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 18:23:50 by gyepark           #+#    #+#             */
/*   Updated: 2022/01/28 22:57:55 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* error */
/* some arguments aren’t integers */
/* some arguments are bigger than an integer */
/* there are duplicates */
/* todo */
/* 1. change the code to accept command line arguments like "1 2 3" 4 5 */

#include <unistd.h>
#include <stdlib.h>
#define INT_MAX 2147483647
#define INT_MIN -2147483648

void	exit_on_error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

int	get_ints_if_valid(char *arg)
{
	long	checker;
	int	sign;

	if (*arg == 0)
		return (0);
	while ((8 < *arg && *arg < 14) || *arg == 32)
		arg++;
	sign = 1;
	if (*arg == '-' || *arg == '+')
	{
		if (*arg == '-')
			sign = -1;
		arg++;
	}
	checker = 0;
	while (47 < *arg && *arg < 58)
	{
		checker = checker * 10 + sign * (*(arg++) - 48);
		if (checker < INT_MIN || checker > INT_MAX)
			return (0);
	}
	if (*arg)
		return (0);
	return (1);
}

void	check_duplication(int argc, int *argv)
{
}

int	*get_ints(int argc, char **argv)
{
	int	*args;
	int	i;

	i = 0;
	while (++i < argc)
		if (!is_num_within_range(argv[i]))
			exit_on_error();
	args = (int *)malloc(sizeof(int) * (argc - 1));

	//check_duplication(argc, argv);
	return (args);
}

int	main(int argc, char **argv)
{
	int	*args;

	args = get_ints(argc, argv);
	free(args);
	return (0);
}
