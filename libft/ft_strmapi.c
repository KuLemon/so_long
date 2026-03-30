/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckhondji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 16:07:17 by ckhondji          #+#    #+#             */
/*   Updated: 2025/11/22 16:23:15 by ckhondji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*tab;
	unsigned int	i;

	i = 0;
	tab = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (tab == NULL)
		return (NULL);
	while (i < ft_strlen(s))
	{
		tab[i] = (*f)(i, s[i]);
		i++;
	}
	tab[i] = 0;
	return (tab);
}
