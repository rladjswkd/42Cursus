#include "ft_printf.h"
#include <stdio.h>
int	main(void)
{
	ft_printf("%d\n", 2147483648);
	printf("%d\n", 2147483648);
	ft_printf("%d\n", -2147483649);
	printf("%d\n", 2147483649);
	return (0);
}
