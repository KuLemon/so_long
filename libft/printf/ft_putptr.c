/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckhondji <ckhondji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 18:10:56 by ckhondji          #+#    #+#             */
/*   Updated: 2025/12/08 16:55:05 by ckhondji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *ptr)
{
	unsigned long long	adress;
	int					count;

	if (ptr == NULL)
		return (ft_putstr("(nil)"));
	adress = (unsigned long long)ptr;
	count = 0;
	count += ft_putstr("0x");
	count += ft_puthex_lower(adress);
	return (count);
}
