#include <stdio.h>
#include "../ft_printf.h"
#include "../libft/libft.h"
static void	foo(int n, ...);
int	main(void)
{
	// return value tests
/*	int c = printf("", "hello");
	printf("%d\n", c); // 0 is returned
	int c2 = printf("%c", "hello");
	printf("%d\n", c2); // something is returned -> in man pages, it will return negative value if error occurs.
	int c3 = printf("%v", "hello");
	printf("%d\n", c3);
*/
	// %d tests
/*	printf("%d\n", 9223372036854775806); // this prints -2.
	printf("%d\n", 9223372036854775808); // this prints 0.
	printf("%d\n", -9223372036854775809); // and this printfs -1. -> the values will be -2, 0, -1 if the arguments of printf are assigned to int variable.
	//just treat number argument as int. no other processes are needed
*/	
	// format string tests
/*	printf("%d %d %d\n", 1, 2); // last %d prints some garbage value.
	printf("%d %d %d\n", 1, 2, 3, 4); // 4 is ignored.
	// with -Werror option, lines above can't be compiled because warnings become errors.
*/	
	// %x testx
/*	printf("%x\n", 2147483647);
	printf("%x\n", -2147483648);
	printf("%x\n", 2147483649);
	printf("%x\n", -2147483649);
	// just print hexa-decimal value for every 2 bytes.
*/	
	// %d, %i tests
/*	printf("%d\n", 017);
	printf("%i\n", 017);
*/
	// pointer tests
/*	void				*p;

	printf("%p\n", p);
	foo(1, p);
	*/

	// unsigned int tests
	printf("-2147483648: %u\n", -2147483648);
	printf("2147483647: %u\n", 2147483647);
	printf("-2147483649: %u\n", -2147483649);
	printf("2147483548: %u\n", 2147483648);
	printf("9223372036854775807: %u\n", 9223372036854775807);
	printf("-9223372036854775808: %u\n", -9223372036854775808);
	printf("9223372036854775808: %u\n", 9223372036854775808);
	printf("-9223372036854775809: %u\n", -9223372036854775809);

	return (0);
}

static void	foo(int n, ...)
{
	va_list				ap;
	unsigned long long	ull;

	va_start(ap, n);
	ull = va_arg(ap, unsigned long long);
	printf("%llu\n", ull);
	printf("%llx\n", ull);
	va_end(ap);
}
