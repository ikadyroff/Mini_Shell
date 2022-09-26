/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehoundey <ehoundey@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:57:16 by ehoundey          #+#    #+#             */
/*   Updated: 2022/06/20 18:01:21 by ehoundey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*newele;

	newlst = NULL;
	while (lst != NULL)
	{
		newele = ft_lstnew((*f)(lst->content));
		if (newele == NULL)
		{
			ft_lstclear(&newlst, (*del));
			free(newlst);
			return (NULL);
		}
		ft_lstadd_back(&newlst, newele);
		lst = lst->next;
	}
	return (newlst);
}
