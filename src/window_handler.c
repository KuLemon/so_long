/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckhondji <ckhondji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 13:49:17 by ckhondji          #+#    #+#             */
/*   Updated: 2026/03/30 16:51:30 by ckhondji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

//Securiser images

void	place_ground(t_data *vars, t_co size)
{
	int		img_size;
	int		i;
	int		j;

	j = 0;
	img_size = 100;
	if (vars->ground_img == NULL)
		vars->ground_img = mlx_xpm_file_to_image(vars->mlx, "img/ground.xpm", &img_size, &img_size);
	if (vars->ground_img == NULL)
		error_handler("Error\nground.xpm not found.", vars);
	while (j < size.y)
	{
		i = 0;
		while (i < size.x)
		{
			if (vars->tab[j][i] == '0')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->ground_img, i * img_size, j * img_size);	
			i++;
		}
		j++;
	}
}

void	place_walls(t_data *vars, t_co size)
{
	int		img_size;
	int		i;
	int		j;

	j = 0;
	img_size = 100;
	if (vars->wall_img == NULL)
		vars->wall_img = mlx_xpm_file_to_image(vars->mlx, "img/wall.xpm", &img_size, &img_size);
	if (vars->wall_img == NULL)
		error_handler("Error\nwall.xpm not found.", vars);
	while (j < size.y)
	{
		i = 0;
		while (i < size.x)
		{
			if (vars->tab[j][i] == '1')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->wall_img, i * img_size, j * img_size);	
			i++;
		}
		j++;
	}
}

void	place_player(t_data *vars, t_co size)
{
	int		img_size;
	int		i;
	int		j;

	j = 0;
	img_size = 100;
	if (vars->p_img == NULL)
		vars->p_img = mlx_xpm_file_to_image(vars->mlx, "img/player.xpm", &img_size, &img_size);
	if (vars->p_img == NULL)
		error_handler("Error\nplayer.xpm not found.", vars);
	while (j < size.y)
	{
		i = 0;
		while (i < size.x)
		{
			if (vars->tab[j][i] == 'P')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->p_img, i * img_size, j * img_size);
			i++;
		}
		j++;
	}
}

void	place_exit(t_data *vars, t_co size)
{
	int		img_size;
	int		i;
	int		j;

	j = 0;
	img_size = 100;
	if (vars->exit_img == NULL)
		vars->exit_img = mlx_xpm_file_to_image(vars->mlx, "img/exit.xpm", &img_size, &img_size);
	if (vars->exit_img == NULL)
		error_handler("Error\nexit.xpm not found.", vars);
	while (j < size.y)
	{
		i = 0;
		while (i < size.x)
		{
			if (vars->tab[j][i] == 'E')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->exit_img, i * img_size, j * img_size);
			i++;
		}
		j++;
	}
}

void	place_coins(t_data *vars, t_co size)
{
	int		img_size;
	int		i;
	int		j;

	j = 0;
	img_size = 100;
	if (vars->coins_img == NULL)
		vars->coins_img = mlx_xpm_file_to_image(vars->mlx, "img/coins.xpm", &img_size, &img_size);
	if (vars->coins_img == NULL)
		error_handler("Error\ncoins.xpm not found.", vars);
	while (j < size.y)
	{
		i = 0;
		while (i < size.x)
		{
			if (vars->tab[j][i] == 'C')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->coins_img, i * img_size, j * img_size);
			i++;
		}
		j++;
	}
}

