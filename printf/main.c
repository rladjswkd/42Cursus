#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
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
	/*
	printf("%d\n", ft_printf("%s\n", "hello, world!"));
	printf("%d\n", printf("%s\n", "hello, world!"));
	printf("%d\n", ft_printf("%s\n", "    "));
	printf("%d\n", printf("%s\n", "    "));
	printf("%d\n", ft_printf("%s\n", ""));
	printf("%d\n", printf("%s\n", ""));
*/
	// %p
	/*
	void	*p;

	printf("%d\n", ft_printf("%p\n", (void *)0));
	printf("%d\n", printf("%p\n", (void *)0));
	printf("%d\n", ft_printf("%p\n", 0xffffffffffffffff));
	printf("%d\n", printf("%p\n", 0xffffffffffffffff));
	printf("%d\n", ft_printf("%p\n", p));
	printf("%d\n", printf("%p\n", p));
*/
	// %u

	printf("%d\n", ft_printf("%u\n", 0));
	printf("%d\n", printf("%u\n", 0));
	printf("%d\n", ft_printf("%u\n", -2147483648));
	printf("%d\n", printf("%u\n", -2147483648));
	printf("%d\n", ft_printf("%u\n", 4294967295));
	printf("%d\n", printf("%u\n", 4294967295));
	printf("%d\n", ft_printf("%u\n", 4294967296));
	printf("%d\n", printf("%u\n", 4294967296));

	return (0);
}
