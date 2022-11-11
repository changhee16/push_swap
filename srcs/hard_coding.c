/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_coding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccho <ccho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 02:03:47 by ccho              #+#    #+#             */
/*   Updated: 2022/11/09 21:36:22 by ccho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	hard_coding_two(t_info	*info)
{
	if (info->top_a->data > info->top_a->next->data)
		sa(info, 1);
}

void	hard_coding_three(t_info *info)
{
	int	a;
	int	b;
	int	c;

	a = info->top_a->data;
	b = info->top_a->next->data;
	c = info->bot_a->data;
	if ((a > b) && (a < c) && (b < c))
		sa(info, 1);
	else if ((a > b) && (b > c))
	{
		sa(info, 1);
		rra(info, 1);
	}
	else if ((a > b) && (a > c) && (b < c))
		ra(info, 1);
	else if ((a < b) && (a < c) && (b > c))
	{
		sa(info, 1);
		ra(info, 1);
	}
	else if ((a < b) && (a > c) && (b > c))
		rra(info, 1);
}

void	get_max_and_min_data(t_info	*info)
{
	t_node	*tmp;
	int		index;

	tmp = info->top_a;
	index = 0;
	while (info->a_size > 3)
	{
		if ((tmp->data == info->arr[info->arr_num - 1]) \
		|| (tmp->data == info->arr[0]))
		{
			if (index > 2)
				info->min_a = -(info->a_size - index);
			else
				info->min_a = index;
			rotate_ra(info);
			pb(info);
			tmp = info->top_a;
			index = 0;
		}
		else
		{
			tmp = tmp->next;
			index++;
		}
	}
}

void	hard_coding_five(t_info *info)
{
	t_node	*tmp;

	get_max_and_min_data(info);
	hard_coding_three(info);
	while (info->b_size)
	{
		tmp = info->top_b;
		if (tmp->data == info->arr[0])
			pa(info);
		else
		{
			pa(info);
			ra(info, 1);
		}
	}
}
