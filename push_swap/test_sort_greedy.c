#include "push_swap.h"
#include <stdio.h>

static void	init_both(t_stack **a, t_stack **b, int argc, char **argv)
{
	*a = (t_stack *)malloc(sizeof(t_stack));
	*b = (t_stack *)malloc(sizeof(t_stack));
	(*a)->arr = get_ints(argc, argv);
	(*a)->size = argc - 1;
	(*a)->len = (*a)->size;
	(*a)->name = 'a';
	(*b)->arr = (int *)malloc(sizeof(int) * (*a)->size);
	(*b)->size = (*a)->size;
	/* last, bottom index */
	(*b)->len = 0;
	(*b)->name = 'b';
}

static void	free_both(t_stack *a, t_stack *b)
{
	free(a->arr);
	free(b->arr);
	free(a);
	free(b);
}

static void	print_stack(t_stack *s)
{
	printf("arr : ");
	for (int i = 0; i < 6; i++)
		printf("%d ", s->arr[i]);
	printf("\n");
	printf("top : %d\n", s->size - s->len);
	printf("len : %d\n\n", s->len);
}

int	main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;
	init_both(&a, &b, argc, argv);
	sort_greedy(a, b);
	return (0);
}
