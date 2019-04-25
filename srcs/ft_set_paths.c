/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_paths.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 15:11:17 by mabouce           #+#    #+#             */
/*   Updated: 2019/04/24 15:24:00 by mabouce          ###   ########.fr       */
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

void		ft_set_paths(t_s *s, int line, int weight)
{
	int	j;

	j = -1;
	if (line == s->end_pos)
	{
		if (s->maxway-- > 0)
			!ft_add_to_ways(s, &s->ways, weight) ? ft_error(s, -7) : 0;
		else if (weight < s->ways->biggest->weight)
			!(ft_replace_to_ways(s, &s->ways, weight)) ? ft_error(s, -7) : 0;
		else if (s->totalplays > (s->k = ft_total_weight(s, weight)))
			if ((s->totalplays = s->k) && !ft_add_to_ways(s, &s->ways, weight))
				ft_error(s, -7);
	}
	else
		while (++j < s->totalroom)
			if (j != line && s->matrice[line][j] == 1)
				if ((s->weight[j][0] && weight + 1 <= s->weight[j][0])
						|| !s->weight[j][0])
				{
					s->pastway[weight] = j;
					s->weight[line][0] = weight;
					ft_set_paths(s, j, weight + 1);
				}
	s->pastway[weight - 1] = -1;
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
	s->max_w = s->totalroom;
	if (!(s->pastway = (int *)malloc(sizeof(int) * s->totalroom)))
		ft_error(s, -6);
	while (++s->i < s->totalroom)
		s->pastway[s->i] = -1;
	s->pastway[0] = s->start_pos;
	ft_set_paths(s, s->start_pos, 1);
	ft_list_print_int_remake(s);
	if (!s->ways)
		ft_error(s, -7);
	return (1);
}
