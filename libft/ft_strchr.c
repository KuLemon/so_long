/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckhondji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 17:29:40 by ckhondji          #+#    #+#             */
/*   Updated: 2025/11/23 16:38:40 by ckhondji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	cc;

	cc = (char) c;
	while (*s != '\0')
	{
		if (*s == cc)
		{
			return ((char *) s);
		}
		s++;
	}
	if (*s == cc)
		return ((char *) s);
	return (NULL);
}

/*
int main(){
	printf("%s", ft_strchr("test", 't'));
}*/
