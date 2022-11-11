/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccho <ccho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 20:09:46 by ccho              #+#    #+#             */
/*   Updated: 2022/11/09 21:39:34 by ccho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_renew_min_a(int a_data, int data, int min)
{
	if (((a_data > data) && (min > (a_data - data))) || (min < 0))
		return (1);
	return (0);
}

int	get_rot_a(t_info	*info, int data)
{
	t_node	*tmp_a;
	int		rot_a;
	int		min;
	int		index;
	int		flag;

	tmp_a = info->top_a;
	min = -1;
	index = 0;
	flag = 0;
	while (tmp_a)
	{
		flag = is_renew_min_a(tmp_a->data, data, min);
		if (flag == 1)
		{
			rot_a = index;
			min = tmp_a->data - data;
		}
		tmp_a = tmp_a->next;
		index++;
	}
	if (rot_a >= ((info->a_size + 1) / 2))
		rot_a = -1 * (info->a_size - rot_a);
	return (rot_a);
}

void	get_min_a_b(t_info	*info)
{
	int		rot_a;
	int		rot_b;
	int		index;
	t_node	*tmp_b;

	tmp_b = info->top_b;
	index = 0;
	while (tmp_b)
	{
		rot_a = get_rot_a(info, tmp_b->data);
		rot_b = index;
		if (rot_b >= ((info->b_size + 1) / 2))
			rot_b = -1 * (info->b_size - rot_b);
		if (((abs(rot_a) + abs(rot_b))) < (abs(info->min_a) + abs(info->min_b)))
		{
			info->min_a = rot_a;
			info->min_b = rot_b;
		}
		tmp_b = tmp_b->next;
		index++;
	}
}
