/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckhondji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 14:32:22 by ckhondji          #+#    #+#             */
/*   Updated: 2025/11/07 17:22:08 by ckhondji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(void *s1, void *s2, size_t n)
{
	size_t			i;
	int				value;
	unsigned char	*char_s1;
	unsigned char	*char_s2;

	value = 0;
	i = 0;
	char_s1 = (unsigned char *) s1;
	char_s2 = (unsigned char *) s2;
	while (i < n)
	{
		if (value != 0)
		{
			return (value);
		}
		value = *char_s1 - *char_s2;
		char_s1++;
		char_s2++;
		i++;
	}
	return (value);
}
/*
int main()
{
	char	*s1 = "ABC";
	char	*s2 = "ABD";
	printf("%d", ft_memcmp(s1, s2, 3));
}*/
