/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckhondji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:44:44 by ckhondji          #+#    #+#             */
/*   Updated: 2025/11/24 18:19:19 by ckhondji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	countwords(char const *s, char c)
{
	int	i;
	int	j;
	int	inside;

	i = 0;
	j = 0;
	inside = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && inside == 0)
		{
			inside = 1;
			j++;
		}
		else if (s[i] == c)
			inside = 0;
		i++;
	}
	return (j);
}

static char	*fill_word(char const *s, int start, int end)
{
	char	*ptr;
	int		i;

	ptr = malloc((end - start + 1) * sizeof(char));
	i = 0;
	if (ptr == NULL)
		return (NULL);
	while (start + i < end)
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = 0;
	return (ptr);
}

static void	*freetab(char **s1, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		free(s1[j]);
		j++;
	}
	free(s1);
	return (NULL);
}

static void	ini_var(size_t *i, int *j, int *sw)
{
	*sw = -1;
	*j = 0;
	*i = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	i;
	int		j;
	int		sw;

	ini_var(&i, &j, &sw);
	tab = ft_calloc((countwords(s, c) + 1), sizeof(char *));
	if (tab == NULL)
		return (NULL);
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && sw < 0)
			sw = i;
		else if ((s[i] == c || i == ft_strlen(s)) && sw >= 0)
		{
			tab[j] = fill_word(s, sw, i);
			if (tab[j] == NULL)
				return (freetab(tab, j));
			sw = -1;
			j++;
		}
		i++;
	}
	return (tab);
}
