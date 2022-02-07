#include "push_swap.h"
#include <stdio.h>

void	print_stack(t_stack s)
{
	printf("arr : ");
	for (int i = 0; i < 5; i++)
		printf("%d ", s.arr[i]);
	printf("\n");
	printf("top : %d\n", s.size - s.len);
	printf("len : %d\n\n", s.len);
}

void	test_swap(t_stack s)
{
	swap(&s);
	print_stack(s);
}

void	test_push(t_stack a, t_stack b)
{
	push(&a, &b);
	print_stack(a);
	print_stack(b);
}

void	test_rotate(t_stack a, int is_forward)
{
	rotate(&a, is_forward);
	print_stack(a);
}

int	main(void)
{
	t_stack	a;
	t_stack	b;

	a.arr = (int *)malloc(sizeof(int) * 5);
	b.arr = (int *)malloc(sizeof(int) * 5);
	a.size = 5;
	b.size = 5;
	a.len = 5;
	b.len = 0;
	for (int i = 0; i < a.size; i++)
		(a.arr)[i] = i + 1;
	for (int i = 0; i < b.size; i++)
		(b.arr)[i] = 0;
	
	test_swap(a);
	test_swap(b);
	test_push(a, b);
	test_push(b, a);
	for (int i = 0; i < a.size + 1; i++)
		test_rotate(a, 1);
	for (int i = 0; i < a.size + 1; i++)
		test_rotate(a, 0);
	push(&a, &b);
	test_rotate(b, 1);
	test_rotate(b, 0);
	push(&a, &b);
	test_rotate(b, 1);
	test_rotate(b, 0);
	
	return (0);
}
