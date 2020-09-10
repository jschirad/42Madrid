/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschirad <jschirad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 11:33:08 by jschirad          #+#    #+#             */
/*   Updated: 2019/11/13 14:20:33 by jschirad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	char	*str;
	int		c;

	c = count * size;
	str = malloc(c);
	if (!str)
		return (NULL);
	else
	{
		ft_bzero(str, c);
		return (str);
	}
}
