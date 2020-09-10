/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschirad <jschirad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 10:45:44 by jschirad          #+#    #+#             */
/*   Updated: 2019/11/17 14:56:55 by jschirad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*aux_lst;
	t_list	*aux_new;

	aux_lst = lst;
	new_lst = NULL;
	if (aux_lst != NULL)
	{
		if ((new_lst = (t_list *)malloc(sizeof(t_list))))
		{
			aux_new = new_lst;
			while (aux_lst != NULL && aux_new != NULL)
			{
				aux_new->content = f(aux_lst->content);
				if ((aux_new->next = (t_list*)malloc(sizeof(t_list))))
				{
					aux_new = aux_new->next;
					aux_lst = aux_lst->next;
				}
				else
					ft_lstclear(&new_lst, del);
			}
		}
	}
	return (new_lst);
}
