/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschirad <jschirad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 13:24:11 by jschirad          #+#    #+#             */
/*   Updated: 2019/11/14 19:16:44 by jschirad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

static int	sizenb(unsigned int nb)
{
	unsigned int	size;

	size = 0;
	while (nb >= 10)
	{
		nb /= 10;
		++size;
	}
	return (size + 1);
}

char		*ft_itoa(int n)
{
	char			*str;
	unsigned int	nb;
	unsigned int	a;
	unsigned int	size;

	if (n < 0)
		nb = (unsigned int)(n * -1);
	else
		nb = (unsigned int)n;
	size = (unsigned int)sizenb(nb);
	a = 0;
	if (!(str = (char*)malloc(sizeof(char) * (size + 1 + (n < 0 ? 1 : 0)))))
		return (0);
	if (n < 0 && (str[a] = '-'))
		size++;
	a = size - 1;
	while (nb >= 10)
	{
		str[a--] = (char)(nb % 10 + 48);
		nb /= 10;
	}
	str[a] = (char)(nb % 10 + 48);
	str[size] = '\0';
	return (str);
}
