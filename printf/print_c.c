#include "ft_printf.h"
int	print_c(va_list *ap)
{
	ft_putchar_fd((char)va_arg(*ap, int), 1);
	return (1);
}
