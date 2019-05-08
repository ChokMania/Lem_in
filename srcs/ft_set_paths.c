/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_paths.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramard <lramard@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 15:11:17 by mabouce           #+#    #+#             */
/*   Updated: 2019/05/08 17:42:53 by lramard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_sp_set_starter(t_s *s, int i)
{
	i = 0;
	while (i < s->totalroom)
	{
		if (s->matrice[s->start_pos][i] == 1 && i != s->start_pos)
		{
			if (!(ft_ways_push_front(s, &s->ways, i)))
				s->ret = -9;
			s->weight[i][i] = 0;
		}
		i++;
	}
}

int		ft_sp_cross_room(t_s *s, t_list *beg, int i, int j)
{
	int		ok;
	t_list	*prev;

	prev = s->prev;
	while (beg)
	{
		beg->weight++;
		ok = 0;
		j = 0;
		while (j < s->totalroom && beg->finished == 0)
		{
			if ((s->ret = ft_sp_check_connection(s, beg, i, j)) == 1)
				return (1);
			else if (s->ret < 0)
				return (s->ret);
			j++;
		}
		if (beg->ttab[0][i] == -5 && s->algo == 1)
		{
			if (beg == s->ways && (ok = 1))
				prev = prev->next;
			ft_list_remove_middle_data_finalways(s, &s->ways, beg);
			beg = prev;
		}
		prev = beg;
		if (ok == 0)
			beg = beg->next;
	}
	return (0);//valeur de return non certaine
}

int			ft_set_paths(t_s *s)
{
	int		i;
	int		j;
	t_list	*beg;

	s->conflit = 0;
	s->tmpconflit = 0;
	i = 0;
	ft_sp_set_starter(s, i);
	beg = s->ways;
	s->prev = s->ways;
	i = 1;
	j = 0;
	s->kkt = 0;
	while (s->kkt < 60 && i < s->totalroom)
	{
		beg = s->ways;
		s->prev = s->ways;
		ft_sp_cross_room(s, beg, i, j);
		i++;
	}
	ft_print_ways(s);
	return (1);
}

long long	ft_set_maxway(t_s *s)
{
	long long i;

	i = 0;
	i = s->matrice[s->start_pos][s->start_pos];
	i = i < s->nbant ? i : s->nbant;
	i = i < s->matrice[s->end_pos][s->end_pos]
		? i : s->matrice[s->end_pos][s->end_pos];
	return (i);
}

int			ft_set_paths_start(t_s *s)
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
	if ((s->ret = ft_set_paths(s)) < -1)
		ft_error(s, s->ret);
	ft_del_useless_list_elem(s);
	return (1);
}
