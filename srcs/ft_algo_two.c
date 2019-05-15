/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 15:22:06 by judumay           #+#    #+#             */
/*   Updated: 2019/05/15 18:15:20 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static	int		ft_last_element(t_s *s, int *bloc)
{
	int i;

	i = s->totalroom - 1;
	while (i >= 0)
	{
		if (bloc[i] != -5)
			break ;
		i--;
	}
	return (bloc[i]);
}

static	void	ft_second_bfs(t_s *s, int start, int *queue, int *bloc)
{
	int i;
	int k;
	int	j;

	i = -1;
	k = -1;
	j = ft_last_element(s, bloc);
	ft_make_start(s);
	ft_first_bfs(s, j, queue);
	while (++i < s->totalroom)
	{
		ft_make_start(s);
		ft_clean_tab_tab_token(s->weight, s->totalroom);
		if (s->matrice[s->st_pos][i] == 1 && i != s->st_pos && i != start
			&& i != j)
			ft_first_bfs(s, i, queue);
	}
}

static	void	ft_init(t_s *s, int *bloc, int *queue)
{
	int	i;

	i = -1;
	while (++i < s->totalroom)
	{
		bloc[i] = -5;
		queue[i] = -5;
	}
}

static	void	ft_algo_two_suite(t_s *s, int *bloc, int *queue, int start)
{
	int		sous_bl;

	while (ft_lenint(bloc, s) + 1 < s->matrice[s->st_pos][s->st_pos])
	{
		ft_clean_not_first(s->weight, s->totalroom);
		s->bfs_first = -2;
		sous_bl = ft_choose_sous(s, start, bloc);
		bloc[ft_lenint(bloc, s)] = sous_bl;
		ft_second_bfs(s, start, queue, bloc);
		ft_is_worth(s, -1);
		s->ret ? ft_clear_tab_f(&s->ways) : ft_list_clear_tab(&s->ways);
	}
}

int				ft_algo_two(t_s *s)
{
	int		*queue;
	int		*bloc;
	int		start;

	if (!(queue = (int *)malloc(sizeof(int) * s->totalroom * s->totalroom)))
		ft_error(s, -6);
	if (!(bloc = (int *)malloc(sizeof(int) * s->totalroom * s->totalroom)))
		ft_error(s, -6);
	ft_init(s, bloc, queue);
	ft_clean_tab(bloc, s->totalroom);
	ft_list_clear_tab(&s->ways);
	ft_make_start(s);
	start = ft_choose_the_one(1, s);
	s->ret = ft_first_bfs(s, start, queue);
	ft_is_worth(s, -1);
	ft_algo_two_suite(s, bloc, queue, start);
	ft_clean_tab_tab(s->weight, s->totalroom);
	ft_list_clear_tab(&s->ways);
	free(queue);
	free(bloc);
	return (1);
}
