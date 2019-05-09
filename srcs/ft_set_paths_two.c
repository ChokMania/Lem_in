/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_paths_two.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 15:11:17 by mabouce           #+#    #+#             */
/*   Updated: 2019/05/09 18:42:20 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			ft_parse_queue(int *tab)
{
	int i;

	i = -1;
	while (tab[++i] != -5)
	{
		if (tab[i] >= 0)
			break ;
	}
	if (tab[i] < 0)
		return (-4);
	return (tab[i]);
}

int			ft_algo_two(t_s *s)
{
	int *tab;
	int i_q;
	int beg;
	int	i;
	int	j;
	int k;
	int totalroom;

	if (!(tab = (int *)malloc(sizeof(int) * s->totalroom * 100000)))
		return (0);
	k = -1;
	while (++k < s->totalroom)
	{
		if (s->matrice[s->st_pos][k] == 1 && k != s->st_pos)
		{
			i_q = -1;
			while (++i_q < s->totalroom)
				tab[i_q] = -5;
			totalroom = -1;
			i_q = 0;
			beg = k;
			j = -1;
			s->weight[beg][0] = 0;
			s->weight[beg][1] = -5;
			tab[0] = beg;
			i = beg;
			while (j != s->end_pos && ++totalroom < s->totalroom)
			{
				j = -1;
				if (i == s->end_pos)
				{
					j = i;
					tab[++i_q] = j;
					break ;
				}
				i = ft_parse_queue(tab);
				if (i < 0)
					continue;
				while (++j < s->totalroom)
				{
					if (s->matrice[i][j] == 1 && i != j && s->weight[j][0] == -5 && j != s->st_pos)
					{
						s->weight[j][0] = s->weight[i][0] + 1;
						s->weight[j][1] = i;
						if (j == s->end_pos)
						{
							break ;
						}
						tab[++i_q] = j;
					}
				}
				tab[totalroom] = -1;
			}
			while (i_q > 0)
				tab[i_q--] = -5;
			if (i >= 0)
			{
				while (1)
				{
					if (j == -5)
						break ;
					tab[i_q++] = j;
					j != s->end_pos ? s->weight[j][0] = -1 : 0;
					j = s->weight[j][1];
				}
			}
			if (i >= 0)
				if (!(ft_ways_push_front_two(s, &s->ways, tab)))
					return (0);
			j = -1;
			while (++j < s->totalroom)
			{
				if (s->weight[j][0] != -1)
				{
					s->weight[j][0] = -5;
					s->weight[j][1] = -5;
				}
			}
		}
	}
//	ft_print_ways(s, s->ways);
	return (1);
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
	return (1);
}
