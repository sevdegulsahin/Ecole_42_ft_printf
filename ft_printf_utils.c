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

int	ft_print_ptr(unsigned long ptr)
{
	int	count;

	if (!ptr)
		return (ft_putstr("(nil)"));
	count = 0;
	count += ft_putchar('0');
	count += ft_putchar('x');
	count += ft_putnbr_base(ptr, 16, "0123456789abcdef");
	return (count);
}

int	ft_putnbr(int n)
{
	int		len;
	long	nbr;

	len = 0;
	nbr = n;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
		len++;
	}
	if (nbr >= 10)
		len += ft_putnbr(nbr / 10);
	len += ft_putchar(nbr % 10 + '0');
	return (len);
}

int	ft_put_unbr(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += ft_put_unbr(n / 10);
	count += ft_putchar((n % 10) + '0');
	return (count);
}

int	ft_put_x(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 16)
		count += ft_put_x(n / 16);
	count += ft_putchar("0123456789abcdef"[n % 16]);
	return (count);
}

int	ft_put_upper_x(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 16)
		count += ft_put_upper_x(n / 16);
	count += ft_putchar("0123456789ABCDEF"[n % 16]);
	return (count);
}
