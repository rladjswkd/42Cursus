#include <stdio.h>
#include "../ft_printf.h"
int	main(void)
{
	// invalid format specifier with flags
	/*
	printf("%-y\n", 10);
	printf("%y\n", 10);
	printf("%0y\n", 10);
	printf("%-0y\n", 10);
	*/

	// valid format specifier with flags
	/*
	printf("%-d\n", 10);
	printf("%0d\n", 10);
	printf("%-0d\n", 10);

	printf("%-6d<end>\n", 10);
	printf("%06d<end>\n", 10);
	printf("%-06d<end>\n", 10);
	*/

	// # flag
	/*
	printf("%#d\n", 10);
	printf("%#c\n", 'a');
	printf("%#s\n", "hello");
	printf("%#i\n", 10);
	printf("%#u\n", 10);
	printf("%#p\n", (void *)0);
	printf("%#x\n", 10);
	printf("%#X\n", 10);
	*/

	// precision for string
	printf("%.3<end>\n", "hello");
	printf("%.10<end>\n", "hello");
	printf("%.3s<end>\n", "hello");
	printf("%.10s<end>\n", "hello");
	return (0);
}
