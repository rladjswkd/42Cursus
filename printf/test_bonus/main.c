#include "ft_printf_bonus.h"
#include <stdio.h>
#include <limits.h>
int	main(void)
{
	void	*p;


	printf("%d\n", printf("%dabcd%2147483647.2d\n", 12, 1));
	printf("%d\n", ft_printf("%dabcd%2147483647.2d\n", 12, 1));

	printf("%d\n", printf("abcd%2.2147483647d %d\n", 12, 1));
	printf("%d\n", ft_printf("abcd%2.2147483647d %d\n", 12, 1));

	printf("%-10{7.8d\n", 12);
	ft_printf("%-10{7.8d\n", 12);
	printf("%d\n", printf("%2147483647d\n", 12, 1));
	printf("%d\n", ft_printf("%2147483647d\n", 12, 1));
	printf("%d\n", printf("%.2147483647d\n", 12, 1));
	printf("%d\n", ft_printf("%.2147483647d\n", 12, 1));

	printf("%\n", 12);
	printf("%-3.3%\n", 0);
	ft_printf("%-3.3%\n\n", 0);
	printf("%030d\n", 12);
	ft_printf("%030d\n\n", 12);
	printf("%3-3d\n", 12);
	ft_printf("%3-3d\n\n", 12);
	printf("%dd\n", 12);
	ft_printf("%dd\n\n", 12);
	printf("%0+03d\n", 12);
	ft_printf("%0+03d\n\n", 12);

	printf("%d\n", printf("%030.40%<end>\n", 12)); // precision is ignored.
	printf("%d\n", ft_printf("%030.40%<end>\n", 12));

	printf("%d\n", printf("%030%<end>\n", 12)); // 0 flag is not ignored.
	printf("%d\n", ft_printf("%030%<end>\n", 12));

	printf("%d\n", printf("%-030%<end>\n", 12)); // - flag is not ignored.
	printf("%d\n", ft_printf("%-030%<end>\n", 12));

	printf("%d\n", printf("%-030.40%<end>\n", 12));
	printf("%d\n", ft_printf("%-030.40%<end>\n", 12));

	printf("%d\n", printf("%30%<end>\n", 12));
	printf("%d\n", ft_printf("%30%<end>\n", 12));

	printf(" %#x \n", 0);
	ft_printf(" %#x \n", 0);
	printf(" %#x \n", LONG_MIN); 
	ft_printf(" %#x \n", LONG_MIN); 
	printf(" %#X %#X %#X %#X %#X %#X %#X\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	ft_printf(" %#X %#X %#X %#X %#X %#X %#X\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	
	printf("%2x\n", 1);
	ft_printf("%2x\n", 1);

	printf("%10.d<end>\n", 0);
	ft_printf("%10.d<end>\n", 0);
	printf("%10.0d<end>\n", 1);
	ft_printf("%10.0d<end>\n", 1);
	printf("%.d<end>\n", 0);
	ft_printf("%.d<end>\n", 0);
	printf("%.0d<end>\n", 0);
	ft_printf("%.0d<end>\n", 0);
	printf("%.d<end>\n", 1);
	ft_printf("%.d<end>\n", 1);
	printf("%.0d<end>\n", 1);
	ft_printf("%.0d<end>\n", 1);

	printf("%.u<end>\n", 0);
	ft_printf("%.u<end>\n", 0);
	printf("%.0u<end>\n", 0);
	ft_printf("%.0u<end>\n", 0);
	printf("%.u<end>\n", 1);
	ft_printf("%.u<end>\n", 1);
	printf("%.0u<end>\n", 1);
	ft_printf("%.0u<end>\n", 1);
	
	printf("%.x<end>\n", 0);
	ft_printf("%.x<end>\n", 0);
	printf("%.0x<end>\n", 0);
	ft_printf("%.0x<end>\n", 0);
	printf("%.x<end>\n", 1);
	ft_printf("%.x<end>\n", 1);
	printf("%.0x<end>\n", 1);
	ft_printf("%.0x<end>\n", 1);
	printf("%.X<end>\n", 0);
	ft_printf("%.X<end>\n", 0);
	printf("%.0X<end>\n", 0);
	ft_printf("%.0X<end>\n", 0);
	printf("%.X<end>\n", 1);
	ft_printf("%.X<end>\n", 1);
	printf("%.0X<end>\n", 1);
	ft_printf("%.0X<end>\n", 1);
	
	void	*np = 0;
	printf("%.p<end>\n", np);
	ft_printf("%.p<end>\n", np);
	printf("%.0p<end>\n", np);
	ft_printf("%.0p<end>\n", np);
	printf("%.p<end>\n", p);
	ft_printf("%.p<end>\n", p);
	printf("%.0p<end>\n", p);
	ft_printf("%.0p<end>\n", p);
	
	
	printf("%01.x<end>\n", 0);
	ft_printf("%01.x<end>\n", 0);
	printf("%01.d<end>\n", 0);
	ft_printf("%01.d<end>\n", 0);
	printf("%01.i<end>\n", 0);
	ft_printf("%01.i<end>\n", 0);
	printf("%01.u<end>\n", 0);
	ft_printf("%01.u<end>\n", 0);
	
	//%c
			
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
	
	//printf("%-x\n", 26);
	//printf("%0x\n", 26);
	//printf("% x\n", 26);
	//printf("%+x\n", 26);
	//printf("%#x\n", 26);
	//printf("%10x\n", 26);
	//printf("%.10x\n", 26);
	//printf("%d\n", printf("%#10x\n", 26));
	//printf("%d\n", printf("%#.10x\n", 26));

	//printf("%-X\n", 26);
	//printf("%0X\n", 26);
	//printf("% X\n", 26);
	//printf("%+X\n", 26);
	//printf("%#X\n", 26);
	//printf("%10X\n", 26);
	//printf("%.10X\n", 26);
	//printf("%d\n", printf("%#10X\n", 26));
	//printf("%d\n", printf("%#.10X\n", 26));

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
	return (0);
}
