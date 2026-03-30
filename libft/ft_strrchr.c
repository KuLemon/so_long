/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckhondji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 13:47:40 by ckhondji          #+#    #+#             */
/*   Updated: 2025/11/23 16:49:43 by ckhondji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	char	cc;

	cc = (char) c;
	ptr = NULL;
	while (*s != '\0')
	{
		if (*s == cc)
		{
			ptr = (char *) s;
		}
		s++;
	}
	if (*s == cc)
		ptr = (char *) s;
	return (ptr);
}

/*
int main()
{
	char	str[] = "test";

	printf("%s", ft_strrchr(str, 't'));
}*/
