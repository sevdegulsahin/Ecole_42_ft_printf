/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sevdsahi <sevdsahi@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 13:52:38 by sevdsahi          #+#    #+#             */
/*   Updated: 2026/09/23 14:35:05 by sevdsahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *string, ...);

int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_put_ptr(void *ptr);
int	ft_putnbr(int n);
int	ft_put_unbr(unsigned int n);
int	ft_put_x(unsigned int n);
int	ft_put_upper_x(unsigned int n);

#endif