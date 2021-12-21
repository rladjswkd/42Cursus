#include "ft_printf.h"
#include <stdio.h>
int	main(void)
{
	//%c
	/*
	printf("%-5c<end>\n", 'a');
	printf("% c\n", 'a');
	printf("%05c\n", 'a');
	printf("%.5c\n", 'a');
	printf("%+c\n", 'a');
	printf("%#c\n\n", 'a');

	ft_printf("%-5c<end>\n", 'a');
	ft_printf("% c\n", 'a');
	ft_printf("%05c\n", 'a');
	ft_printf("%.5c\n", 'a');
	ft_printf("%+c\n", 'a');
	ft_printf("%#c\n", 'a');
	*/

	//%s
	printf("%010s<end>\n", 0);
	printf("%-5s<end>\n", "abc");
	printf("%5s<end>\n", "abc");
	printf("% s\n", "abc");
	printf("%05s\n", "abc");
	printf("%.5s\n", "abc");
	printf("%.2s\n", "abc");
	printf("%6.2s<end>\n", "abc");
	printf("%+s\n", "abc");
	printf("%#s\n", "abc");
	return (0);
}
