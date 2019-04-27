/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_paths.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 15:11:17 by mabouce           #+#    #+#             */
/*   Updated: 2019/04/26 18:59:43 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			ft_total_weight(t_s *s, int weight)
{
	int		totalway;
	int		totalweight;
	t_list	*beg;

	totalway = 0;
	totalweight = 0;
	beg = s->ways;
	while (beg)
	{
		totalway++;
		totalweight += beg->weight - 1;
		beg = beg->next;
	}
	return ((s->nbant + totalweight + weight - 1) / (totalway + 1));
}

void		ft_set_paths(t_s *s)
{
	int i;

	i = 0;
	while (i < s->start_pos)
	{
		if (s->matrice[s->start_pos][i] == 1)
			ft_ways_push_front(s, &s->ways, i);
		i++;
	}
	miniprintf("%%start paths = %i\n%%", "RED", ft_list_size(s->ways), "END");
	s->ways = s->ways->next;
	ft_print_tab_tab_int(s->ways->ttab, 3, s->totalroom);
}

void		ft_set_maxway(t_s *s)
{
	s->maxway = s->matrice[s->start_pos][s->start_pos];
	s->maxway = s->maxway < s->nbant ? s->maxway : s->nbant;
	s->maxway = s->maxway < s->matrice[s->end_pos][s->end_pos]
		? s->maxway : s->matrice[s->end_pos][s->end_pos];
}

int			ft_set_paths_start(t_s *s)
{
	s->i = -1;
	s->totalplays = s->totalroom * s->nbant;
	ft_set_maxway(s);
	ft_set_paths(s);
	if (!s->ways)
		ft_error(s, -7);
	return (1);
}
