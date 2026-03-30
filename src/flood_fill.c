/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckhondji <ckhondji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 16:13:02 by ckhondji          #+#    #+#             */
/*   Updated: 2026/03/30 16:55:47 by ckhondji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void    fill(char **tab, int i, int j, char to_not_fill, t_co size)
{
	if (i < 0 || j < 0 || i > size.y || j > size.x)
		return ;
	if (tab[i][j] == to_not_fill || tab[i][j] == 'F')
		return ;
	tab[i][j] = 'F';
	fill(tab, i - 1, j, to_not_fill, size);
	fill(tab, i + 1, j, to_not_fill, size);
	fill(tab, i, j - 1, to_not_fill, size);
	fill(tab, i, j + 1, to_not_fill, size);
}

int		check_fill(char **tab, t_co size, char to_not_fill)
{
	int	i;
	int	j;

	j = 0;
	while (j < size.y - 1)
	{
		i = 0;
		while (i < size.x - 1)
		{
			if (tab[j][i] != 'F' && tab[j][i] != to_not_fill)
				if (tab[j][i] == 'P' || tab[j][i] == 'E' || tab[j][i] == 'C')
					return (1);
			i++;
		}
		j++;
	}
	return (0);
}

t_co	p_finder(char **tab, t_co size)
{
	int	i;
	int	j;
	t_co p;

	i = 0;
	j=0;
	while (j < size.x - 1)
	{
		i = 0;
		while (i < size.y - 1)
		{
			if (tab[i][j] == 'P')
			{
				p.x = i;
				p.y = j;
			}
			i++;
		}
		j += 1;
	}

	return (p);
}

char	**copy_tab(char **tab, t_co size)
{
	char	**new_tab;
	int		i;

	i = 0;
	new_tab = (char **)malloc((size.y + 1) * sizeof(char *));
	if (!new_tab)
		return (NULL);
	while (i < size.y)
	{
		new_tab[i] = (char *)malloc((ft_strlen(tab[i]) + 1) * sizeof(char));
		if (!new_tab[i])
		{
			free_tab(new_tab);
			return (NULL);
		}
		ft_strlcpy(new_tab[i], tab[i], size.x + 1);
		i++;
	}
	new_tab[i] = NULL;
	return (new_tab);
}

int    flood_fill(char **tab, char to_not_fill, t_co size)
{
	char		**temp_tab;
	int			check_result;
	t_co		p;

	check_result = 0;
	p = p_finder(tab, size);
	temp_tab = copy_tab(tab, size);
	if (!temp_tab)
		return (-1);
	fill(temp_tab, p.x, p.y, to_not_fill, size);
	check_result = check_fill(temp_tab, size, to_not_fill);
	free_tab(temp_tab);
	if (check_result == 1)
		return (-1);
	return (0);
}