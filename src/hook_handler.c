/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckhondji <ckhondji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 14:30:31 by ckhondji          #+#    #+#             */
/*   Updated: 2026/03/30 16:58:14 by ckhondji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	closewin(t_data *vars)
{
	free_vars(vars);
	exit(0);
	return (0);
}

int	keypresshandler(int keycode, t_data *vars)
{
	static int nbmov;

	if (!nbmov)
		nbmov = 1;
	if (keycode == 65307)
		closewin(vars);
	else
	{
		if (keycode == 119 || keycode == 97 || keycode == 115 || keycode == 100)
		{
			if (collision_init(keycode, vars) == 1)
				ft_printf("Nombre de mouvements: %d\n", nbmov++);
			if (check_win(vars) == 0)
			{
        		ft_printf("\nBravo !");
				closewin(vars);
			}
			build_level(vars);
		}
	}
	return (0);
}