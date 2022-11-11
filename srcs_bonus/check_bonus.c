/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccho <ccho@student.42.kr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:07:50 by ccho              #+#    #+#             */
/*   Updated: 2022/11/10 16:08:58 by ccho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

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
