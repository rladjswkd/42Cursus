#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack a;

	a.name = 'a';
	a.arr = get_ints(argc, argv);
	a.size = argc - 1;
	a.len = a.size;

	int	res = is_sorted(&a);
	if (res)
		printf("%s\n", "sorted");
	else
		printf("%s\n", "not sorted");
	free(a.arr);
	return (0);
}

/* gcc input_manager.c operations.c printers.c stack_utils.c test_is_sorted.c -o main */
