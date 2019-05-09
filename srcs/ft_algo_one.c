/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_one.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 08:43:31 by judumay           #+#    #+#             */
/*   Updated: 2019/05/09 17:10:03 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			ft_algo_if(t_s *s, int t[4], t_list *beg, int check)
{
	if (check == 0)
	{
		t[1]++;
		s->maxway--;
		beg->finished = 1;
		if (!(ft_list_copy(s, &s->finalways, beg)))
			ft_error(s, -10);
		if (ft_best_ways_found(s))
			return (1);
	}
	if (check == 1)
	{
		if ((t[0] < 2) || (t[0] >= 2 && t[3] != beg->ttab[0][t[0] - 2]))
		{
			if (ft_check_prev(beg, t[0], t[3]) == 1)
			{
				beg->ttab[0][t[0]] = t[3];
				beg->ttab[1][t[0]] = 1;
			}
		}
	}
	return (0);
}

int			ft_second_while_algo(t_s *s, t_list *beg, int t[4])
{
	t[3] = -1;
	t[2] = 0;
	while (++t[3] < s->totalroom && beg->finished == 0)
		if (beg->ttab[0][t[0] - 1] == s->end_pos)
		{
			if (ft_algo_if(s, t, beg, 0) == 1)
				return (1);
		}
		else if (beg->ttab[0][t[0] - 1] > -5 && beg->finished == 0
			&& t[3] != s->st_pos && s->matrice[beg->ttab[0][t[0] - 1]][t[3]]
			== 1 && beg->ttab[0][t[0] - 1] != t[3] && beg->ttab[1][t[0]] < 0
			&& (s->matrice[t[3]][t[3]] > 1 || t[3] == s->end_pos))
			ft_algo_if(s, t, beg, 1);
		else if (beg->ttab[0][t[0] - 1] > -5 && beg->finished == 0 &&
			t[3] != s->st_pos && s->matrice[beg->ttab[0][t[0] - 1]][t[3]] == 1
			&& beg->ttab[0][t[0] - 1] != t[3] && beg->ttab[1][t[0]] > 0
			&& (s->matrice[t[3]][t[3]] > 1 || t[3] == s->end_pos))
			if ((t[0] < 2) || (t[0] >= 2 && t[3] != beg->ttab[0][t[0] - 2]))
				if (ft_check_prev(beg, t[0], t[3]) == 1)
				{
					beg->ttab[2][t[0] - 1] = 1;
					if (!(ft_duplicate_ways_push(s, beg, t[0], t[3])))
						ft_error(s, -10);
				}
	return (0);
}

int			ft_while_algo(t_s *s, t_list *beg, t_list *prev, int t[4])
{
	while (t[1] < 60 && t[0] < s->totalroom)
	{
		beg = s->ways;
		prev = s->ways;
		while (beg)
		{
			beg->weight++;
			if (ft_second_while_algo(s, beg, t))
				return (1);
			if (beg->ttab[0][t[0]] == -5 && s->algo == 1)
			{
				if (beg == s->ways && (t[2] = 1))
					prev = prev->next;
				ft_list_remove_middle_data_finalways(s, &s->ways, beg);
				beg = prev;
			}
			prev = beg;
			if (t[2] == 0)
				beg = beg->next;
		}
		t[0]++;
	}
	return (0);
}

int			ft_set_paths(t_s *s)
{
	int		t[4];
	t_list	*beg;
	t_list	*prev;

	t[0] = 0;
	s->conflit = 0;
	s->tmpconflit = 0;
	while (t[0] < s->totalroom)
	{
		if (s->matrice[s->st_pos][t[0]] == 1 && t[0] != s->st_pos)
		{
			if (!(ft_ways_push_front(s, &s->ways, t[0])))
				ft_error(s, -9);
			s->weight[t[0]][t[0]] = 0;
		}
		t[0]++;
	}
	beg = s->ways;
	prev = s->ways;
	t[0] = 1;
	t[1] = 0;
	ft_while_algo(s, beg, prev, t);
	return (1);
}
