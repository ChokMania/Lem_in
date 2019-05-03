/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursively_find_best_way.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 16:04:42 by mabouce           #+#    #+#             */
/*   Updated: 2019/05/03 17:04:07 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_duptabint(int *tab1, int *tab2, t_s *s)
{
	int i;

	i = 0;
	while (tab2[i] != -5 && i < s->totalroom)
	{
		tab1[i] = tab2[i];
		i++;
	}
}

int		ft_way_is_in_conflict(t_s *s, t_list *first, t_list *second)
{
	int i;
	int	j;

	i = 0;
	while (i < s->totalroom && first->ttab[0][i] != -5)
	{
		if (first->ttab[2][i] == 1)
		{
			j = -1;
			while (++j < s->totalroom && second->ttab[0][j] != -5)
				if (second->ttab[2][j] == 1
					&& second->ttab[0][j] == first->ttab[0][i])
				{
					return (1);
				}
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
		if (beg == s->first || !ft_way_is_in_conflict(s, s->first, beg))
		{
			if (beg == s->first || j == 0 || s->tmptab[j - 1] != p)
			{
				s->tmptab[j] = p;
				if (beg == s->first || ft_check_previous_conflicts(s, s->tmptab, j))
				{
					s->maxwaytwo--;
					if (ft_lenint(s->tmptab, s) > ft_lenint(s->tab, s))
						ft_duptabint(s->tab, s->tmptab, s);
					if (ft_recursively_find_best_way(s, beg->next, j + 1, p + 1))
						return (1);
					s->maxwaytwo++;
				}
				s->tmptab[j] = -5;
			}
		}
		p++;
		beg = beg->next;
	}
	return (0);
}

int		ft_best_ways_found(t_s *s)
{
	int i;

	if (s->tmptab == NULL)
	{
		i = -1;
		if (!(s->tmptab = (int *)malloc(sizeof(int) * s->totalroom + 1)))
			return (-5);
		while (++i < s->totalroom)
			s->tmptab[i] = -5;
	}
	s->maxwaytwo = ft_set_maxway(s);
	s->p = 0;
	if (ft_recursively_find_best_way(s, s->finalways, 0, 0))
		return (1);
	return (0);
}
