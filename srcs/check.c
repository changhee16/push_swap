/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccho <ccho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:05:10 by ccho              #+#    #+#             */
/*   Updated: 2022/11/09 22:09:43 by ccho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	error_print(int flag, t_info	*info)
{
	if (flag == 1)
		write(2, "Error\n", 6);
	if (info)
		free_info(info);
	exit(-1);
}

void	check_argv(char	**argv, int flag, t_info	*info)
{
	int	i;

	if (flag == 2)
		i = -1;
	else
		i = 0;
	while (argv[++i])
	{
		if (ft_strlen(argv[i]) > 11)
			error_print(1, NULL);
		ft_push_atoi(argv[i], info);
	}
}
