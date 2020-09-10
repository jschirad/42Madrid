/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschirad <jschirad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 19:24:17 by jschirad          #+#    #+#             */
/*   Updated: 2019/11/11 17:44:17 by jschirad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			x;

	x = 0;
	if (n == 0)
		return (0);
	while (s1[x] && s2[x] && s1[x] == s2[x] && (x < n - 1))
		x++;
	return ((unsigned char)s1[x] - (unsigned char)s2[x]);
}
