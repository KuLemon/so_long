/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckhondji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:37:03 by ckhondji          #+#    #+#             */
/*   Updated: 2025/11/07 16:02:55 by ckhondji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	count;
	char	*s_char;

	s_char = (char *) s;
	count = 0;
	while (count < n)
	{
		*s_char = 0;
		s_char++;
		count++;
	}
}
/*
int main(){
	char feur[] = "feqweqweur";
	bzero(feur, 5);
	printf("%s", feur);
}*/
