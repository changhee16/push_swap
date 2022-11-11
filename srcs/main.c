/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccho <ccho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:33:11 by ccho              #+#    #+#             */
/*   Updated: 2022/11/11 17:02:13 by ccho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_stack(t_info	*info)
{
	info->top_a = NULL;
	info->bot_a = NULL;
	info->top_b = NULL;
	info->bot_b = NULL;
	info->arr = NULL;
	info->a_size = 0;
	info->b_size = 0;
}

int	get_argc(char	**argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}

void	free_info(t_info	*info)
{
	if (info->arr)
		free(info->arr);
	if (info->top_a)
		ft_nodeclear(&(info->top_a));
	if (info->top_b)
		ft_nodeclear(&(info->top_b));
}

int	main(int argc, char **argv)
{
	t_info	info;

	init_stack(&info);
	if (argc < 2)
		error_print(0, NULL);
	else if (argc == 2)
		info.arr = argc_two_set(argv[1], &info);
	else
		info.arr = argc_more_set(argv, argc, &info);
	if (!info.arr)
		error_print(0, NULL);
	int_to_stack(&info);
	sort_int_arr(&info);
	push_swap(&info);
	//check_stack(&info);
	free_info(&info);
	return (0);
}
