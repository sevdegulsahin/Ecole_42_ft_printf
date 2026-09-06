#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbr_base(unsigned long n, int base, char *chars);
int	ft_print_signed(long n);
int	ft_print_ptr(unsigned long ptr);

#endif
