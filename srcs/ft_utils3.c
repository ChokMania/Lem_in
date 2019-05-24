/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 17:43:02 by judumay           #+#    #+#             */
/*   Updated: 2019/05/24 14:38:40 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	ft_find_first(t_s *s, int k)
{
	int i;

	i = -1;
	while (k > 0)
	{
		i++;
		if (s->matrice[s->st_pos][i] == 1)
			k--;
	}
	return (i);
}

static void	ft_make_start(t_s *s)
{
	int	start;

	start = -1;
	while (++start < s->ttroom)
		if (s->matrice[s->st_pos][start] == 1 && start != s->st_pos)
			s->weight[start][0] = -1;
}

static int	ft_algo_while(t_s *s, int tab[2], int *queue)
{
	int start;

	start = ft_find_first(s, tab[0]) - 1;
	ft_make_start(s);
	while (++tab[1] < s->ttroom)
	{
		++start == s->ttroom ? start = 0 : 0;
		if (start == s->end_pos && s->matrice[s->st_pos][start] == 1
			&& start != s->st_pos)
		{
			ft_push_or_not(s, queue, -4, start);
			ft_is_worth(s, 0);
			ft_list_clear_tab(&s->ways);
			return (1);
		}
		else if (s->matrice[s->st_pos][start] == 1 && start != s->st_pos)
		{
			ft_bfs(s, start, queue);
			ft_clean_tab_tab(s->weight, s->ttroom, 1);
		}
	}
	ft_clean_tab_tab(s->weight, s->ttroom, 0);
	ft_is_worth(s, 0);
	ft_list_clear_tab(&s->ways);
	return (0);
}

int			ft_algo(t_s *s)
{
	int	*queue;
	int	tab[2];

	if (!(queue = (int*)malloc(sizeof(int) * s->ttroom)))
		ft_error(s, -8);
	ft_clean_tab(queue, s->ttroom);
	tab[0] = 0;
	while (++tab[0] <= s->matrice[s->st_pos][s->st_pos] && (tab[1] = -1))
		if (ft_algo_while(s, tab, queue) > 0)
			break ;
	free(queue);
	return (1);
}

int			ft_set_maxway(t_s *s)
{
	int i;

	i = 0;
	i = s->matrice[s->st_pos][s->st_pos];
	i = i < s->nbant ? i : s->nbant;
	i = i < s->matrice[s->end_pos][s->end_pos]
		? i : s->matrice[s->end_pos][s->end_pos];
	return (i);
}
