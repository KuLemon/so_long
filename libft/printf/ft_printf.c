/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckhondji <ckhondji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 16:50:28 by ckhondji          #+#    #+#             */
/*   Updated: 2025/12/04 19:28:47 by ckhondji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_var(const char *s, va_list args)
{
	if (*(s + 1) == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (*(s + 1) == 's')
		return (ft_putstr(va_arg(args, const char *)));
	if (*(s + 1) == 'p')
		return (ft_putptr(va_arg(args, void *)));
	if (*(s + 1) == 'd' || *(s + 1) == 'i')
		return (ft_putnbr(va_arg(args, int)));
	if (*(s + 1) == 'u')
		return (ft_putunbr(va_arg(args, unsigned int)));
	if (*(s + 1) == 'x')
		return (ft_puthex_lower(va_arg(args, unsigned int)));
	if (*(s + 1) == 'X')
		return (ft_puthex_upper(va_arg(args, unsigned int)));
	if (*(s + 1) == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		tmp;
	va_list	args;

	i = 0;
	tmp = 0;
	if (!s)
		return (-1);
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			tmp += handle_var(s + i, args);
			i++;
		}
		else
			tmp += ft_putchar(s[i]);
		i++;
	}
	va_end(args);
	return (tmp);
}
