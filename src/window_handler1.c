/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_handler1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckhondji <ckhondji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 13:49:17 by ckhondji          #+#    #+#             */
/*   Updated: 2026/03/30 17:00:32 by ckhondji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int		build_level(t_data *vars)
{
	t_co	size;
	int		i;

	i = 0;
	size.x = ft_strlen(vars->tab[0]);
	while (vars->tab[i] != NULL)
	{
		i++;
	}
	size.y = i;
	place_walls(vars, size);
	place_player(vars, size);
	place_exit(vars, size);
	place_coins(vars, size);
	place_ground(vars, size);
	return (0);
}