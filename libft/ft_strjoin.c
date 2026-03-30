/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckhondji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 16:29:20 by ckhondji          #+#    #+#             */
/*   Updated: 2025/11/24 17:39:13 by ckhondji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_lenstr(char const *str)
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len1;
	int		len2;
	char	*tab;

	len1 = ft_lenstr(s1);
	len2 = ft_lenstr(s2);
	tab = ft_calloc((len1 + len2 + 1), sizeof(char));
	if (tab == NULL)
		return (NULL);
	while (*s1 != '\0')
	{
		*tab = *s1;
		tab++;
		s1++;
	}
	while (*s2 != '\0')
	{
		*tab = *s2;
		tab++;
		s2++;
	}
	return (tab - (len1 + len2));
}
/*
int main()
{
	char str1[] = "123";
	char str2[] = "456";

	printf("%s", ft_strjoin(str1, str2));
}*/
