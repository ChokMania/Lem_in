/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_paths_two.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 15:11:17 by mabouce           #+#    #+#             */
/*   Updated: 2019/05/10 15:10:44 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_reverse_final(t_s *s)
{
	t_list	*beg;
	int		t;
	int		i;
	int		j;

	beg = s->finalways;
	while (beg)
	{
		i = 0;
		j = ft_lenint(beg->tab, s) - 1;
		while (i < j)
		{
			t = beg->tab[j];
			beg->tab[j] = beg->tab[i];
			beg->tab[i] = t;
			j--;
			i++;
		}
		beg = beg->next;
	}
}

void		ft_is_worth(t_s *s, int i)
{
	int		total;
	t_list	*beg;

	beg = s->ways;
	total = 0;
	while (beg && (i = 0))
	{
		while (beg->tab[i] != -5 && i < s->totalroom)
			i++;
		total += i - 1;
		beg = beg->next;
	}
	if ((beg = s->ways) && (!ft_list_size(s->finalways) || (s->nbant + total)
		/ ft_list_size(s->finalways) > (s->nbant + s->max_weight)
		/ ft_list_size(s->ways)))
	{
		s->finalways ? ft_list_clear(&s->finalways) : 0;
		s->max_weight = total;
		while (beg)
		{
			ft_ways_push_front_two(s, &s->finalways, beg->tab);
			beg = beg->next;
		}
	}
}

int			ft_set_paths_start_two(t_s *s)
{
	int i;

	s->i = -1;
	if (!(s->tab = (int *)malloc(sizeof(int) * s->totalroom)))
		ft_error(s, -7);
	while (++s->i < s->totalroom)
		s->tab[s->i] = -5;
	i = -1;
	if (!(s->tb = (int *)malloc(sizeof(int) * s->totalroom)))
		ft_error(s, -8);
	while (++i < s->totalroom)
		s->tb[i] = -5;
	s->i = 0;
	s->maxway = ft_set_maxway(s);
	ft_algo_two(s);
	ft_reverse_final(s);
	ft_sort_list(s->finalways, s);
	return (1);
}
