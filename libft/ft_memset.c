/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckhondji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 13:46:18 by ckhondji          #+#    #+#             */
/*   Updated: 2025/11/08 16:41:10 by ckhondji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t		count;
	char		*char_s;

	char_s = (char *) s;
	count = 0;
	while (count < n)
	{
		char_s[count] = c;
		count++;
	}
	return (s);
}
