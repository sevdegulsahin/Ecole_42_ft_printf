/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sevdsahi <sevdsahi@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 13:52:26 by sevdsahi          #+#    #+#             */
/*   Updated: 2026/09/23 14:34:55 by sevdsahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
