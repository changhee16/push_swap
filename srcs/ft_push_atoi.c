/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccho <ccho@student.42.kr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 16:56:04 by ccho              #+#    #+#             */
/*   Updated: 2022/11/10 22:11:54 by ccho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	space_handle(const char *str, int *i)
{	
	while (((str[*i] >= 9) && (str[*i] <= 13)) || (str[*i] == 32))
			*i += 1;
}

int	ft_push_atoi(const char *str, t_info	*info)
{
	int			sign;
	long long	result;
	int			i;

	sign = 1;
	result = 0;
	i = 0;
	space_handle(str, &i);
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	if (str[i] == '\0')
		error_print(1, info);
	i--;
	while (str[++i] >= '0' && str[i] <= '9')
		result = 10 * result + (str[i] - '0');
	result = result * sign;
	if (str[i] != '\0' || result > 2147483647 || result < -2147483648)
		error_print(1, info);
	return (result);
}
