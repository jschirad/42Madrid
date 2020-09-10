/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschirad <jschirad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 11:07:49 by jschirad          #+#    #+#             */
/*   Updated: 2019/11/16 14:21:26 by jschirad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	i;
	unsigned int	x;

	i = 0;
	if (!*needle)
		return ((char *)haystack);
	while (haystack[i] != '\0' && (size_t)i < len)
	{
		if (haystack[i] == needle[0])
		{
			x = 1;
			while (needle[x] != '\0' && haystack[i + x] == needle[x] &&
			(size_t)(i + x) < len)
				++x;
			if (needle[x] == '\0')
				return ((char *)&haystack[i]);
		}
		++i;
	}
	return (0);
}
