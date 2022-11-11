/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccho <ccho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:46:37 by ccho              #+#    #+#             */
/*   Updated: 2022/11/11 13:52:01 by ccho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
	if (check == 0)
		error_print(0, info);
}
