/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckhondji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 14:57:48 by ckhondji          #+#    #+#             */
/*   Updated: 2025/11/23 17:23:46 by ckhondji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	lensrc;
	size_t	lendst;

	lensrc = ft_strlen(src);
	lendst = ft_strlen(dst);
	if (lendst >= size)
		lendst = size;
	if (lendst == size)
		return (size + lensrc);
	if (lensrc < size - lendst)
	{	
		ft_memcpy(dst + lendst, src, lensrc + 1);
	}
	else
	{
		ft_memcpy(dst + lendst, src, size - lendst - 1);
		dst[size - 1] = '\0';
	}
	return (lendst + lensrc);
}
/*
int main()
{
	printf("%zu", ft_strlcat("CAQWECJAS", "CCCCCAAAAAAAAA", -1));
}*/
