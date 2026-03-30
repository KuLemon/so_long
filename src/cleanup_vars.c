/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_vars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckhondji <ckhondji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 16:59:23 by ckhondji          #+#    #+#             */
/*   Updated: 2026/03/28 20:16:37 by ckhondji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void    free_tab(char **tab)
{
    int i;

    i = 0;
    while (tab[i])
    {
        free(tab[i]);
        i++;
    }
    free(tab);
}

void	free_struct(t_data *vars)
{
	if (vars->mlx)
	{
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
	}
	free(vars);
}

void	free_vars(t_data *vars)
{
	if (vars->wall_img)
		mlx_destroy_image(vars->mlx, vars->wall_img);
	if (vars->ground_img)
		mlx_destroy_image(vars->mlx, vars->ground_img);
	if (vars->coins_img)
		mlx_destroy_image(vars->mlx, vars->coins_img);
	if (vars->exit_img)
		mlx_destroy_image(vars->mlx, vars->exit_img);
	if (vars->p_img)
		mlx_destroy_image(vars->mlx, vars->p_img);
	if (vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	free_tab(vars->tab);
	free_struct(vars);
}