/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_functions_two.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 15:11:32 by mabouce           #+#    #+#             */
/*   Updated: 2019/05/16 14:53:24 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_list		*ft_create_elem_tab_way_two(t_s *s, int *tab)
{
	t_list	*new;
	int		i;

	i = -1;
	if (!(new = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	new->tab = NULL;
	if (!(new->tab = (int*)malloc(sizeof(int) * s->totalroom)))
	{
		free(new);
		return (NULL);
	}
	while (++i < s->totalroom)
		new->tab[i] = tab[i];
	new->ttab = NULL;
	new->next = NULL;
	return (new);
}

int			ft_ways_push_front_two(t_s *s, t_list **begin_list, int *tab)
{
	t_list	*tmp;

	if (*begin_list && begin_list)
	{
		if ((tmp = ft_create_elem_tab_way_two(s, tab)) == NULL)
			return (0);
		tmp->next = (*begin_list);
		(*begin_list) = tmp;
	}
	else
	{
		if (!((*begin_list) = ft_create_elem_tab_way_two(s, tab)))
			return (0);
	}
	return (1);
}
