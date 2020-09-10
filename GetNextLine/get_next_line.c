/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschirad <jschirad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 11:06:09 by jschirad          #+#    #+#             */
/*   Updated: 2019/11/30 12:03:42 by jschirad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static int	new_line(char **s, char **line, int len)
{
	char *tmp;

	while ((*s)[len] != '\n' && (*s)[len] != '\0')
		len++;
	if ((*s)[len] == '\n')
	{
		*line = ft_strndup(*s, len);
		tmp = ft_strndup((&(*s)[len + 1]), ft_strlen((&(*s)[len + 1])));
		free(*s);
		*s = tmp;
	}
	else
	{
		*line = *s;
		*s = NULL;
		return (0);
	}
	return (1);
}

static int	check_line(char **s, char **line, int size)
{
	int len;

	len = 0;
	if (size < 0)
		return (-1);
	else if (size == 0 && *s == NULL)
	{
		*line = ft_strndup("", 1);
		return (0);
	}
	else
		return (new_line(s, line, len));
}

int		get_next_line(int fd, char **line)
{
	int			size;
	char		*tmp;
	char		buff[BUFFER_SIZE + 1];
	static char	*s[4096];

	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	while ((size = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[size] = '\0';
		if (*s == NULL)
			*s = ft_strndup(buff, BUFFER_SIZE);
		else
		{
			tmp = ft_strjoin(*s, buff);
			free(*s);
			*s = tmp;
		}
		if (ft_strchr(*s, '\n'))
			break ;
	}
	return (check_line(s, line, size));
}
