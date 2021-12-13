#include "ft_printf.h"
int	print_s(va_list *ap)
{
	char	*str;

	str = va_arg(*ap, char *);
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}
