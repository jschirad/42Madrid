/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschirad <jschirad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 15:09:57 by jschirad          #+#    #+#             */
/*   Updated: 2019/11/12 16:34:54 by jschirad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char		*ft_strrchr(const char *s, int c)
{
	char			*str;
	unsigned int	len;

	str = (char *)s;
	len = 0;
	while (str[len] != '\0')
		len++;
	if (*s == c)
		return ((char *)s);
	if (s || c)
	{
		while (len > 0)
		{
			if (str[len] == c)
				return (&str[len]);
			len--;
		}
	}
	return (NULL);
}
