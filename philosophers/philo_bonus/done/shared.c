#include "struct_args.h"

t_args	access_args(t_args *initializer)
{
	static t_args args;

	if (initializer)
		args = *initializer;
	return (args);
}

int	*access_last_eat(int initializer)
{
	static int	last;

	if (initializer)
		last = initializer;
	return (&last);
}

int	*access_n_eat(int initializer)
{
	static int	count;

	if (initializer)
		count = initializer;
	return (&count);
}
