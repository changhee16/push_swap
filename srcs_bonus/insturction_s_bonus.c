/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insturction_s_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccho <ccho@student.42.kr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:39:05 by ccho              #+#    #+#             */
/*   Updated: 2022/11/10 17:54:25 by ccho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

void	sa(t_info	*info, int flag)
{
	int	tmp;

	if (!(info->top_a) || !(info->top_a->next))
		return ;
	tmp = info->top_a->data;
	info->top_a->data = info->top_a->next->data;
	info->top_a->next->data = tmp;
	if (flag == 1)
		write(1, "sa\n", 3);
}

void	sb(t_info	*info, int flag)
{
	int	tmp;

	if (!(info->top_b) || !(info->top_b->next))
		return ;
	tmp = info->top_b->data;
	info->top_b->data = info->top_b->next->data;
	info->top_b->next->data = tmp;
	if (flag == 1)
		write(1, "sb\n", 3);
}

void	ss(t_info	*info)
{
	if (!(info->top_a) || !(info->top_a->next))
		return ;
	sa(info, 0);
	if (!(info->top_b) || !(info->top_b->next))
		return ;
	sb(info, 0);
}
