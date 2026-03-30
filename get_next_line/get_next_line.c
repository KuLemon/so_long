/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckhondji <ckhondji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:44:37 by ckhondji          #+#    #+#             */
/*   Updated: 2025/12/22 17:29:37 by ckhondji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	val_ini(int *i, int *j, int fd, char *c)
{
	*i = read(fd, c, BUFFER_SIZE);
	*j = 0;
}

char	*get_next_line(int fd)
{
	static t_Node	*stash;
	int				i;
	int				j;
	char			*c;
	char			*str;

	c = malloc(sizeof(char) * BUFFER_SIZE);
	if (fd < 0 || BUFFER_SIZE <= 0 || !c)
		return (free(c), NULL);
	while (node_checker(stash) == 0)
	{
		val_ini(&i, &j, fd, c);
		if (i < 0)
			return (free(c), free_stash(&stash), NULL);
		if (i == 0)
			break ;
		while (j < i)
			add_node(&stash, c[j++]);
	}
	free(c);
	if (!stash)
		return (NULL);
	str = stash_to_string(stash);
	stash = stash_cleaner(stash);
	return (str);
}
