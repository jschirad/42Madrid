/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschirad <jschirad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 14:18:47 by jschirad          #+#    #+#             */
/*   Updated: 2019/11/11 19:41:08 by jschirad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <strings.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dest;
	unsigned char	*sorc;

	dest = (unsigned char *)dst;
	sorc = (unsigned char *)src;
	if (dst || src)
	{
		while (n > 0)
		{
			if ((*dest = *sorc) == (unsigned char)c)
				return (dest + 1);
			dest++;
			sorc++;
			n--;
		}
	}
	return (NULL);
}
