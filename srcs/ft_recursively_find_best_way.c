/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursively_find_best_way.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 16:04:42 by mabouce           #+#    #+#             */
/*   Updated: 2019/05/02 13:24:37 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_way_is_in_conflict(t_s *s, t_list *first, t_list *second)
{
	int i;
	int	j;

	i = 0;
	/*ft_print_tab_tab_int_tmp(s, first->ttab, 3, s->totalroom);
	ft_putchar('\n');
	ft_print_tab_tab_int_tmp(s, second->ttab, 3, s->totalroom);
	ft_putchar('\n');
	ft_putchar('\n');
	ft_putchar('\n');
	*/while (i < s->totalroom && first->ttab[0][i] != -5)
	{
		if (first->ttab[2][i] == 1)
		{
			j = -1;
			while (++j < s->totalroom && second->ttab[0][j] != -5)
				if (second->ttab[2][j] == 1
					&& second->ttab[0][j] == first->ttab[0][i])
					return (1);
		}
		i++;
	}
	return (0);
}

int		ft_check_previous_conflicts(t_s *s, int *tab, int j)
{
	t_list	*current;
	t_list	*others;
	int		i;
	int		k;

	i = tab[j];
	current = s->finalways;
	if (i != 0)
	{
		while (i > 0 && current)
		{
			current = current->next;
			i--;
		}
		while (i < s->totalroom && tab[i] != -5 && (k = -1))
		{
			others = s->finalways;
			while (++k < tab[i])
				others = others->next;
			if (others != current && ft_way_is_in_conflict(s, others, current))
				return (0);
			i++;
		}
	}
	return (1);
}

int		ft_recursively_find_best_way(t_s *s, t_list *beg, int j, int p)
{
	if (s->maxwaytwo == 0)
		return (1);
	while (beg)
	{
		if (p == 0)
			s->first = beg;
		if (!ft_way_is_in_conflict(s, s->first, beg))
		{
			s->tab[j] = p;//pas bon
			if (s->tab[j] != - 5 && ft_check_previous_conflicts(s, s->tab, j))
			{
				s->maxwaytwo--;
				if (ft_recursively_find_best_way(s, beg->next, j + 1, p + 1))
				{
					return (1);
				}
				s->maxwaytwo++;
			}
			//s->tab[j] = -5;
		}
		p++;
		beg = beg->next;
	}
	return (0);
}

//t_list		*ft_del_list_elem(t_s *s)

int		ft_best_ways_found(t_s *s)
{
	s->maxwaytwo = ft_set_maxway(s);
	s->p = 0;
	if (ft_recursively_find_best_way(s, s->finalways, 0, 0))
	{
		//s->finalways = ft_del_list_elem(s);
		return (1);
	}
	ft_print_tab_int(s->tab, s->totalroom);
	return (0);
}
