/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccho <ccho@student.42.kr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:14:16 by ccho              #+#    #+#             */
/*   Updated: 2022/11/10 22:17:14 by ccho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

void	sort_int_arr(t_info *info)
{
	int	i;
	int	j;
	int	key;
	int	check;

	i = 0;
	check = 0;
	while (++i < info->arr_num)
	{
		key = info->arr[i];
		j = i;
		while (--j >= 0 && info->arr[j] >= key)
		{
			if (info->arr[j] == key)
				error_print(1, info);
			info->arr[j + 1] = info->arr[j];
			check++;
		}
		info->arr[j + 1] = key;
	}
}

void	is_sort(t_info	*info)
{
	t_node	*tmp;
	int		sort;

	tmp = info->top_a;
	sort = 0;
	while (sort + 1 < info->a_size)
	{
		if (tmp->data > tmp->next->data)
			break ;
		else
			tmp = tmp->next;
		sort++;
	}
	if (sort + 1 != info->a_size)
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
}
