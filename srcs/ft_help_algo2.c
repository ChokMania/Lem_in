/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help_algo2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 18:10:03 by judumay           #+#    #+#             */
/*   Updated: 2019/05/15 18:18:30 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_make_start(t_s *s)
{
	int	start;

	start = -1;
	while (++start < s->totalroom)
		if (s->matrice[s->st_pos][start] == 1 && start != s->st_pos)
			s->weight[start][0] = -1;
}

int		ft_choose_sous(t_s *s, int start, int *bloc)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (++i < s->totalroom)
	{
		if (i == bloc[j])
			j++;
		else if (s->matrice[s->st_pos][i] == 1 && i != s->st_pos
			&& i != start)
			break ;
	}
	return (i);
}

void	ft_push_or_not(t_s *s, int *queue, int i, int start)
{
	int l;

	l = -1;
	if (i >= 0 || i == -12)
	{
		i == -12 ? queue[++l] = start : 0;
		i == -12 ? i = -1 : 0;
		while (i != -1)
		{
			queue[++l] = i;
			i != s->end_pos ? s->weight[i][0] = s->bfs_first : 0;
			i = s->weight[i][1];
		}
		if (!(ft_ways_push_front_two(s, &s->ways, queue)))
			ft_error(s, -7);
		ft_clean_tab(queue, s->totalroom);
	}
}

void	ft_init_bfs(t_s *s, int tab[5], int *queue, int start)
{
	tab[0] = start;
	tab[1] = -1;
	tab[2] = 0;
	tab[4] = 0;
	s->weight[start][0] = 0;
	s->weight[start][1] = -1;
	queue[0] = start;
}

int		ft_first_bfs(t_s *s, int start, int *queue)
{
	int	tab[5];

	ft_init_bfs(s, tab, queue, start);
	while (++tab[1] < s->totalroom && (tab[3] = -1))
	{
		tab[0] = ft_parse_queue(queue);
		if ((start == s->end_pos && (tab[3] = -12)) || (tab[0] < 0))
			break ;
		while (++tab[3] < s->totalroom)
			if (s->matrice[tab[0]][tab[3]] == 1 && tab[0] != tab[3]
				&& s->weight[tab[3]][0] == -5 && tab[3] != s->st_pos
				&& (tab[4] = 1))
			{
				s->weight[tab[3]][0] = s->weight[tab[0]][0] + 1;
				s->weight[tab[3]][1] = tab[0];
				if (tab[3] == s->end_pos)
					break ;
				queue[++tab[2]] = tab[3];
			}
		if ((queue[tab[1]] = -1) && tab[3] == s->end_pos && tab[4] == 1)
			break ;
	}
	ft_clean_tab(queue, s->totalroom);
	tab[0] >= 0 ? ft_push_or_not(s, queue, tab[3], start) : 0;
	return (tab[0] >= 0 ? 1 : 0);
}
