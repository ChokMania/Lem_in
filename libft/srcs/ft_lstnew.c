/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 18:27:04 by mabouce           #+#    #+#             */
/*   Updated: 2019/03/03 16:59:29 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *data, size_t content_size)
{
	t_list	*new;

	if (!(new = malloc(sizeof(t_list))))
		return (NULL);
	if (!data)
	{
		new->data = NULL;
		new->content_size = 0;
		new->next = NULL;
	}
	else
	{
		if (!(new->data = ft_memalloc(content_size)))
			return (NULL);
		ft_memcpy(new->data, data, content_size);
		new->content_size = content_size;
		new->next = NULL;
	}
	return (new);
}
