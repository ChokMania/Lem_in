/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 15:11:32 by mabouce           #+#    #+#             */
/*   Updated: 2019/04/26 18:59:45 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"


t_list		*ft_create_elem_tab_way(t_s *s, int i)
{
	t_list	*new;
	int		**tab;
	int		j;
	int		k;

	if (!(tab = (int **)malloc(sizeof(int *) * (3))))
		return (0);
	j = 0;
	while (j < 3)
	{
		k = 0;
		if (!(tab[j] = (int *)malloc(sizeof(int) * s->totalroom)))
		{
			ft_inttabdel(&tab, s->totalroom);
			return (0);
		}
		while (k < s->totalroom)
		{
			tab[j][k] = 0;
			k++;
		}
		j++;
	}
	tab[0][0] = s->start_pos;
	if (!(new = malloc(sizeof(t_list))))
		return (NULL);
	new->next = NULL;
	new->i = i;
	new->ttab = tab;
	return (new);
}

int			ft_ways_push_front(t_s *s, t_list **begin_list, int i)
{
	t_list	*tmp;

	if (*begin_list && begin_list)
	{
		if (!(tmp = ft_create_elem_tab_way(s, i)))
			return (0);
		tmp->next = (*begin_list);
		(*begin_list) = tmp;
	}
	else
	{
		if (!((*begin_list) = ft_create_elem_tab_way(s, i)))
			return (0);
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
