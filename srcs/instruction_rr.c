/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_rr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccho <ccho@student.42.kr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 20:16:41 by ccho              #+#    #+#             */
/*   Updated: 2022/11/08 22:26:57 by ccho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rra(t_info	*info, int flag)
{
	t_node	*tmp;

	if (!(info->top_a->next))
		return ;
	tmp = info->bot_a;
	info->bot_a = info->bot_a->prev;
	info->bot_a->next = NULL;
	info->top_a->prev = tmp;
	tmp->next = info->top_a;
	tmp->prev = NULL;
	info->top_a = tmp;
	if (flag == 1)
		write(1, "rra\n", 4);
}

void	rrb(t_info	*info, int flag)
{
	t_node	*tmp;

	if (!(info->top_b->next))
		return ;
	tmp = info->bot_b;
	info->bot_b = info->bot_b->prev;
	info->bot_b->next = NULL;
	info->top_b->prev = tmp;
	tmp->next = info->top_b;
	tmp->prev = NULL;
	info->top_b = tmp;
	if (flag == 1)
		write(1, "rrb\n", 4);
}

void	rrr(t_info	*info)
{
	if (!(info->top_a) || !(info->top_a->next))
		return ;
	rra(info, 0);
	if (!(info->top_b) || !(info->top_b->next))
		return ;
	rrb(info, 0);
	write(1, "rrr\n", 4);
}
