/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 23:51:26 by gyepark           #+#    #+#             */
/*   Updated: 2022/02/16 14:55:16 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define BUFFER_SIZE 1024
typedef struct s_stack
{
	int		*arr;
	unsigned	size;
	unsigned	len;
	char		name;
}	t_stack;

typedef struct s_ops
{
	unsigned	ra;
	unsigned	rra;
	unsigned	rb;
	unsigned	rrb;
	unsigned	count;
	unsigned	op_type;
}	t_ops;

void		free_all(t_stack *a, t_stack *b);
void		exit_on_error(t_stack *a, t_stack *b);
int		*get_ints(int argc, char **argv);

void		swap(t_stack *s);
void		push(t_stack *from, t_stack *to);
void		rotate(t_stack *s, int is_forward);

void		operate_rr(t_stack *a, t_stack *b, t_ops ops);
void		operate_rrr(t_stack *a, t_stack *b, t_ops ops);
void		operate_cross(t_stack *a, t_stack *b, t_ops ops);

void		print_name(t_stack *s);
void		print_swap(t_stack *s);
void		print_push(t_stack *from, t_stack *to);
void		print_rotate(t_stack *s, int is_forward);
void		print_rotate_both(t_stack *a, t_stack *b, int is_forward);

unsigned	get_top_index(t_stack *s);
void		repeat_rotate(t_stack *s, int count, int is_forward);
int		is_sorted(t_stack *s);
unsigned	get_max_index(t_stack *s);
unsigned	get_min_index(t_stack *s);

int		init_both(t_stack **a, t_stack **b, int argc, char **argv);

t_ops		get_optimal_ops(t_stack *a, t_stack *b);

unsigned	get_min(unsigned x, unsigned y);
unsigned	get_max(unsigned x, unsigned y);

void		sort_greedy(t_stack *a, t_stack *b);
void		sort_direct(t_stack *a, t_stack *b);

void		move_smallest(t_stack *a, t_stack *b);

int 		ft_strlen(char *s);
char    	*ft_strjoin(char *s1, char *s2);
char    	*ft_substr(char *s, int start, int len);
int		are_same_strings(char *s1, char *s2);

char		*get_next_line();
#endif
