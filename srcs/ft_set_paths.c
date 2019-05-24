/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_paths.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 15:11:17 by judumay           #+#    #+#             */
/*   Updated: 2019/05/24 14:35:04 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** tab[0] = i
** tab[1] = k
** tab[2] = in
** tab[3] = count
** ligne 66; 0 == conflit;
*/

static int	ft_bfs_suite(t_s *s, int start, int *queue, int tab[4])
{
	int j;

	while (++tab[3] < s->ttroom && (j = -1))
	{
		tab[0] = ft_parse_queue(queue);
		if ((start == s->end_pos && (j = -4)) || tab[0] < 0)
			break ;
		while (++j < s->ttroom)
			if (s->matrice[tab[0]][j] == 1 && tab[0] != j && j != s->st_pos)
			{
				s->weight[j][2] = ft_conflict(s, j);
				if (s->weight[j][0] == -5 && (tab[2] = 1))
				{
					s->weight[j][0] = s->weight[tab[0]][0] + 1;
					s->weight[j][1] = tab[0];
					if (j == s->end_pos)
						break ;
					queue[++tab[1]] = j;
				}
			}
		if ((queue[tab[3]] = -1) && j == s->end_pos && tab[2] == 1)
			break ;
	}
	return (j);
}

int			ft_bfs(t_s *s, int start, int *queue)
{
	int	j;
	int	tab[4];

	tab[3] = -1;
	tab[1] = 0;
	tab[2] = 0;
	s->weight[start][0] = 0;
	s->weight[start][1] = -1;
	queue[0] = start;
	s->i = 0;
	s->weight[start][2] = ft_conflict(s, start);
	j = ft_bfs_suite(s, start, queue, tab);
	ft_clean_tab(queue, s->ttroom);
	tab[0] < 0 && j != -4 ? 0 : ft_push_or_not(s, queue, j, start);
	ft_sort_list(s->ways, s, queue, s->tmp);
	return (1);
}

int			ft_set_paths_start(t_s *s)
{
	s->maxway = ft_set_maxway(s);
	ft_algo(s);
	ft_sort_list(s->finalways, s, NULL, s->tmp);
	s->k = 0;
	return (1);
}
