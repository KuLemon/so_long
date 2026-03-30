/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckhondji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 13:41:57 by ckhondji          #+#    #+#             */
/*   Updated: 2025/11/07 17:21:37 by ckhondji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				count;
	unsigned char		*dest_char;
	unsigned char		*src_char;

	dest_char = (unsigned char *) dst;
	src_char = (unsigned char *) src;
	count = 0;
	if (dst == (void *)0 && src == (void *)0)
		return (dst);
	while (count < n)
	{
		dest_char[count] = src_char[count];
		count++;
	}
	return (dst);
}
/*
int main()
{
	int src[] = {1, 5, 3};
	int dest[5];

	ft_memcpy(dest, src, sizeof(src));
	printf("%d", dest[1]);
}*/
