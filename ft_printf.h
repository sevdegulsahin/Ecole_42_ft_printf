#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>

/* Ana Fonksiyon */
int ft_printf(const char *string, ...);

/* Yardımcı (Helper) Fonksiyonlar */
int ft_putchar(char c);
int ft_putstr(char *s);
int ft_put_ptr(void *ptr);
int ft_putnbr(int n);
int ft_put_unbr(unsigned int n);
int ft_put_x(unsigned int n);
int ft_put_upper_x(unsigned int n);

#endif