/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckhondji <ckhondji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 18:36:57 by ckhondji          #+#    #+#             */
/*   Updated: 2025/12/04 20:14:38 by ckhondji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putlnbr(long long n)
{
	int	i;

	i = 0;
	if (n == -4294967296)
		return (ft_putstr("-4294967296"));
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
		i = 1;
	}
	if (n > 9)
	{
		i += ft_putnbr(n / 10);
		i += ft_putnbr(n % 10);
	}
	else
	{
		i += ft_putchar(n + '0');
	}
	return (i);
}

int	ft_putunbr(unsigned int n)
{
	int	i;

	i = 0;
	if ((int) n < 0)
	{
		i += ft_putlnbr(n);
	}
	else if (n > 9)
	{
		i += ft_putnbr(n);
	}
	else
	{
		i += ft_putchar(n + '0');
	}
	return (i);
}
