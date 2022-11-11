/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccho <ccho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 00:54:24 by ccho              #+#    #+#             */
/*   Updated: 2022/11/09 18:02:36 by ccho             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_count(char const *s, char c)
{
	int	cnt;

	cnt = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			cnt++;
			while (*s && *s != c)
				s++;
		}
	}
	return (cnt);
}

static char	*ft_strndup(const char *s, int n)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)malloc(n + 1);
	if (!str)
		return (NULL);
	while (i < n)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

char	**ft_free(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		i;
	int		count;
	int		tmp;

	i = 0;
	count = 0;
	split = (char **)malloc(sizeof(char *) * (ft_count(s, c) + 1));
	if (!split)
		return (NULL);
	while (count < ft_count(s, c) && s[i])
	{
		while (s[i] == c)
			i++;
		tmp = i;
		while (s[i] != c && s[i])
			i++;
		split[count] = ft_strndup(&s[tmp], i - tmp);
		if (!split[count])
			return (ft_free(split));
		count++;
	}
	split[count] = NULL;
	return (split);
}
