/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschirad <jschirad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 18:50:02 by jschirad          #+#    #+#             */
/*   Updated: 2019/11/14 18:55:49 by jschirad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

static char	ft_strncpy(char *dst, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] != 0 && i < n)
	{
		dst[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dst[i] = 0;
		i++;
	}
	return (*dst);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int		a;
	int		b;
	char	*s2;

	a = 0;
	if (s1 == 0)
		return (0);
	while (ft_strchr(set, s1[a]) != 0 && s1[a] != 0)
		a++;
	b = ft_strlen(s1) - a;
	if (b != 0)
	{
		while (ft_strchr(set, s1[b + a - 1]) != 0 && a < b - 1)
			b--;
	}
	if (!(s2 = (char *)malloc(sizeof(char) * (b + 1))))
		return (0);
	ft_strncpy(s2, &((char *)s1)[a], b);
	s2[b] = 0;
	return (s2);
}
