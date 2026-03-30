/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckhondji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 16:55:05 by ckhondji          #+#    #+#             */
/*   Updated: 2025/12/03 17:46:50 by ckhondji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (*str != '\0')
	{
		i++;
		str++;
	}
	return (i);
}

int	ft_putstr(const char *str)
{
	int	i;

	if (str == NULL)
	{
		return (ft_putstr("(null)"));
	}
	i = ft_strlen(str);
	write(1, str, i);
	return (i);
}
