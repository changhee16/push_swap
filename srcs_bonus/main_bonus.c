/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccho <ccho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:59:03 by ccho              #+#    #+#             */
/*   Updated: 2022/11/11 12:02:31 by ccho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

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

void	exec_ins(char	*line, t_info	*info)
{
	if (!ft_strncmp(line, "pa\n", 3))
		pa(info);
	else if (!ft_strncmp(line, "pb\n", 3))
		pb(info);
	else if (!ft_strncmp(line, "ra\n", 3))
		ra(info, 0);
	else if (!ft_strncmp(line, "rb\n", 3))
		rb(info, 0);
	else if (!ft_strncmp(line, "rr\n", 3))
		rr(info);
	else if (!ft_strncmp(line, "rra\n", 4))
		rra(info, 0);
	else if (!ft_strncmp(line, "rrb\n", 4))
		rrb(info, 0);
	else if (!ft_strncmp(line, "rrr\n", 4))
		rrr(info);
	else if (!ft_strncmp(line, "sa\n", 3))
		sa(info, 0);
	else if (!ft_strncmp(line, "sb\n", 3))
		sb(info, 0);
	else if (!ft_strncmp(line, "ss\n", 3))
		ss(info);
	else
		error_print(1, info);
}

int	main(int argc, char	**argv)
{
	t_info	info;
	char	*line;

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
	while (1)
	{
		line = get_next_line(STDIN_FILENO);
		if (!line)
			break ;
		exec_ins(line, &info);
		free(line);
	}
	is_sort(&info);
	free_info(&info);
	return (0);
}
