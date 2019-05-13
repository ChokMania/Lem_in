/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 15:22:06 by judumay           #+#    #+#             */
/*   Updated: 2019/05/13 08:36:34 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		ft_everything_push(t_s *s, int *tab, int t[5])
{
	while (t[0] > 0)
		tab[t[0]--] = -5;
	if (t[3] >= 0)
	{
		while (1)
		{
			if (t[2] == -5)
				break ;
			tab[t[0]++] = t[2];
			t[2] != s->end_pos ? s->weight[t[2]][0] = -1 : 0;
			t[2] = s->weight[t[2]][1];
		}
	}
	if (t[3] >= 0)
		if (!(ft_ways_push_front_two(s, &s->ways, tab)))
			ft_error(s, -7);
	t[2] = -1;
}

static void		ft_complete_bfs(t_s *s, int *tab, int t[5])
{
	while (t[2] != s->end_pos && ++t[4] < s->totalroom)
	{
		t[2] = -1;
		if (t[3] == s->end_pos)
		{
			t[2] = t[3];
			tab[++t[0]] = t[2];
			break ;
		}
		t[3] = ft_parse_queue(tab);
		if (t[3] < 0)
			continue ;
		while (++t[2] < s->totalroom)
			if (s->matrice[t[3]][t[2]] == 1 && t[3] != t[2]
				&& s->weight[t[2]][0] == -5 && t[2] != s->st_pos)
			{
				s->weight[t[2]][0] = s->weight[t[3]][0] + 1;
				s->weight[t[2]][1] = t[3];
				if (t[2] == s->end_pos)
					break ;
				tab[++t[0]] = t[2];
			}
		tab[t[4]] = -1;
	}
}

static void		ft_init(t_s *s, int t[5], int *tab, int k)
{
	t[0] = -1;
	while (++t[0] < s->totalroom)
		tab[t[0]] = -5;
	t[4] = -1;
	t[0] = 0;
	t[1] = k;
	t[2] = -1;
	s->weight[t[1]][0] = 0;
	s->weight[t[1]][1] = -5;
	tab[0] = t[1];
	t[3] = t[1];
}

void			ft_first_while(t_s *s, int k, int save, int *tab)
{
	int	t[5];

	while (++save < s->totalroom)
	{
		k++;
		if (k == s->totalroom)
			k = 0;
		if (s->matrice[s->st_pos][k] == 1 && k != s->st_pos)
		{
			ft_init(s, t, tab, k);
			ft_complete_bfs(s, tab, t);
			ft_everything_push(s, tab, t);
			while (++t[2] < s->totalroom)
			{
				if (s->weight[t[2]][0] != -1)
				{
					s->weight[t[2]][0] = -5;
					s->weight[t[2]][1] = -5;
				}
			}
		}
	}
}

int				ft_algo_two(t_s *s)
{
	int *tab;
	int k;
	int u;

	if (!(tab = (int *)malloc(sizeof(int) * s->totalroom * s->totalroom)))
		ft_error(s, -6);
	u = 0;
	while (++u <= s->matrice[s->st_pos][s->st_pos])
	{
		k = ft_choose_the_one(u, s);
		ft_first_while(s, k, -1, tab);
		ft_reset_weight(s);
		ft_is_worth(s, -1);
		ft_list_clear_tab(&s->ways);
	}
	free(tab);
	return (1);
}
