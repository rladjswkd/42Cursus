/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_preprocessor.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:10:14 by gyepark           #+#    #+#             */
/*   Updated: 2022/02/14 15:15:24 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static int	check_argument(char *arg)
{
	int	count;
	int	start;
	int	i;

	count = 0;
	start = 0;
	i = -1;
	while (arg[++i])
	{
		if (arg[i] == ' ' || arg[i] == '\t' || arg[i] == '\n')
		{
			if (start < i)
				count++;
			start = i + 1;
		}
	}
	return (count + (start != i));
}

static int	count_numbers(int argc, char **argv)
{
	int	i;
	int	numbers;

	i = 0;
	numbers = 0;
	while (++i < argc)
		numbers += check_argument(argv[i]);
	return (numbers);
}

char	**preprocess_arguments(int argc, char **argv)
{
	char 	**output;
	int	i;
	int	size;

	size = count_numbers(argc, argv);
	output = (char **)malloc(sizeof(char *) * size);
	if (!output)
		return (0);
	i = 0;
	while (
	return (output);
}

int	main(void)
{
	char	*i1[4] = {"program", "+123", "-234", "+-123"};
	char	*i2[4] = {"program", " 2", "\t3", "3\n4"};
	char	*i3[3] = {"program", "+a", "1 2 3\t\t\t\n"};
	int	argc;

	argc = 4;
	printf("%d\n", count_numbers(argc, i1));
	printf("%d\n", count_numbers(argc, i2));
	argc = 3;
	printf("%d\n", count_numbers(argc, i3));
	return (0);
}
