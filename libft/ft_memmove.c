/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschirad <jschirad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 13:40:14 by jschirad          #+#    #+#             */
/*   Updated: 2019/11/11 20:03:21 by jschirad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <strings.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char			*dest;
	const unsigned char		*sorc;

	if (dst < src)
		return (ft_memcpy(dst, src, len));
	dest = (unsigned char *)dst;
	sorc = (const unsigned char *)src;
	if (!len || dst == src)
		return (dst);
	while (len--)
	{
		dest[len] = sorc[len];
	}
	return (dst);
}
