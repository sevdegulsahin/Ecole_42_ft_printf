/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sevdsahi <sevdsahi@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 13:52:14 by sevdsahi          #+#    #+#             */
/*   Updated: 2026/09/23 19:24:25 by sevdsahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
