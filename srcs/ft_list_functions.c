/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 15:11:32 by mabouce           #+#    #+#             */
/*   Updated: 2019/04/24 15:14:47 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_list		*ft_create_elem_tab_int(t_s *s, int weight)
{
	t_list	*new;
	int		*tab;

	s->k = -1;
	if (!(tab = (int *)malloc(sizeof(int) * s->totalroom)))
		return (0);
	while (++s->k < s->totalroom)
		tab[s->k] = s->pastway[s->k];
	if (!(new = malloc(sizeof(t_list))))
		return (NULL);
	new->next = NULL;
	new->biggest = NULL;
	new->tab = tab;
	new->weight = weight;
	return (new);
}

void		ft_set_biggest(t_list **begin_list, t_list *biggest)
{
	t_list *beg;

	beg = *begin_list;
	while (beg)
	{
		beg->biggest = biggest;
		beg = beg->next;
	}
}

int			ft_add_to_ways(t_s *s, t_list **begin_list, int weight)
{
	t_list	*tmp;

	if (*begin_list && begin_list)
	{
		if (!(tmp = ft_create_elem_tab_int(s, weight)))
			return (0);
		tmp->next = (*begin_list);
		(*begin_list) = tmp;
		if (tmp->weight <= tmp->next->biggest->weight)
			tmp->biggest = tmp->next->biggest;
		else
			ft_set_biggest(begin_list, tmp);
	}
	else
	{
		if (!((*begin_list) = ft_create_elem_tab_int(s, weight)))
			return (0);
		(*begin_list)->biggest = (*begin_list);
	}
	return (1);
}

void		ft_list_print_int_remake(t_s *s)
{
	int		i;
	int		chemin;
	t_list	*beg;

	beg = s->ways;
	chemin = 1;
	while (beg)
	{
		i = -1;
		if (beg->tab)
		{
			miniprintf("%%%%Chemin numero :%% %i\n", "BOLD", "UNDER",
					"END", chemin++);
			while (++i < s->totalroom && beg->tab[i] != -1)
				miniprintf("%d -> name : %s\n", beg->tab[i]
						, s->namematrice[beg->tab[i]]);
		}
		beg = beg->next;
	}
}

int			ft_replace_to_ways(t_s *s, t_list **begin_list, int weight)
{
	t_list	*new_biggest;
	t_list	*tmp;

	if (!begin_list)
		return (0);
	tmp = *begin_list;
	if (tmp->biggest && tmp == tmp->biggest)
		ft_list_remove_first_int(begin_list);
	else if (tmp->biggest && tmp->biggest->next)
		ft_list_remove_middle_int(begin_list, tmp->biggest);
	else if (tmp->biggest && !tmp->biggest->next)
		ft_list_remove_last_int(begin_list);
	else
		return (0);
	ft_add_to_ways(s, begin_list, weight);
	return (1);
}
