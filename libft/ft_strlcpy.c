/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschirad <jschirad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 17:39:14 by jschirad          #+#    #+#             */
/*   Updated: 2019/11/13 13:22:31 by jschirad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t			i;
	size_t			n;

	i = 0;
	n = 0;
	if (src != NULL)
	{
		n = ft_strlen(src);
		if (dst != NULL && dstsize != 0)
		{
			while (i < n && i < dstsize - 1)
			{
				dst[i] = src[i];
				i++;
			}
			dst[i] = '\0';
		}
	}
	return (n);
}
