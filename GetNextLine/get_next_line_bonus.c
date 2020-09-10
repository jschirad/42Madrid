/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschirad <jschirad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 12:01:27 by jschirad          #+#    #+#             */
/*   Updated: 2019/11/30 12:19:10 by jschirad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
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

int			get_next_line(const int fd, char **line)
{
	int			size;
	static char	*s[4096];
	char		buff[BUFFER_SIZE + 1];
	char		*tmp;

	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	while ((size = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[size] = '\0';
		if (s[fd] == NULL)
			s[fd] = ft_strndup(buff, BUFFER_SIZE);
		else
		{
			tmp = ft_strjoin(s[fd], buff);
			free(s[fd]);
			s[fd] = tmp;
		}
		if (ft_strchr(s[fd], '\n'))
			break ;
	}
	return (check_line(&(s[fd]), line, size));
}
