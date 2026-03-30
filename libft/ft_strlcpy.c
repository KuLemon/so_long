/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckhondji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:42:12 by ckhondji          #+#    #+#             */
/*   Updated: 2025/11/07 14:50:13 by ckhondji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len;

	len = ft_strlen(src);
	if (size >= len + 1)
	{	
		ft_memcpy(dst, src, len + 1);
	}
	else if (size > 0)
	{
		ft_memcpy(dst, src, size - 1);
		dst[size - 1] = 0;
	}
	return (len);
}
/*
int main(){
	const char src[] = "test";
	char dst[] = "prout";

	printf("%d", strlcpy(dst, src, 1));
}*/
