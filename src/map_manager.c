/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckhondji <ckhondji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 16:45:30 by ckhondji          #+#    #+#             */
/*   Updated: 2026/03/30 16:50:28 by ckhondji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	rectangle__checker(char **tab)
{
	int	width;
	int	height;
	int	exp_width;

	height = 0;
	exp_width = ft_strlen(tab[0]);
	while (tab[height] != NULL)
	{
		width = ft_strlen(tab[height]);
		if (width != exp_width)
			return (-1);
		height++;
	}
	return (height);
}

int	wall_checker(char **tab, t_co size, char wall)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (j < size.x)
	{
		if (tab[0][j] != wall || tab[size.y - 1][j] != wall)
			return (-1);
		j++;
	}
	while (i < size.y)
	{
		if (tab[i][0] != wall || tab[i][size.x - 1] != wall)
			return (-1);
		i++;
	}
	return (0);
}

int	elements_checker(char **tab, t_co size)
{
	int	vars[5];

	vars[2] = 0;
	vars[3] = 0;
	vars[4] = 0;
	vars[0] = -1;
	while (++vars[0] < size.y - 1)
	{
		vars[1] = -1;
		while (++vars[1] < size.x - 1)
		{
			if (tab[vars[0]][vars[1]] == 'P')
				vars[2] += 1;
			if (tab[vars[0]][vars[1]] == 'E')
				vars[3] += 1;
			if (tab[vars[0]][vars[1]] == 'C')
				vars[4] += 1;
		}
	}
	if (vars[2] != 1 || vars[3] != 1 || vars[4] < 1)
		return (-1);
	return (0);
}

int	checker(char **tab)
{
	t_co	size;

	if (rectangle__checker(tab) == -1)
		return (ft_printf("Error\nSelected map is neither a rectangle or a square.\n"));
	size.x = ft_strlen(tab[0]);
	size.y = rectangle__checker(tab);
	if (wall_checker(tab, size, '1') == -1)
		return (ft_printf("Error\nSelected map is not surrounded by walls.\n"));
	if (elements_checker(tab, size) == -1)
		return (ft_printf("Error\nSelected map does not contain necessary elements.\n"));
	if (flood_fill(tab, '1', size) == -1)
		return (ft_printf("Error\nSelected map does not contain a viable path.\n"));
	return (0);
}

char	**parsing(int fd)
{
	char	*str;
	char	**tab;
	char	*string;
	char	*temp;

	string = ft_strdup("");
	while ((str = get_next_line(fd)) != NULL)
	{
		temp = ft_strjoin(string, str);
		free(string);
		free(str);
		string = temp;
	}
	tab = ft_split(string, '\n');
	free(string);
	return (tab);
}

//pathfinding