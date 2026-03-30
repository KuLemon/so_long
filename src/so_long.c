/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckhondji <ckhondji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 15:55:10 by ckhondji          #+#    #+#             */
/*   Updated: 2026/03/30 16:52:24 by ckhondji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int argc, char *argv[])
{
	t_data	*vars;
	int		fd;
	t_co	size;

	vars = ft_calloc(1, sizeof(t_data));
	fd = open(argv[1], O_RDONLY);
	if (fd < 0 || argc != 2)
	{
		free(vars);
		return (ft_printf("Error\nMap file not found."));
	}
	vars->tab = parsing(fd);
	if (checker(vars->tab) != 0)
	{
		free_vars(vars);
		return (0);
	}
	size.x = ft_strlen(vars->tab[0]);
	size.y = rectangle__checker(vars->tab);
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, size.x * 100, size.y * 100, "SO LONG");
	mlx_hook(vars->win, 2, 1L << 0, keypresshandler, vars);
	mlx_hook(vars->win, 17, 1L << 5, closewin, vars);
	build_level(vars);
	//free_vars(vars);
	mlx_loop(vars->mlx);
	return (0);
}

void error_handler(char *msg, t_data *vars)
{
	ft_printf("%s", msg);
	closewin(vars);
}