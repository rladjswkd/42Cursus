#include "ft_printf.h"
#include <stdio.h>
int	main(void)
{
	// %d, %i
	/*
	printf("%d\n", ft_printf("%d\n", 2147483648));
	printf("%d\n", printf("%d\n", 2147483648));
	printf("%d\n", ft_printf("%d\n", -2147483649));
	printf("%d\n", printf("%d\n", -2147483649));
	printf("%d\n", ft_printf("%d\n", 0));
	printf("%d\n", printf("%d\n", 0));
	printf("%i\n", ft_printf("%d\n", 2147483648));
	printf("%i\n", printf("%d\n", 2147483648));
	printf("%i\n", ft_printf("%d\n", -2147483649));
	printf("%i\n", printf("%d\n", -2147483649));
	printf("%i\n", ft_printf("%d\n", 0));
	printf("%i\n", printf("%d\n", 0));
*/
	// %c
	/*
	printf("%d\n", ft_printf("%c\n", 'a'));
	printf("%d\n", printf("%c\n", 'a'));
	printf("%d\n", ft_printf("%c\n", ' '));
	printf("%d\n", printf("%c\n", ' '));
	printf("%d\n", ft_printf("%c\n", 0));
	printf("%d\n", printf("%c\n", 0));
	printf("%d\n", ft_printf("%c\n", 65));
	printf("%d\n", printf("%c\n", 65));
	printf("%d\n", ft_printf("%c\n", 300));
	printf("%d\n", printf("%c\n", 300));
	printf("%d\n", ft_printf("%c\n", '\n'));
	printf("%d\n", printf("%c\n", '\n'));
*/
	// %s
	printf("%d\n", ft_printf("%s\n", "hello, world!"));
	printf("%d\n", printf("%s\n", "hello, world!"));
	printf("%d\n", ft_printf("%s\n", "    "));
	printf("%d\n", printf("%s\n", "    "));
	printf("%d\n", ft_printf("%s\n", ""));
	printf("%d\n", printf("%s\n", ""));
	return (0);
}
