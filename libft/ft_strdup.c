/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckhondji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 14:28:29 by ckhondji          #+#    #+#             */
/*   Updated: 2025/11/08 14:35:23 by ckhondji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*tab;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(s);
	tab = malloc(len + 1 * sizeof(char));
	if (!tab)
		return (NULL);
	while (s[i] != '\0')
	{
		tab[i] = s[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

/*
int main()
{
	char str[] = "test";
	char *str2 = strdup(str);

	printf("%s", str2);
}*/
