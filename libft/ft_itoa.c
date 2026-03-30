/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckhondji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 12:10:12 by ckhondji          #+#    #+#             */
/*   Updated: 2025/11/24 18:01:48 by ckhondji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_tens(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
	{
		i++;
	}
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static void	ft_stockn(int n, char *str, int *i)
{
	if (n > 9)
	{
		ft_stockn(n / 10, str, i);
		ft_stockn(n % 10, str, i);
	}
	else
	{
		str[(*i)++] = n + '0';
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		tens;

	tens = ft_tens(n);
	i = 0;
	str = ft_calloc(tens + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	if (n == -2147483648)
	{
		return (ft_memcpy(str, "-2147483648", 12));
	}
	else if (n == 0)
	{
		str[i] = '0';
		return (str);
	}
	if (n < 0)
	{
		str[i++] = '-';
		n = n * -1;
	}
	ft_stockn(n, str, &i);
	return (str);
}
/*
int main()
{
	char *str = ft_itoa(-145);
	printf("%s", str);
	//printf("%d", ft_tens(-33130));
}*/
