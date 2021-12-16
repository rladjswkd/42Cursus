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
	/*
	printf("%d\n", ft_printf("%u\n", 0));
	printf("%d\n", printf("%u\n", 0));
	printf("%d\n", ft_printf("%u\n", -2147483648));
	printf("%d\n", printf("%u\n", -2147483648));
	printf("%d\n", ft_printf("%u\n", 4294967295));
	printf("%d\n", printf("%u\n", 4294967295));
	printf("%d\n", ft_printf("%u\n", 4294967296));
	printf("%d\n", printf("%u\n", 4294967296));
	*/

	// %x, %X
	/*
	printf("%d\n", ft_printf("%x\n", 0));
	printf("%d\n", printf("%x\n", 0));
	printf("%d\n", ft_printf("%x\n", -2147483648));
	printf("%d\n", printf("%x\n", -2147483648));
	printf("%d\n", ft_printf("%x\n", 4294967295));
	printf("%d\n", printf("%x\n", 4294967295));
	printf("%d\n", ft_printf("%x\n", 4294967296));
	printf("%d\n", printf("%x\n", 4294967296));
	printf("%d\n", ft_printf("%x\n", 32));
	printf("%d\n", printf("%x\n", 32));


	printf("%d\n", ft_printf("%X\n", 0));
	printf("%d\n", printf("%X\n", 0));
	printf("%d\n", ft_printf("%X\n", -2147483648));
	printf("%d\n", printf("%X\n", -2147483648));
	printf("%d\n", ft_printf("%X\n", 4294967295));
	printf("%d\n", printf("%X\n", 4294967295));
	printf("%d\n", ft_printf("%X\n", 4294967296));
	printf("%d\n", printf("%X\n", 4294967296));
	printf("%d\n", ft_printf("%X\n", 32));
	printf("%d\n", printf("%X\n", 32));
	*/

	// %%
	/*
	printf("%d\n", ft_printf("%%\n", 32));
	printf("%d\n", printf("%%\n", 32));

	printf("%d\n", printf("%%\n", 32)); // segfault occurs.
	*/

	// combined tests
	printf("%d\n", ft_printf("%%. %d is %x %s\n", 125, 125, "in hexadecimal"));
	printf("%d\n", printf("%%. %d is %x %s\n", 125, 125, "in hexadecimal"));
	printf("%d\n", ft_printf("%x and %X is different.\n", 125, 125));
	printf("%d\n", printf("%x and %X is different.\n", 125, 125));
	printf("%d\n", ft_printf("%i is %u in %%u.\n", -125, -125));
	printf("%d\n", printf("%i is %u in %%u.\n", -125, -125));
	printf("%d\n", ft_printf("%d is printed, but one argument is left.\n", 125, 125));
	printf("%d\n", printf("%d is printed, but one argument is left.\n", 125, 125));
	printf("%d\n", ft_printf("%s\n", 0));
	printf("%d\n", printf("%s\n", 0));

	// invalid flags	
	printf("%d\n", ft_printf("%y\n", 125, 125));
	printf("%d\n", printf("%y\n", 125, 125));
	printf("%d\n", ft_printf("%yvk\n", 125, 125));
	printf("%d\n", printf("%yvk\n", 125, 125));

	// empty format
	
	printf("%d\n", ft_printf("", 125, 125));
	printf("%d\n", printf("", 125, 125));
	
	return (0);
}
