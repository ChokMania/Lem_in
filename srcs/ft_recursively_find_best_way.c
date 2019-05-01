/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursively_find_best_way.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 16:04:42 by mabouce           #+#    #+#             */
/*   Updated: 2019/05/01 17:05:41 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_check_previous_conflicts(t_s *s, int *tab, int j)
{
	t_list *current;
	t_list *others;
	int		i;
	int		k;

	i = tab[j];
	current = s->finalways;
	while (i-- > 0)
		current = current->next;
	while (i < s->totalroom && tab[i] != -5)
	{
		k = 0;
		others = s->finalways;
		while (k < tab[i])
		{
			others = others->next;
			k++;
		}
		if (others != current && ft_way_is_in_conflict(s, others, current))
			return (0);
		i++;
	}
	return (1);
}

int	ft_recursively_find_best_way(t_s *s, t_list *beg, t_list *first, int j)
{
	if (s->maxwaytwo == 0)
		return (1);
	while (beg)
	{
		if (j == 0)
			first = beg;
		if (!ft_way_is_in_conflict(s, first, beg))
		{
			s->tab[j] = s->p;
			if (ft_check_previous_conflicts(s, s->tab, j))
			{
				s->maxwaytwo--;
				if (ft_recursively_find_best_way(s, beg->next, first, j + 1))
					return (1);
				s->maxwaytwo++;
			}
			s->tab[j] = -5;
		}
		s->p++;
		beg = beg->next;
	}
	return (0);
}
