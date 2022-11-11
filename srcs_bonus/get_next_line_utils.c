/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccho <ccho@student.42.kr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 11:49:16 by ccho              #+#    #+#             */
/*   Updated: 2022/11/10 16:03:47 by ccho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

char	*ft_strdup(char *src)
{
	int		len;
	char	*nsrc;
	int		i;

	i = 0;
	len = ft_strlen(src);
	nsrc = (char *)malloc(sizeof(char) * (len + 1));
	if (!(nsrc))
		return (NULL);
	while (src[i])
	{
		nsrc[i] = src[i];
		i++;
	}
	nsrc[i] = '\0';
	return (nsrc);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	int		i;
	char	*newstr;

	i = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	newstr = (char *)malloc(len + 1);
	while (*s1)
	{
		newstr[i] = *s1;
		s1++;
		i++;
	}
	while (*s2)
	{
		newstr[i] = *s2;
		s2++;
		i++;
	}
	newstr[i] = 0;
	return (newstr);
}

int	ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	if (s[i] == '\0' && (char)c == '\0')
		return (i);
	else
		return (-1);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	j;

	i = start;
	j = 0;
	if (!s)
		return (NULL);
	substr = (char *)malloc(len + 1);
	if (!substr)
		return (NULL);
	if (i >= ft_strlen(s))
	{
		substr = malloc(1);
		substr[0] = 0;
		return (substr);
	}
	while (s[i] && j < len)
		substr[j++] = s[i++];
	substr[j] = 0;
	return (substr);
}
