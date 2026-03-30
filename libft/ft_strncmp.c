/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckhondji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 13:52:31 by ckhondji          #+#    #+#             */
/*   Updated: 2025/11/23 17:22:19 by ckhondji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*ss1;
	unsigned char	*ss2;

	ss1 = (unsigned char *) s1;
	ss2 = (unsigned char *) s2;
	i = 0;
	if (n <= 0)
		return (0);
	while ((ss1[i] != '\0' && ss2[i] != '\0') && ss1[i] == ss2[i] && i < n - 1)
	{
		i++;
	}
	return (ss1[i] - ss2[i]);
}
/*
int main()
{
	printf("%d", ft_strncmp("ABCD", "AB", -1));
}*/
