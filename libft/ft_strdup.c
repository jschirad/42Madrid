/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschirad <jschirad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 15:30:43 by jschirad          #+#    #+#             */
/*   Updated: 2019/11/12 10:10:28 by jschirad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*src;
	size_t	n;

	n = ft_strlen(s1);
	if (!(src = (char *)malloc(sizeof(char) * (n + 1))))
	{
		return (0);
	}
	return (ft_memcpy(src, s1, n + 1));
}
