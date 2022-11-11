/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccho <ccho@student.42.kr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 15:09:45 by ccho              #+#    #+#             */
/*   Updated: 2022/11/10 16:04:36 by ccho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

void	free_str(char **str)
{
	free(*str);
	*str = NULL;
}

int	read_buffer(int fd, char *buf, char **str)
{
	int		num;
	char	*tmp;

	num = read(fd, buf, BUFFER_SIZE);
	while (num > 0)
	{
		buf[num] = '\0';
		if (!(*str))
			*str = ft_strdup(buf);
		else
		{
			tmp = ft_strjoin(*str, buf);
			free(*str);
			*str = ft_strdup(tmp);
			free(tmp);
		}
		if (ft_strchr(*str, '\n') >= 0)
			break ;
		num = read(fd, buf, BUFFER_SIZE);
	}
	return (num);
}

char	*parse_line(char **str, int num)
{
	char	*line;
	char	*tmp;
	int		index;

	index = ft_strchr(*str, '\n');
	if (index >= 0)
	{
		tmp = ft_strdup(*str);
		line = ft_substr(*str, 0, index + 1);
		free_str(str);
		if (index + 1 >= num || tmp[index + 1] == '\0')
		{
			free(tmp);
			return (line);
		}
		*str = ft_substr(tmp, index + 1, num);
		free(tmp);
	}
	else
	{
		line = ft_strdup(*str);
		free_str(str);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*buf;
	int			num;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	num = read_buffer(fd, buf, &str);
	free(buf);
	if (num < 0 || (!str && !num))
		return (NULL);
	num = ft_strlen(str);
	return (parse_line(&str, num));
}
