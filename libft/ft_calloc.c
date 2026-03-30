/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckhondji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 17:29:20 by ckhondji          #+#    #+#             */
/*   Updated: 2025/11/25 18:34:13 by ckhondji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			i;
	unsigned char	*tab;

	i = 0;
	if (size != 0 && nmemb > SIZE_MAX / size)
		return (NULL);
	tab = malloc(size * nmemb);
	if (tab == NULL)
		return (NULL);
	while (i < nmemb * size)
	{
		tab[i] = 0;
		i++;
	}
	return ((void *) tab);
}
/*
int main()
{
	int *pointer = (int *) calloc(10, sizeof(int));

	for (int i=0; i<10; i++)
	{
		printf("%d", pointer[i]);
	}
}*/
