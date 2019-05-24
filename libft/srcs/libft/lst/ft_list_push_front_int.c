/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front_int.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 13:17:17 by judumay           #+#    #+#             */
/*   Updated: 2019/05/24 14:35:04 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_list_push_front_int(t_list **begin_list, int i)
{
	t_list *tmp;

	if (*begin_list && begin_list)
	{
		tmp = ft_create_elem_int(i);
		tmp->next = (*begin_list);
		if (!((*begin_list) = tmp))
			return (0);
	}
	else
	{
		if (!((*begin_list) = ft_create_elem_int(i)))
			return (0);
	}
	return (1);
}
