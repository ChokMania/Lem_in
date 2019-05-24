/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach_if.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 20:46:41 by judumay           #+#    #+#             */
/*   Updated: 2019/05/24 14:40:36 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_foreach_if(t_list *begin_list, void (*f)(void *)
		, void *data_ref, int (*cmp)())
{
	if (!begin_list)
		return ;
	while (begin_list)
	{
		if (cmp(begin_list->data, data_ref) == 0)
			f(begin_list->data);
		begin_list = begin_list->next;
	}
}
