/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschirad <jschirad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 15:45:09 by jschirad          #+#    #+#             */
/*   Updated: 2019/11/11 20:24:16 by jschirad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char			*str1;
	const unsigned char		*str2;

	if (!n)
		return (0);
	str1 = (unsigned char *)s1;
	str2 = (const unsigned char *)s2;
	if (*str1 == *str2)
	{
		while (--n && *str1 == *str2)
		{
			++str1;
			++str2;
		}
	}
	return (*str1 - *str2);
}
