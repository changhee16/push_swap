/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccho <ccho@student.42.kr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:41:24 by ccho              #+#    #+#             */
/*   Updated: 2022/11/10 20:52:23 by ccho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	int_to_stack(t_info	*info)
{
	int		i;
	t_node	*tmp;

	i = -1;
	info->top_a = NULL;
	while (++i < info->arr_num)
	{
		tmp = ft_nodenew(info->arr[i]);
		ft_nodeadd_back(&info->top_a, tmp);
		(info->a_size)++;
	}
	info->bot_a = ft_nodelast(info->top_a);
	info->bot_a->next = NULL;
}

int	*char_to_int(char	**argv, t_info	*info, int flag)
{
	int	i;
	int	j;
	int	last_index;
	int	*arr;

	arr = (int *)malloc(sizeof(int) * (info->arr_num + 1));
	if (!(arr))
		error_print(0, NULL);
	if (flag == 2)
	{
		i = -1;
		last_index = info->arr_num - 1;
	}
	else
	{
		i = 0;
		last_index = info->arr_num;
	}
	j = -1;
	while (++i <= last_index)
		arr[++j] = ft_push_atoi(argv[i], info);
	return (arr);
}
