/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_paths.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 15:11:17 by mabouce           #+#    #+#             */
/*   Updated: 2019/05/22 14:38:34 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			ft_bfs(t_s *s, int start, int *queue)
{
	int i;
	int j;
	int k;
	int in;
	int count;

	count = -1;
	k = 0;
	s->weight[start][0] = 0;
	s->weight[start][1] = -1;
	queue[0] = start;
	s->i = 0;
	s->weight[start][2] = ft_conflict(s, start);
	while (++count < s->totalroom)
	{
		j = -1;
		i = ft_parse_queue(queue);
		if ((start == s->end_pos && (j = -4)) || i < 0)
			break ;
		while (++j < s->totalroom)
		{
			if (s->matrice[i][j] == 1 && i != j && j != s->st_pos)
			{
				s->weight[j][2] = ft_conflict(s, j);
				if (s->weight[j][0] == -5)
				{
					in = 1;
					s->weight[j][0] = s->weight[i][0] + 1;
					s->weight[j][1] = i;
					if (j == s->end_pos)
						break ;
					queue[++k] = j;
				}
			}
		}
		queue[count] = -1;
		if (j == s->end_pos && in == 1)
			break ;
	}
	ft_clean_tab(queue, s->totalroom);
	if (i < 0 && j != -4)
		;// REMONTER CONFLIT;
	else
		ft_push_or_not(s, queue, j, start);
	ft_sort_list(s->ways, s, queue, s->totalroom);
	return (1);
}

int			ft_set_paths_start(t_s *s)
{
	s->maxway = ft_set_maxway(s);
	ft_algo(s);
	ft_sort_list(s->finalways, s, NULL, s->totalroom);
	s->k = 0;
	return (1);
}
