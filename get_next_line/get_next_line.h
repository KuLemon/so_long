/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckhondji <ckhondji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:57:02 by ckhondji          #+#    #+#             */
/*   Updated: 2026/02/21 17:04:51 by ckhondji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct t_Node{
	char			val;
	struct t_Node	*next;
}	t_Node;

char	*get_next_line(int fd);
void	add_node(t_Node **head, char c);
int		node_checker(t_Node *head);
t_Node	*stash_cleaner(t_Node *head);
char	*stash_to_string(t_Node *head);
void	free_stash(t_Node **stash);

#endif