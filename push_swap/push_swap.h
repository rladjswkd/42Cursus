/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 23:51:26 by gyepark           #+#    #+#             */
/*   Updated: 2022/02/04 18:55:08 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# define INT_MAX 2147483647
# define INT_MIN -2147483648
typedef unsigned int uint
typedef struct s_stack
{
	int	*arr;
	int	size;
	int	len;
	int	max;
	int	min;
	char	name;
}	t_stack;

int	*get_ints(int argc, char **argv);

void	swap(t_stack *s);
void	push(t_stack *from, t_stack *to);
void	rotate(t_stack *s, int is_forward);
int	get_top_index(t_stack *s);

void	print_name(t_stack *s);
void	print_swap(t_stack *s);
void	print_push(t_stack *from, t_stack *to);
void	print_rotate(t_stack *s, int is_forward);

int	find_max(t_stack *s);
int	find_min(t_stack *s);
#endif
