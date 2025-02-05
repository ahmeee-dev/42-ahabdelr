/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabdelr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:34:14 by ahabdelr          #+#    #+#             */
/*   Updated: 2024/12/16 15:18:17 by ahabdelr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first;
	t_list	*new;
	t_list	*alias;

	first = NULL;
	alias = lst;
	while (alias)
	{
		new = ft_lstnew(f(alias->content));
		if (new != NULL)
		{
			ft_lstadd_back(&first, new);
			alias = alias->next;
		}
		else
		{
			ft_lstclear(&first, del);
			ft_lstclear(&lst, del);
		}
	}
	return (first);
}
