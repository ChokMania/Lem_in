/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_paths_one_cont_two.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramard <lramard@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 10:38:11 by lramard           #+#    #+#             */
/*   Updated: 2019/05/08 10:38:14 by lramard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			ft_check_prev(t_list *beg, int i, int j)
{
	i++;
	while (i > 0)
	{
		if (beg->ttab[0][i - 1] == j)
			return (0);
		i--;
	}
	return (1);
}

int			ft_duplicate_ways_push(t_s *s, t_list *beg, int currentmove, int j)
{
	int		i;
	t_list	*new;

	if (!(ft_ways_push_front(s, &s->ways, j)))
		return (0);
	i = 0;
	new = s->ways;
	while (i < s->totalroom)
	{
		new->ttab[0][i] = beg->ttab[0][i];
		new->ttab[1][i] = beg->ttab[1][i];
		new->ttab[2][i] = beg->ttab[2][i];
		i++;
	}
	new->ttab[0][currentmove] = j;
	new->weight = beg->weight;
	return (1);
}

void		first(t_s *s, t_list *beg)
{
	miniprintf("first\n");
	s->kkt++;
	s->maxway--;
	beg->finished = 1;
	if (!(ft_list_copy(s, &s->finalways, beg)))
		s->ret = -10;
	if (ft_best_ways_found(s))
		s->ret = 1;
}

void		second(t_list *beg, int i, int j)
{
	miniprintf("second\n");
	if ((i < 2) || (i >= 2 && j != beg->ttab[0][i - 2]))
	{
		if (ft_check_prev(beg, i, j) == 1)
		{
			beg->ttab[0][i] = j;
			beg->ttab[1][i] = 1;
		}
	}
}

void		third(t_s *s, t_list *beg, int i, int j)
{
	miniprintf("third\n");
	if ((i < 2) || (i >= 2 && j != beg->ttab[0][i - 2]))
	{
		if (ft_check_prev(beg, i, j) == 1)
		{
			beg->ttab[2][i - 1] = 1;
			if (!(ft_duplicate_ways_push(s, beg, i, j)))
				s->ret = 0;
		}
	}
}
