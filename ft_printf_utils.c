#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	len;

	if (!s)
		s = "(null)";
	len = 0;
	while (s[len])
	{
		ft_putchar(s[len]);
		len++;
	}
	return (len);
}

int	ft_putnbr_base(unsigned long n, int base, char *chars)
{
	int	count;

	count = 0;
	if (n >= (unsigned long)base)
		count += ft_putnbr_base(n / (unsigned long)base, base, chars);
	count += ft_putchar(chars[n % (unsigned long)base]);
	return (count);
}

int	ft_print_signed(long n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		count += ft_putchar('-');
		count += ft_putnbr_base((unsigned long)(-n), 10, "0123456789");
	}
	else
		count += ft_putnbr_base((unsigned long)n, 10, "0123456789");
	return (count);
}

int	ft_print_ptr(unsigned long ptr)
{
	int	count;

	count = 0;
	count += ft_putchar('0');
	count += ft_putchar('x');
	if (ptr == 0)
		count += ft_putchar('0');
	else
		count += ft_putnbr_base(ptr, 16, "0123456789abcdef");
	return (count);
}
