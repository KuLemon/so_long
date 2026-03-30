/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckhondji <ckhondji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:44:54 by ckhondji          #+#    #+#             */
/*   Updated: 2025/12/26 17:15:48 by ckhondji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	add_node(t_Node **head, char c)
{
	t_Node	*node;
	t_Node	*temp;

	node = malloc(sizeof(t_Node));
	if (!node)
		return ;
	node->val = c;
	node->next = NULL;
	if (*head == NULL)
	{
		*head = node;
		return ;
	}
	temp = *head;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = node;
}

int	node_checker(t_Node *head)
{
	t_Node	*temp;

	temp = head;
	while (temp != NULL)
	{
		if (temp->val == '\n')
		{
			return (1);
		}
		temp = temp->next;
	}
	return (0);
}

t_Node	*stash_cleaner(t_Node *head)
{
	t_Node	*tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		if (tmp->val == '\n')
		{
			free(tmp);
			return (head);
		}
		free(tmp);
	}
	return (NULL);
}

char	*stash_to_string(t_Node *head)
{
	t_Node	*tmp;
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	tmp = head;
	while (tmp != NULL)
	{
		i++;
		if (tmp->val == '\n')
			break ;
		tmp = tmp->next;
	}
	str = malloc(i * sizeof(char) + 1);
	tmp = head;
	while (j < i)
	{
		str[j] = tmp->val;
		tmp = tmp->next;
		j++;
	}
	str[j] = '\0';
	return (str);
}

void	free_stash(t_Node **stash)
{
	t_Node	*tmp;

	while (*stash)
	{
		tmp = *stash;
		*stash = (*stash)->next;
		free(tmp);
	}
}
