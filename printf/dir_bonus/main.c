#include "ft_printf.h"
#include <stdio.h>
int	main(void)
{
	//%c
	/*	
	printf("%-5c<end>\n", 'a');
	ft_printf("%-5c<end>\n", 'a');
	printf("% c<end>\n", 'a');
	ft_printf("% c<end>\n", 'a');
	printf("%05c<end>\n", 'a');
	ft_printf("%05c<end>\n", 'a');
	printf("%.5c<end>\n", 'a');
	ft_printf("%.5c<end>\n", 'a');
	printf("%+c<end>\n", 'a');
	ft_printf("%+c<end>\n", 'a');
	printf("%#c<end>\n", 'a');
	ft_printf("%#c<end>\n", 'a');
	printf("%-05c<end>\n", 'a');
	ft_printf("%-05c<end>\n", 'a');
	printf("\n");
	*/

	//%s

	printf("%010s<end>\n", (void *)0);
	ft_printf("%010s<end>\n\n", (void *)0);
	printf("%.4s<end>\n", (void *)0);
	ft_printf("%.4s<end>\n\n", (void *)0);
	printf("%.10s<end>\n", (void *)0);
	ft_printf("%.10s<end>\n\n", (void *)0);
	printf("%-5s<end>\n", "abc");
	ft_printf("%-5s<end>\n\n", "abc");
	printf("%5s<end>\n", "abc");
	ft_printf("%5s<end>\n\n", "abc");
	printf("% s\n", "abc");
	ft_printf("% s\n\n", "abc");
	printf("%05s\n", "abc");
	ft_printf("%05s\n\n", "abc");
	printf("%.5s\n", "abc");
	ft_printf("%.5s\n\n", "abc");
	printf("%.2s\n", "abc");
	ft_printf("%.2s\n\n", "abc");
	printf("%6.2s<end>\n", "abc");
	ft_printf("%6.2s<end>\n\n", "abc");
	printf("%+s\n", "abc");
	ft_printf("%+s\n\n", "abc");
	printf("%#s\n", "abc");
	ft_printf("%#s\n\n", "abc");

	return (0);
}
