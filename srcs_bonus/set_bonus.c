/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccho <ccho@student.42.kr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:09:43 by ccho              #+#    #+#             */
/*   Updated: 2022/11/10 22:15:08 by ccho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

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
