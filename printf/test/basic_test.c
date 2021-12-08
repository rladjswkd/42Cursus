#include <stdio.h>
#include "../ft_printf.h"
#include "../libft/libft.h"
int	main(void)
{
	int c = printf("", "hello");
	printf("%d\n", c); // 0 is returned
	int c2 = printf("%c", "hello");
	printf("%d\n", c2); // something is returned -> in man pages, it will return negative value if error occurs.
	int c3 = printf("%v", "hello");
	printf("%d\n", c3);
	return (0);
}
