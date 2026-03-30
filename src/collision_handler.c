/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckhondji <ckhondji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 16:51:01 by ckhondji          #+#    #+#             */
/*   Updated: 2026/03/30 16:56:39 by ckhondji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int check_win(t_data *vars)
{
    int     i;
    int     j;
    t_co    size;

    i = 0;
    j = 0;
    size.x = ft_strlen(vars->tab[0]);
    size.y = rectangle__checker(vars->tab);
	while (i < size.y)
	{
		j = 0;
		while (j < size.x)
		{
			if (vars->tab[i][j] == 'E')
				return (1);
            j++;
		}
        i++;
	}
    return (0);
}


int check_exit(t_data *vars, t_co size)
{
    int i;
    int j;

    i = 0;
    j = 0;
	while (i < size.y)
	{
		j = 0;
		while (j < size.x)
		{
			if (vars->tab[i][j] == 'C')
				return (1);
            j++;
		}
        i++;
	}
    return (0);
}

void    move_p(int keycode, t_data *vars, t_co p)
{
    if (keycode == 119)
    {
        vars->tab[p.x][p.y] = '0';
        vars->tab[p.x - 1][p.y] = 'P';
    } else if (keycode == 97)
    {
        vars->tab[p.x][p.y] = '0';
        vars->tab[p.x][p.y - 1] = 'P';
    } else if (keycode == 115)
    {
        vars->tab[p.x][p.y] = '0';
        vars->tab[p.x + 1][p.y] = 'P';
    } else if (keycode == 100)
    {
        vars->tab[p.x][p.y] = '0';
        vars->tab[p.x][p.y + 1] = 'P';
    }
}

void check_wall(int keycode, t_data *vars, t_co p, t_co size)
{
    if (vars->tab[p.x - 1][p.y] != '1' && keycode == 119) //W
    {
        if (vars->tab[p.x - 1][p.y] == 'E' && check_exit(vars, size) == 1)
            return ;
        move_p(keycode, vars, p);
    } else if (vars->tab[p.x][p.y - 1] != '1' && keycode == 97) //A
    {
        if (vars->tab[p.x][p.y - 1] == 'E' && check_exit(vars, size) == 1)
            return ;    
        move_p(keycode, vars, p);
    } else if (vars->tab[p.x + 1][p.y] != '1' && keycode == 115) //S
    {
        if (vars->tab[p.x + 1][p.y] == 'E' && check_exit(vars, size) == 1)
            return ;    
        move_p(keycode, vars, p);
    } else if (vars->tab[p.x][p.y + 1] != '1' && keycode == 100) //D
    {
        if (vars->tab[p.x][p.y + 1] == 'E' && check_exit(vars, size) == 1)
            return ;
        move_p(keycode, vars, p);
    }
}

int collision_init(int keycode, t_data *vars)
{
    t_co p;
    t_co size;
    
    size.x = ft_strlen(vars->tab[0]);
    size.y = rectangle__checker(vars->tab);
    if (check_win(vars) == 0)
        return (0);
    p = p_finder(vars->tab, size);
    check_wall(keycode, vars, p, size);
    if (vars->tab[p.x][p.y] != 'P')
        return (1);
    return (0);
}