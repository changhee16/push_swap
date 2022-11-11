/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccho <ccho@student.42.kr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:13:06 by ccho              #+#    #+#             */
/*   Updated: 2022/11/10 16:13:13 by ccho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

t_node	*ft_nodenew(int data)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->data = data;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_node	*ft_nodelast(t_node *node)
{
	while (node->next)
		node = node->next;
	return (node);
}

void	ft_nodeadd_back(t_node **node, t_node *new)
{
	t_node	*last;

	if (!new)
		return ;
	if (!*node)
	{
		*node = new;
		return ;
	}
	last = ft_nodelast(*node);
	last->next = new;
	new->prev = last;
}

void	ft_nodeclear(t_node **node)
{
	t_node	*tmp;

	while (*node)
	{
		tmp = (*node)->next;
		free(*node);
		*node = tmp;
	}
	*node = NULL;
}
