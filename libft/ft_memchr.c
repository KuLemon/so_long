/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckhondji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 14:04:51 by ckhondji          #+#    #+#             */
/*   Updated: 2025/11/17 17:43:20 by ckhondji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void *s, int c, size_t n)
{
	size_t					i;
	unsigned char			char_c;
	unsigned char			*char_s;

	char_s = (unsigned char *) s;
	char_c = (unsigned char) c;
	i = 0;
	while (i < n)
	{
		if (char_s[i] == char_c)
		{
			return ((void *) char_s + i);
		}
		i++;
	}
	return (NULL);
}

/*
int main()
{
	int	test[] = {42};
	char	*result = ft_memchr(test, 42, 3);
	printf("%s", result);
}*/
