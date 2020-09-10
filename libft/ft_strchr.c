/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschirad <jschirad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 14:27:12 by jschirad          #+#    #+#             */
/*   Updated: 2019/11/11 20:56:19 by jschirad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <strings.h>

char	*ft_strchr(const char *s, int c)
{
	if (*s == c)
		return ((char *)s);
	while (*(s++))
		if (*s == c)
			return ((char *)s);
	return (NULL);
}
