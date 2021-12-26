#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
int	main(void)
{
	/*
	printf(" %#x \n", 0);
	ft_printf(" %#x \n", 0);
	printf(" %#x \n", LONG_MIN); 
	ft_printf(" %#x \n", LONG_MIN); 
	printf(" %#X %#X %#X %#X %#X %#X %#X\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	ft_printf(" %#X %#X %#X %#X %#X %#X %#X\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	*/
	printf("%2x\n", 1);
	ft_printf("%2x\n", 1);
	//%c
	/*		
	printf("%d\n", printf("%-5c<end>\n", 'a'));
	printf("%d\n", ft_printf("%-5c<end>\n", 'a'));
	ft_printf("\n");
	printf("%d\n", printf("% c<end>\n", 'a'));
	printf("%d\n", ft_printf("% c<end>\n", 'a'));
	ft_printf("\n");
	printf("%d\n", printf("%05c<end>\n", 'a'));
	printf("%d\n", ft_printf("%05c<end>\n", 'a'));
	ft_printf("\n");	
	printf("%d\n", printf("%.5c<end>\n", 'a'));
	printf("%d\n", ft_printf("%.5c<end>\n", 'a'));
	ft_printf("\n");
	printf("%d\n", printf("%+c<end>\n", 'a'));
	printf("%d\n", ft_printf("%+c<end>\n", 'a'));
	ft_printf("\n");
	printf("%d\n", printf("%#c<end>\n", 'a'));
	printf("%d\n", ft_printf("%#c<end>\n", 'a'));
	ft_printf("\n");
	printf("%d\n", printf("%-05c<end>\n", 'a'));
	printf("%d\n", ft_printf("%-05c<end>\n", 'a'));
	ft_printf("\n");
	printf("%d\n", printf("%010.5c<end>\n", 'a'));
	printf("%d\n", ft_printf("%010.5c<end>\n", 'a'));
	ft_printf("\n");
	printf("%d\n", printf("%010.c<end>\n", 'a'));
	printf("%d\n", ft_printf("%010.c<end>\n", 'a'));
	ft_printf("\n");
	printf("\n");

	//%s
	printf("%d\n", printf("%010s<end>\n", (void *)0));
	printf("%d\n", ft_printf("%010s<end>\n", (void *)0));
	ft_printf("\n");
	printf("%d\n", printf("%.4s<end>\n", (void *)0));
	printf("%d\n", ft_printf("%.4s<end>\n", (void *)0));
	ft_printf("\n");
	printf("%d\n", printf("%.10s<end>\n", (void *)0));
	printf("%d\n", ft_printf("%.10s<end>\n", (void *)0));
	ft_printf("\n");
	printf("%d\n", printf("%-5s<end>\n", "abc"));
	printf("%d\n", ft_printf("%-5s<end>\n", "abc"));
	ft_printf("\n");
	printf("%d\n", printf("%5s<end>\n", "abc"));
	printf("%d\n", ft_printf("%5s<end>\n", "abc"));
	ft_printf("\n");
	printf("%d\n", printf("% s\n", "abc"));
	printf("%d\n", ft_printf("% s\n", "abc"));
	ft_printf("\n");
	printf("%d\n", printf("%05s\n", "abc"));
	printf("%d\n", ft_printf("%05s\n", "abc"));
	ft_printf("\n");
	printf("%d\n", printf("%.5s\n", "abc"));
	printf("%d\n", ft_printf("%.5s\n", "abc"));
	ft_printf("\n");
	printf("%d\n", printf("%.2s\n", "abc"));
	printf("%d\n", ft_printf("%.2s\n", "abc"));
	ft_printf("\n");
	printf("%d\n", printf("%6.2s<end>\n", "abc"));
	printf("%d\n", ft_printf("%6.2s<end>\n", "abc"));
	ft_printf("\n");
	printf("%d\n", printf("%+s\n", "abc"));
	printf("%d\n", ft_printf("%+s\n", "abc"));
	ft_printf("\n");
	printf("%d\n", printf("%#s\n", "abc"));
	printf("%d\n", ft_printf("%#s\n", "abc"));
	ft_printf("\n");
	printf("\n");

	//%p
	void	*p;
	printf("%d\n", printf("%-20.30p<end>\n", p));
	printf("%d\n", ft_printf("%-20.30p<end>\n", p));
	ft_printf("\n");
	printf("%d\n", printf("%p<end>\n", p));
	printf("%d\n", ft_printf("%p<end>\n", p));
	ft_printf("\n");
	printf("%d\n", printf("%.2p<end>\n", p));
	printf("%d\n", ft_printf("%.2p<end>\n", p));
	ft_printf("\n");
	printf("%d\n", printf("%20p<end>\n", (void *)0));
	printf("%d\n", ft_printf("%20p<end>\n", (void *)0));
	ft_printf("\n");
	printf("%d\n", printf("%020p<end>\n", p));
	printf("%d\n", ft_printf("%020p<end>\n", p));
	ft_printf("\n");
	printf("%d\n", printf("%-20p<end>\n", p));
	printf("%d\n", ft_printf("%-20p<end>\n", p));
	ft_printf("\n");
	printf("%d\n", printf("%20.30p<end>\n", p));
	printf("%d\n", ft_printf("%20.30p<end>\n", p));
	ft_printf("\n");
	printf("%d\n", printf("%-20.30p<end>\n", p));
	printf("%d\n", ft_printf("%-20.30p<end>\n", p));
	ft_printf("\n");
	printf("%d\n", printf("%-40.30p<end>\n", p));
	printf("%d\n", ft_printf("%-40.30p<end>\n", p));
	ft_printf("\n");
	printf("%d\n", printf("%40.30p<end>\n", p));
	printf("%d\n", ft_printf("%40.30p<end>\n", p));
	ft_printf("\n");
	printf("%d\n", printf("%040.30p<end>\n", p));
	printf("%d\n", ft_printf("%040.30p<end>\n", p));
	ft_printf("\n");
	printf("%d\n", printf("% p<end>\n", p));
	printf("%d\n", ft_printf("% p<end>\n", p));
	ft_printf("\n");
	printf("%d\n", printf("%+p<end>\n", p));
	printf("%d\n", ft_printf("%+p<end>\n", p));
	ft_printf("\n");
	printf("%d\n", printf("%#p<end>\n", p));
	printf("%d\n", ft_printf("%#p<end>\n", p));
	ft_printf("\n");
	printf("\n");

	//%u
	printf("%d\n", printf("%-u<end>\n", 123));
	printf("%d\n", ft_printf("%-u<end>\n", 123));
	ft_printf("\n");
	printf("%d\n", printf("%0u<end>\n", 123));
	printf("%d\n", ft_printf("%0u<end>\n", 123));
	ft_printf("\n");
	printf("%d\n", printf("%+u<end>\n", 123));
	printf("%d\n", ft_printf("%+u<end>\n", 123));
	ft_printf("\n");
	printf("%d\n", printf("% u<end>\n", 123));
	printf("%d\n", ft_printf("% u<end>\n", 123));
	ft_printf("\n");
	printf("%d\n", printf("%#u<end>\n", 123));
	printf("%d\n", ft_printf("%#u<end>\n", 123));
	ft_printf("\n");
	printf("%d\n", printf("%10u<end>\n", 123));
	printf("%d\n", ft_printf("%10u<end>\n", 123));
	ft_printf("\n");
	printf("%d\n", printf("%1u<end>\n", 123));
	printf("%d\n", ft_printf("%1u<end>\n", 123));
	ft_printf("\n");
	printf("%d\n", printf("%.1u<end>\n", 123));
	printf("%d\n", ft_printf("%.1u<end>\n", 123));
	ft_printf("\n");
	printf("%d\n", printf("%.10u<end>\n", 123));
	printf("%d\n", ft_printf("%.10u<end>\n", 123));
	ft_printf("\n");
	printf("%d\n", printf("%01u<end>\n", 123));
	printf("%d\n", ft_printf("%01u<end>\n", 123));
	ft_printf("\n");
	printf("%d\n", printf("%010u<end>\n", 123));
	printf("%d\n", ft_printf("%010u<end>\n", 123));
	ft_printf("\n");
	printf("%d\n", printf("%-0u<end>\n", 123));
	printf("%d\n", ft_printf("%-0u<end>\n", 123));
	ft_printf("\n");
	printf("%d\n", printf("%-1u<end>\n", 123));
	printf("%d\n", ft_printf("%-1u<end>\n", 123));
	ft_printf("\n");
	printf("%d\n", printf("%-10u<end>\n", 123));
	printf("%d\n", ft_printf("%-10u<end>\n", 123));
	ft_printf("\n");
	printf("%d\n", printf("%-.1u<end>\n", 123));
	printf("%d\n", ft_printf("%-.1u<end>\n", 123));
	ft_printf("\n");
	printf("%d\n", printf("%-.10u<end>\n", 123));
	printf("%d\n", ft_printf("%-.10u<end>\n", 123));
	ft_printf("\n");
	printf("%d\n", printf("%1.1u<end>\n", 123));
	printf("%d\n", ft_printf("%1.1u<end>\n", 123));
	ft_printf("\n");
	printf("%d\n", printf("%1.10u<end>\n", 123));
	printf("%d\n", ft_printf("%1.10u<end>\n", 123));
	ft_printf("\n");
	printf("%d\n", printf("%10.1u<end>\n", 123));
	printf("%d\n", ft_printf("%10.1u<end>\n", 123));
	ft_printf("\n");
	printf("%d\n", printf("%10.10u<end>\n", 123));
	printf("%d\n", ft_printf("%10.10u<end>\n", 123));
	ft_printf("\n");
	printf("%d\n", printf("%-20.10u<end>\n", 123));
	printf("%d\n", ft_printf("%-20.10u<end>\n", 123));
	ft_printf("\n");
	printf("%d\n", printf("%20.10u<end>\n", 123));
	printf("%d\n", ft_printf("%20.10u<end>\n", 123));
	ft_printf("\n");
	printf("%d\n", printf("%020.10u<end>\n", 123));
	printf("%d\n", ft_printf("%020.10u<end>\n", 123));
	ft_printf("\n");
	ft_printf("\n");

	// %x %X
	printf("%-x\n", 26);
	printf("%0x\n", 26);
	printf("% x\n", 26);
	printf("%+x\n", 26);
	printf("%#x\n", 26);
	printf("%10x\n", 26);
	printf("%.10x\n", 26);
	printf("%d\n", printf("%#10x\n", 26));
	printf("%d\n", printf("%#.10x\n", 26));

	printf("%-X\n", 26);
	printf("%0X\n", 26);
	printf("% X\n", 26);
	printf("%+X\n", 26);
	printf("%#X\n", 26);
	printf("%10X\n", 26);
	printf("%.10X\n", 26);
	printf("%d\n", printf("%#10X\n", 26));
	printf("%d\n", printf("%#.10X\n", 26));
	
	printf("%d\n", printf("%-#10.20X<end>\n", 26));
	printf("%d\n", ft_printf("%-#10.20X<end>\n", 26));
	ft_printf("\n");

	printf("%d\n", printf("%-#20.10X<end>\n", 26));
	printf("%d\n", ft_printf("%-#20.10X<end>\n", 26));
	ft_printf("\n");

	printf("%d\n", printf("%0#10.20X<end>\n", 26));
	printf("%d\n", ft_printf("%0#10.20X<end>\n", 26));
	ft_printf("\n");

	printf("%d\n", printf("%0#20.10X<end>\n", 26));
	printf("%d\n", ft_printf("%0#20.10X<end>\n", 26));
	ft_printf("\n");

	printf("%d\n", printf("%0-10.20X<end>\n", 26));
	printf("%d\n", ft_printf("%0-10.20X<end>\n", 26));
	ft_printf("\n");

	printf("%d\n", printf("%0-20.10X<end>\n", 26));
	printf("%d\n", ft_printf("%0-20.10X<end>\n", 26));
	ft_printf("\n");

	printf("%d\n", printf("%0-#.10X<end>\n", 26));
	printf("%d\n", ft_printf("%0-#.10X<end>\n", 26));
	ft_printf("\n");

	printf("%d\n", printf("%0-#.X<end>\n", 26));
	printf("%d\n", ft_printf("%0-#.X<end>\n", 26));
	ft_printf("\n");

	printf("%d\n", printf("%0-#10X<end>\n", 26));
	printf("%d\n", ft_printf("%0-#10X<end>\n", 26));
	ft_printf("\n");

	printf("%d\n", printf("%0-#0X<end>\n", 26));
	printf("%d\n", ft_printf("%0-#0X<end>\n", 26));
	ft_printf("\n");

	printf("%d\n", printf("%0-#20.19X<end>\n", 26));
	printf("%d\n", ft_printf("%0-#20.19X<end>\n", 26));
	ft_printf("\n");

	printf("%d\n", printf("%-#10.20x<end>\n", 26));
	printf("%d\n", ft_printf("%-#10.20x<end>\n", 26));
	ft_printf("\n");

	printf("%d\n", printf("%-#20.10x<end>\n", 26));
	printf("%d\n", ft_printf("%-#20.10x<end>\n", 26));
	ft_printf("\n");

	printf("%d\n", printf("%0#10.20x<end>\n", 26));
	printf("%d\n", ft_printf("%0#10.20x<end>\n", 26));
	ft_printf("\n");

	printf("%d\n", printf("%0#20.10x<end>\n", 26));
	printf("%d\n", ft_printf("%0#20.10x<end>\n", 26));
	ft_printf("\n");

	printf("%d\n", printf("%0-10.20x<end>\n", 26));
	printf("%d\n", ft_printf("%0-10.20x<end>\n", 26));
	ft_printf("\n");

	printf("%d\n", printf("%0-20.10x<end>\n", 26));
	printf("%d\n", ft_printf("%0-20.10x<end>\n", 26));
	ft_printf("\n");

	printf("%d\n", printf("%0-#.10x<end>\n", 26));
	printf("%d\n", ft_printf("%0-#.10x<end>\n", 26));
	ft_printf("\n");

	printf("%d\n", printf("%0-#.x<end>\n", 26));
	printf("%d\n", ft_printf("%0-#.x<end>\n", 26));
	ft_printf("\n");

	printf("%d\n", printf("%0-#10x<end>\n", 26));
	printf("%d\n", ft_printf("%0-#10x<end>\n", 26));
	ft_printf("\n");

	printf("%d\n", printf("%0-#0x<end>\n", 26));
	printf("%d\n", ft_printf("%0-#0x<end>\n", 26));
	ft_printf("\n");

	printf("%d\n", printf("%0-#20.19x<end>\n", 26));
	printf("%d\n", ft_printf("%0-#20.19x<end>\n", 26));
	ft_printf("\n");

	printf("%d\n", printf("%0#10x<end>\n", 31));
	printf("%d\n", ft_printf("%0#10x<end>\n", 31));
	ft_printf("\n");

	printf("%d\n", printf("%0#.10x<end>\n", 31));
	printf("%d\n", ft_printf("%0#.10x<end>\n", 31));
	ft_printf("\n");

	printf("%d\n", printf("%010x<end>\n", 31));
	printf("%d\n", ft_printf("%010x<end>\n", 31));
	ft_printf("\n");

	printf("%d\n", printf("%0.10x<end>\n", 31));
	printf("%d\n", ft_printf("%0.10x<end>\n", 31));
	ft_printf("\n");
	ft_printf("\n");
	
	// %d, %i
	printf("%0d\n", 42);
	ft_printf("%0d\n", 42);
	printf("%-d\n", 42);
	ft_printf("%-d\n", 42);
	printf("%+d\n", 42);
	ft_printf("%+d\n", 42);
	printf("% d\n", 42);
	ft_printf("% d\n", 42);
	printf("%#d\n", 42);
	ft_printf("%#d\n", 42);
	printf("%10d\n", 42);
	ft_printf("%10d\n", 42);
	printf("%.10d\n", 42);
	ft_printf("%.10d\n", 42);

	printf("%0i\n", 42);
	ft_printf("%0i\n", 42);
	printf("%-i\n", 42);
	ft_printf("%-i\n", 42);
	printf("%+i\n", 42);
	ft_printf("%+i\n", 42);
	printf("% i\n", 42);
	ft_printf("% i\n", 42);
	printf("%#i\n", 42);
	ft_printf("%#i\n", 42);
	printf("%10i\n", 42);
	ft_printf("%10i\n", 42);
	printf("%.10i\n", 42);
	ft_printf("%.10i\n", 42);

	printf("%0d\n", -42);
	ft_printf("%0d\n", -42);
	printf("%-d\n", -42);
	ft_printf("%-d\n", -42);
	printf("%+d\n", -42);
	ft_printf("%+d\n", -42);
	printf("% d\n", -42);
	ft_printf("% d\n", -42);
	printf("%#d\n", -42);
	ft_printf("%#d\n", -42);
	printf("%10d\n", -42);
	ft_printf("%10d\n", -42);
	printf("%.10d\n", -42);
	ft_printf("%.10d\n", -42);

	printf("%0i\n", -42);
	ft_printf("%0i\n", -42);
	printf("%-i\n", -42);
	ft_printf("%-i\n", -42);
	printf("%+i\n", -42);
	ft_printf("%+i\n", -42);
	printf("% i\n", -42);
	ft_printf("% i\n", -42);
	printf("%#i\n", -42);
	ft_printf("%#i\n", -42);
	printf("%10i\n", -42);
	ft_printf("%10i\n", -42);
	printf("%.10i\n", -42);
	ft_printf("%.10i\n", -42);
	*/
	return (0);
}
