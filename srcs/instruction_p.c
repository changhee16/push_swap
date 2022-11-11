/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_p.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccho <ccho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:05:58 by ccho              #+#    #+#             */
/*   Updated: 2022/11/09 21:58:33 by ccho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	out_top(t_info	*info, int flag)
{
	if (flag == 1)
	{
		if (info->top_b->next)
		{
			info->top_b = info->top_b->next;
			info->top_b->prev = NULL;
		}
		else
			info->top_b = NULL;
	}
	else if (flag == 2)
	{
		if (info->top_a->next)
		{
			info->top_a = info->top_a->next;
			info->top_a->prev = NULL;
		}
		else
			info->top_a = NULL;
	}
}

void	pa(t_info	*info)
{
	t_node	*tmp;

	if (!(info->top_b))
		return ;
	tmp = info->top_b;
	out_top(info, 1);
	(info->b_size)--;
	if (info->top_a)
	{
		tmp->next = info->top_a;
		info->top_a->prev = tmp;
		info->top_a = tmp;
	}
	else
	{
		info->top_a = tmp;
		info->bot_a = tmp;
		info->top_b->next = NULL;
	}
	(info->a_size)++;
	write(1, "pa\n", 3);
}

void	pb(t_info	*info)
{
	t_node	*tmp;

	if (!(info->top_a))
		return ;
	tmp = info->top_a;
	out_top(info, 2);
	(info->a_size)--;
	if (info->top_b)
	{
		tmp->next = info->top_b;
		info->top_b->prev = tmp;
		info->top_b = tmp;
	}
	else
	{
		info->top_b = tmp;
		info->bot_b = tmp;
		info->top_b->next = NULL;
	}
	(info->b_size)++;
	write(1, "pb\n", 3);
}
