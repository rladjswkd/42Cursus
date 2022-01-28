/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 18:23:50 by gyepark           #+#    #+#             */
/*   Updated: 2022/01/28 23:51:20 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* error */
/* some arguments aren’t integers */
/* some arguments are bigger than an integer */
/* there are duplicates */
/* todo */
/* 1. change the code to accept command line arguments like "1 2 3" 4 5 */

#include <push_swap.h>

int	main(int argc, char **argv)
{
	int	*args;	
	/* do todo 1. here and update argc, argv to represent newly created int list */
	args = get_ints(argc, argv);
	free(args);
	return (0);
}
