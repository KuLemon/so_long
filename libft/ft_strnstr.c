/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckhondji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 17:04:29 by ckhondji          #+#    #+#             */
/*   Updated: 2025/11/22 17:20:41 by ckhondji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;
	size_t		j;
	const char	*tmp_big;

	tmp_big = big;
	i = 0;
	j = 0;
	if (*little == '\0')
		return ((char *) big);
	while (big[i] && i < len)
	{
		while (big[i + j] == little[j] && i + j < len && big[i + j])
		{
			j++;
			if (little[j] == 0)
				return ((char *)tmp_big + i);
		}
		j = 0;
		i++;
	}
	return (0);
}
/*
int main()
{
	const char big[] = "ajstestqwhb";
	const char little[] = "test";
	printf("%s", ft_strnstr(big, little, 0));
}*/
