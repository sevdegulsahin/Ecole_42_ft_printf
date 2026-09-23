/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sevdsahi <sevdsahi@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 13:52:32 by sevdsahi          #+#    #+#             */
/*   Updated: 2026/09/23 19:23:18 by sevdsahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_handle(char spec, va_list args)
{
	if (spec == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (spec == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (spec == 'p')
		return (ft_put_ptr(va_arg(args, void *)));
	else if (spec == 'd' || spec == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (spec == 'u')
		return (ft_put_unbr(va_arg(args, unsigned int)));
	else if (spec == 'x')
		return (ft_put_x(va_arg(args, unsigned int)));
	else if (spec == 'X')
		return (ft_put_upper_x(va_arg(args, unsigned int)));
	else if (spec == '%')
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
		if (format[i] == '%')
		{
			i++;
			if (!format[i])
				break ;
			count += ft_handle(format[i], args);
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
