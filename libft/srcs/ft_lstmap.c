/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 11:18:02 by mabouce           #+#    #+#             */
/*   Updated: 2018/11/11 14:33:38 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*first;
	t_list	*current;
	t_list	*tmp;

	if (lst && f)
	{
		tmp = f(lst);
		if (!(first = ft_lstnew(tmp->content, tmp->content_size)))
			return (NULL);
		current = first;
		lst = lst->next;
		while (lst->next)
		{
			tmp = f(lst);
			if (!(current->next = ft_lstnew(tmp->content, tmp->content_size)))
				return (NULL);
			current = current->next;
			lst = lst->next;
		}
		tmp = f(lst);
		if (!(current->next = ft_lstnew(tmp->content, tmp->content_size)))
			return (NULL);
		return (first);
	}
	return (NULL);
}
