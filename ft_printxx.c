/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printxx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sevdsahi <sevdsahi@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 13:52:44 by sevdsahi          #+#    #+#             */
/*   Updated: 2026/09/23 19:25:16 by sevdsahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
