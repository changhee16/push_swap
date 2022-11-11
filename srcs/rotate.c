/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccho <ccho@student.42.kr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 20:02:46 by ccho              #+#    #+#             */
/*   Updated: 2022/11/10 22:02:32 by ccho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_rr(t_info	*info)
{
	while ((info->min_a > 0) && (info->min_b > 0))
	{
		rr(info);
		info->min_a--;
		info->min_b--;
	}
	while ((info->min_a < 0) && (info->min_b < 0))
	{
		rrr(info);
		info->min_a++;
		info->min_b++;
	}
}

void	rotate_ra(t_info	*info)
{
	while (info->min_a > 0)
	{
		ra(info, 1);
		info->min_a--;
	}
	while (info->min_a < 0)
	{
		rra(info, 1);
		info->min_a++;
	}
}

void	rotate_rb(t_info	*info)
{
	while (info->min_b > 0)
	{
		rb(info, 1);
		info->min_b--;
	}
	while (info->min_b < 0)
	{
		rrb(info, 1);
		info->min_b++;
	}
}

void	rotate_sort(t_info	*info)
{
	t_node	*tmp_a;
	int		index;

	tmp_a = info->top_a;
	index = 1;
	while (tmp_a)
	{
		if (tmp_a->data == info->arr[info->arr_num - 1])
			break ;
		tmp_a = tmp_a->next;
		index++;
	}
	if (index > ((info->a_size + 1) / 2))
		index = -1 * (info->a_size - index);
	while (index > 0)
	{
		ra(info, 1);
		index--;
	}
	while (index < 0)
	{
		rra(info, 1);
		index++;
	}
}
