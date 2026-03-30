/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckhondji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 14:35:51 by ckhondji          #+#    #+#             */
/*   Updated: 2025/11/22 17:29:56 by ckhondji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*dest_char;
	char		*src_char;

	if (dest == NULL && src == NULL)
		return (NULL);
	src_char = (char *) src;
	dest_char = (char *) dest;
	i = 0;
	if (dest_char > src_char)
	{
		while (n-- > 0)
		{
			dest_char[n] = src_char[n];
		}
	}
	else
	{
		while (i < n)
		{
			dest_char[i] = src_char[i];
			i++;
		}
	}
	return (dest);
}

/*
int main()
{
	char src[] = "ABCDEFGHIJKLMNO";
	char dest[] = "123456789101112131415";

	ft_memmove(dest+1, src, 10);
	printf("%s", dest);
}*/
