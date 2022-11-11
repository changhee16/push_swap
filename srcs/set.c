/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccho <ccho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:39:17 by ccho              #+#    #+#             */
/*   Updated: 2022/11/09 20:00:48 by ccho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	set_four(t_info	*info)
{
	t_node	*tmp_a;
	int		index;

	tmp_a = info->top_a;
	index = 0;
	while (tmp_a)
	{
		if (tmp_a->data == info->arr[info->arr_num - 2])
			break ;
		tmp_a = tmp_a->next;
		index++;
	}
	while (index)
	{
		ra(info, 1);
		index--;
	}
	pb(info);
}

int	*argc_two_set(char	*argv, t_info	*info)
{
	char	**split_argv;
	int		*res;

	res = NULL;
	split_argv = ft_split(argv, ' ');
	check_argv(split_argv, 2, info);
	info->arr_num = get_argc(split_argv);
	if (!split_argv[0])
		error_print(1, NULL);
	else if (info->arr_num == 1)
		res = NULL;
	else
		res = char_to_int(split_argv, info, 2);
	ft_free(split_argv);
	return (res);
}

int	*argc_more_set(char	**argv, int argc, t_info	*info)
{
	int	*res;

	info->arr_num = argc - 1;
	check_argv(argv, 3, info);
	res = char_to_int(argv, info, 3);
	return (res);
}
