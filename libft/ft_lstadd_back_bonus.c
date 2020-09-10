/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschirad <jschirad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 19:24:55 by jschirad          #+#    #+#             */
/*   Updated: 2019/11/17 13:46:16 by jschirad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*p_new;

	p_new = *alst;
	if (alst == NULL)
		return ;
	if (p_new == NULL)
		*alst = new;
	else
	{
		while (p_new->next)
			p_new = p_new->next;
		p_new->next = new;
	}
}
