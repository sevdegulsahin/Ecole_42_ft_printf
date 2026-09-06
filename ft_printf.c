#include "ft_printf.h"

static int	ft_handle(char spec, va_list *args)
{
	if (spec == 'c')
		return (ft_putchar((char)va_arg(*args, int)));
	if (spec == 's')
		return (ft_putstr(va_arg(*args, char *)));
	if (spec == 'p')
		return (ft_print_ptr((unsigned long)va_arg(*args, void *)));
	if (spec == 'd' || spec == 'i')
		return (ft_print_signed((long)va_arg(*args, int)));
	if (spec == 'u')
		return (ft_putnbr_base((unsigned long)va_arg(*args, unsigned int),
				10, "0123456789"));
	if (spec == 'x')
		return (ft_putnbr_base((unsigned long)va_arg(*args, unsigned int),
				16, "0123456789abcdef"));
	if (spec == 'X')
		return (ft_putnbr_base((unsigned long)va_arg(*args, unsigned int),
				16, "0123456789ABCDEF"));
	if (spec == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;

	if (!format)
		return (-1);
	va_start(args, format);
	count = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			count += ft_handle(format[i], &args);
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
