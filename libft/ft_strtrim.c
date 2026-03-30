/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckhondji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 16:44:29 by ckhondji          #+#    #+#             */
/*   Updated: 2025/11/24 18:15:10 by ckhondji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isset(char const c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
		{
			return (1);
		}
		i++;
	}
	return (0);
}

static char	*ft_createtab(const char *s1, size_t start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	if (len <= 0)
		return (ft_strdup(""));
	str = ft_calloc(len + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	while (i < len)
	{
		str[i] = s1[start + i];
		i++;
	}
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*tab;
	size_t		i;
	size_t		start;
	size_t		end;

	start = 0;
	end = ft_strlen(s1);
	i = 0;
	while (s1[i] != '\0' && ft_isset(s1[i], set) == 1)
	{
		start++;
		i++;
	}
	end = ft_strlen(s1);
	while (end > start && ft_isset(s1[end - 1], set) == 1)
	{
		end--;
	}
	tab = ft_createtab(s1, start, end - start);
	return (tab);
}
/*
int main()
{
	char str[] = " lorem ipsum dolor sit amet";
	printf("%s", ft_strtrim(str, "l "));
}*/
