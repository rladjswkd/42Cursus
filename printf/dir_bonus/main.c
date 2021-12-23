#include "ft_printf.h"
#include <stdio.h>
int	main(void)
{
	//%c
	/*		
	printf("%d\n", printf("%-5c<end>\n", 'a'));
	printf("%d\n", ft_printf("%-5c<end>\n", 'a'));
	printf("%d\n", printf("% c<end>\n", 'a'));
	printf("%d\n", ft_printf("% c<end>\n", 'a'));
	printf("%d\n", printf("%05c<end>\n", 'a'));
	printf("%d\n", ft_printf("%05c<end>\n", 'a'));
	printf("%d\n", printf("%.5c<end>\n", 'a'));
	printf("%d\n", ft_printf("%.5c<end>\n", 'a'));
	printf("%d\n", printf("%+c<end>\n", 'a'));
	printf("%d\n", ft_printf("%+c<end>\n", 'a'));
	printf("%d\n", printf("%#c<end>\n", 'a'));
	printf("%d\n", ft_printf("%#c<end>\n", 'a'));
	printf("%d\n", printf("%-05c<end>\n", 'a'));
	printf("%d\n", ft_printf("%-05c<end>\n", 'a'));
	printf("\n");
	*/

	//%s
	/*	
	printf("%d\n", printf("%010s<end>\n", (void *)0));
	printf("%d\n", ft_printf("%010s<end>\n", (void *)0));
	printf("%d\n", printf("%.4s<end>\n", (void *)0));
	printf("%d\n", ft_printf("%.4s<end>\n", (void *)0));
	printf("%d\n", printf("%.10s<end>\n", (void *)0));
	printf("%d\n", ft_printf("%.10s<end>\n", (void *)0));
	printf("%d\n", printf("%-5s<end>\n", "abc"));
	printf("%d\n", ft_printf("%-5s<end>\n", "abc"));
	printf("%d\n", printf("%5s<end>\n", "abc"));
	printf("%d\n", ft_printf("%5s<end>\n", "abc"));
	printf("%d\n", printf("% s\n", "abc"));
	printf("%d\n", ft_printf("% s\n", "abc"));
	printf("%d\n", printf("%05s\n", "abc"));
	printf("%d\n", ft_printf("%05s\n", "abc"));
	printf("%d\n", printf("%.5s\n", "abc"));
	printf("%d\n", ft_printf("%.5s\n", "abc"));
	printf("%d\n", printf("%.2s\n", "abc"));
	printf("%d\n", ft_printf("%.2s\n", "abc"));
	printf("%d\n", printf("%6.2s<end>\n", "abc"));
	printf("%d\n", ft_printf("%6.2s<end>\n", "abc"));
	printf("%d\n", printf("%+s\n", "abc"));
	printf("%d\n", ft_printf("%+s\n", "abc"));
	printf("%d\n", printf("%#s\n", "abc"));
	printf("%d\n", ft_printf("%#s\n", "abc"));
	printf("\n");
	*/

	//%p
	
	void	*p;
	printf("%d\n", printf("%p<end>\n", p));
	printf("%d\n", ft_printf("%p<end>\n", p));
	printf("%d\n", printf("%p<end>\n", p));
	printf("%d\n", ft_printf("%p<end>\n", p));
	printf("%d\n", printf("%.2p<end>\n", p));
	printf("%d\n", ft_printf("%.2p<end>\n", p));
	printf("%d\n", printf("%20p<end>\n", (void *)0));
	printf("%d\n", ft_printf("%20p<end>\n", (void *)0));
	printf("%d\n", printf("%020p<end>\n", p));
	printf("%d\n", ft_printf("%020p<end>\n", p));
	printf("%d\n", printf("%-20p<end>\n", p));
	printf("%d\n", ft_printf("%-20p<end>\n", p));
	printf("%d\n", printf("%20.30p<end>\n", p));
	printf("%d\n", ft_printf("%20.30p<end>\n", p));
	printf("%d\n", printf("%-40.30p<end>\n", p));
	printf("%d\n", ft_printf("%-40.30p<end>\n", p));
	printf("%d\n", printf("%40.30p<end>\n", p));
	printf("%d\n", ft_printf("%40.30p<end>\n", p));
	printf("%d\n", printf("%040.30p<end>\n", p));
	printf("%d\n", ft_printf("%040.30p<end>\n", p));
	printf("%d\n", printf("% p<end>\n", p));
	printf("%d\n", ft_printf("% p<end>\n", p));
	printf("%d\n", printf("%+p<end>\n", p));
	printf("%d\n", ft_printf("%+p<end>\n", p));
	printf("%d\n", printf("%#p<end>\n", p));
	printf("%d\n", ft_printf("%#p<end>\n", p));
	printf("\n");

	return (0);
}
