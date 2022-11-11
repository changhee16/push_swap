/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_r.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccho <ccho@student.42.kr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 19:31:48 by ccho              #+#    #+#             */
/*   Updated: 2022/11/08 22:25:30 by ccho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_info	*info, int flag)
{
	t_node	*tmp;

	if (!(info->top_a->next))
		return ;
	tmp = info->top_a;
	info->top_a = info->top_a->next;
	info->top_a->prev = NULL;
	info->bot_a->next = tmp;
	tmp->prev = info->bot_a;
	tmp->next = NULL;
	info->bot_a = tmp;
	if (flag == 1)
		write(1, "ra\n", 3);
}

void	rb(t_info	*info, int flag)
{
	t_node	*tmp;

	if (!(info->top_b->next))
		return ;
	tmp = info->top_b;
	info->top_b = info->top_b->next;
	info->top_b->prev = NULL;
	info->bot_b->next = tmp;
	tmp->prev = info->bot_b;
	tmp->next = NULL;
	info->bot_b = tmp;
	if (flag == 1)
		write(1, "rb\n", 3);
}

void	rr(t_info	*info)
{
	if (!(info->top_a) || !(info->top_a->next))
		return ;
	ra(info, 0);
	if (!(info->top_b) || !(info->top_b->next))
		return ;
	rb(info, 0);
	write(1, "rr\n", 3);
}
