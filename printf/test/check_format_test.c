#include <stdio.h>
#include "../ft_printf.h"
#include "../libft/libft.h"
int	check_format(const char *format);
int	main(void)
{
	printf("%d\n", check_format("       "));
	printf("%d\n", check_format(""));
	printf("%d\n", check_format("%c"));
	printf("%d\n", check_format("%cs"));
	printf("%d\n", check_format("%c%s"));
	printf("%d\n", check_format("%b"));
	return (0);
}

int	check_format(const char *format)
{
	int			count;

	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			if (ft_strchr(VALID_SET, *(format + 1)))
			{
				format++;
				count++;
			}
			else
				return (-1);
		}
		format++;
	}
	return (count);
}

