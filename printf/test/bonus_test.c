#include <stdio.h>
#include "../ft_printf.h"
#include "../libft/libft.h"
int	main(void)
{
	// invalid format specifier with flags
	printf("%-y\n", 10);
	printf("%y\n", 10);
	printf("%0y\n", 10);
	printf("%-0y\n", 10);

	// valid format specifier with flags
	printf("%-d\n", 10);
	printf("%0d\n", 10);
	printf("%-0d\n", 10);

	printf("%-6d<end>\n", 10);
	printf("%06d<end>\n", 10);
	printf("%-06d<end>\n", 10);
	return (0);
}
