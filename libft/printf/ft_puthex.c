/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckhondji <ckhondji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 19:33:16 by ckhondji          #+#    #+#             */
/*   Updated: 2025/12/04 19:23:35 by ckhondji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_upper(unsigned int n)
{
	unsigned int	last_digit;
	char			hex_char;
	int				count;

	count = 0;
	if (n >= 16)
	{
		count += ft_puthex_upper(n / 16);
	}
	last_digit = n % 16;
	if (last_digit < 10)
	{
		hex_char = last_digit + '0';
	}
	else
	{
		hex_char = last_digit - 10 + 'A';
	}
	count += ft_putchar(hex_char);
	return (count);
}

int	ft_puthex_lower(unsigned long long n)
{
	unsigned long long	last_digit;
	char				hex_char;
	int					count;

	count = 0;
	if (n >= 16)
	{
		count += ft_puthex_lower(n / 16);
	}
	last_digit = n % 16;
	if (last_digit < 10)
	{
		hex_char = last_digit + '0';
	}
	else
	{
		hex_char = last_digit - 10 + 'a';
	}
	count += ft_putchar(hex_char);
	return (count);
}
