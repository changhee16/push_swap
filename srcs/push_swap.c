/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccho <ccho@student.42.kr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 20:27:18 by ccho              #+#    #+#             */
/*   Updated: 2022/11/10 22:01:22 by ccho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	divide_three(t_info	*info)
{
	t_node	*tmp;
	int		num_1;
	int		num_2;
	int		num_3;

	num_1 = info->arr[2];
	num_2 = info->arr[(2 + (info->arr_num - 1)) / 2];
	num_3 = info->arr[info->arr_num - 1];
	while (info->a_size > 3)
	{
		tmp = info->top_a;
		if ((tmp->data >= num_1) && (tmp->data < num_2))
			pb(info);
		else if ((tmp->data >= num_2) && (tmp->data != num_3))
		{
			pb(info);
			rb(info, 1);
		}
		else
			ra(info, 1);
	}
}

void	greedy(t_info	*info)
{
	while (info->top_b)
	{
		info->min_a = info->a_size;
		info->min_b = info->b_size;
		get_min_a_b(info);
		rotate_rr(info);
		rotate_ra(info);
		rotate_rb(info);
		pa(info);
	}
	rotate_sort(info);
}

void	push_swap(t_info	*info)
{
	if (info->arr_num == 2)
		hard_coding_two(info);
	else if (info->arr_num == 3)
		hard_coding_three(info);
	else if (info->arr_num == 5)
		hard_coding_five(info);
	else
	{
		if (info->arr_num == 4)
			set_four(info);
		else
			divide_three(info);
		hard_coding_three(info);
		greedy(info);
	}
}
