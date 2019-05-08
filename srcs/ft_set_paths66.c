

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_paths22.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramard <lramard@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 15:11:17 by mabouce           #+#    #+#             */
/*   Updated: 2019/05/08 16:11:43 by lramard          ###   ########.fr       */
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

int		ft_way_have_no_conflict(t_s *s, t_list *current)
{
	int i;

	i = 0;
	while (i < s->totalroom)
	{
		if (current->ttab[2][i] > 0)
			return (0);
		i++;
	}
	return (1);
}

int			ft_set_paths(t_s *s)
{
	int	i;
	int	j;
	int	k;
	int	ok;
	t_list *beg;
	t_list *prev;

	i = 0;
	s->conflit = 0;
	s->tmpconflit = 0;
	while (i < s->totalroom)
	{
		if (s->matrice[s->start_pos][i] == 1 && i != s->start_pos)
		{
			if (!(ft_ways_push_front(s, &s->ways, i)))
				return (-9);
			s->weight[i][i] = 0;
		}
		i++;
	}
	beg = s->ways;
	prev = s->ways;
	i = 1;
	k = 0;
	while (k < 60 && i < s->totalroom)
	{
		beg = s->ways;
		prev = s->ways;
		while (beg)
		{
			beg->weight++;
			ok = 0;
			j = 0;
			while (j < s->totalroom && beg->finished == 0)
			{
				if (beg->ttab[0][i - 1] == s->end_pos)
				{
					k++;
					s->maxway--;
					beg->finished = 1;
					if (!(ft_list_copy(s, &s->finalways, beg)))
						return (-10);
					if (ft_best_ways_found(s))
						return (1);
				}
				else if (beg->ttab[0][i - 1] > -5 && beg->finished == 0
					&& j != s->start_pos && s->matrice[beg->ttab[0][i - 1]][j]
						== 1 && beg->ttab[0][i - 1] != j && beg->ttab[1][i] < 0
							&& (s->matrice[j][j] > 1 || j == s->end_pos))
				{
					if ((i < 2) || (i >= 2 && j != beg->ttab[0][i - 2]))
					{
						if (ft_check_prev(beg, i, j) == 1)
						{
							beg->ttab[0][i] = j;
							beg->ttab[1][i] = 1;
						}
					}
				}
				else if (beg->ttab[0][i - 1] > -5 && beg->finished == 0 &&
					j != s->start_pos && s->matrice[beg->ttab[0][i - 1]][j] == 1
						&& beg->ttab[0][i - 1] != j && beg->ttab[1][i] > 0
							&& (s->matrice[j][j] > 1 || j == s->end_pos))
				{
					if ((i < 2) || (i >= 2 && j != beg->ttab[0][i - 2]))
					{
						if (ft_check_prev(beg, i, j) == 1)
						{
							beg->ttab[2][i - 1] = 1;
							if (!(ft_duplicate_ways_push(s, beg, i, j)))
								return (0);
						}
					}
				}
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
		i++;
	}
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
