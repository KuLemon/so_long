/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckhondji <ckhondji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 16:08:21 by ckhondji          #+#    #+#             */
/*   Updated: 2026/03/30 16:57:10 by ckhondji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <mlx.h>
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include "libft/printf/ft_printf.h"

typedef struct s_data {
	void	*mlx;
	void	*win;
	char	**tab;

	void	*wall_img;
	void	*ground_img;
	void	*coins_img;
	void	*exit_img;
	void	*p_img;
}	t_data;

typedef struct s_co {
	int	x;
	int	y;
}	t_co;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		flood_fill(char **tab, char to_not_fill, t_co size);
int		keypresshandler(int keycode, t_data *vars);
int		collision_init(int keycode, t_data *vars);
void 	error_handler(char *msg, t_data *vars);
int		check_win(t_data *vars);
t_co	p_finder(char **tab, t_co size);
int		rectangle__checker(char **tab);
int		build_level(t_data *vars);
int		get_linenumbers(int fd);
void	free_vars(t_data *vars);
void    free_tab(char **tab);
int		closewin(t_data *vars);
int		checker(char **tab);
char	**parsing(int fd);

void	place_ground(t_data *vars, t_co size);
void	place_walls(t_data *vars, t_co size);
void	place_player(t_data *vars, t_co size);
void	place_coins(t_data *vars, t_co size);
void	place_exit(t_data *vars, t_co size);

#endif