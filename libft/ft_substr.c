/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckhondji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 14:46:49 by ckhondji          #+#    #+#             */
/*   Updated: 2025/11/24 17:18:03 by ckhondji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_s;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_calloc(1, sizeof(char)));
	if (len > ft_strlen(start + s))
		len = ft_strlen(start + s);
	sub_s = ft_calloc(len + 1, sizeof(char));
	if (!sub_s)
		return (NULL);
	while (i < len)
	{
		sub_s[i] = s[start + i];
		i++;
	}
	return (sub_s);
}

/*
int main(){
	char str[] = "ABCtestABC";
	char *str2 = ft_substr(str, 3, 4);
	printf("%s", str2);
}*/
