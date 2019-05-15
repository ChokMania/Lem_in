/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 15:22:06 by judumay           #+#    #+#             */
/*   Updated: 2019/05/15 15:57:49 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static	void	ft_list_clear_tab_not_first(t_list **begin_list)
{
	t_list *save;

	save = *begin_list;
	while ((*begin_list)->next)
	{
		save = (*begin_list);
		(*begin_list) = (*begin_list)->next;
		if (save->ttab)
			ft_inttabdel(&save->ttab, 3);
		if (save->tab)
			free(save->tab);
		free(save);
	}
}

static	void	ft_clean_not_first(int **tab, int len1)
{
	int	i;
	int j;

	i = -1;
	j = -1;
	while (++i < len1)
	{
		if (tab[i][0] != -1)
			tab[i][0] = -5;
		tab[i][1] = -5;
	}
}

static	void	ft_clean_tab_tab_token(int **tab, int len1)
{
	int	i;
	int j;

	i = -1;
	j = -1;
	while (++i < len1)
	{
		if (tab[i][0] != -1 && tab[i][0] != -2)
			tab[i][0] = -5;
		tab[i][1] = -5;
	}
}

static	void	ft_clean_tab(int *tab, int len)
{
	int	i;

	i = -1;
	while (++i < len)
		tab[i] = -5;
}

static	void	ft_clean_tab_tab(int **tab, int len1)
{
	int	i;
	int j;

	i = -1;
	j = -1;
	while (++i < len1)
	{
		tab[i][0] = -5;
		tab[i][1] = -5;
	}
}

static	int		ft_choose_sous(t_s *s, int start, int *bloc)
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

static	void	ft_push_or_not(t_s *s, int *queue, int i, int start)
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

static	int	ft_first_bfs(t_s *s, int start, int *queue)
{
	int i;
	int j;
	int	k;
	int	l;
	int	in;

	i = start;
	k = -1;
	l = 0;
	in = 0;
	s->weight[start][0] = 0;
	s->weight[start][1] = -1;
	queue[0] = start;
	while (++k < s->totalroom)
	{
		i = ft_parse_queue(queue);
		if (start == s->end_pos)
		{
			j = -12;
			break ;
		}
		j = -1;
		if (i < 0)
			break ;
		while (++j < s->totalroom)
		{
			if (s->matrice[i][j] == 1 && i != j && s->weight[j][0] == -5
				&& j != s->st_pos)
			{
				in = 1;
				s->weight[j][0] = s->weight[i][0] + 1;
				s->weight[j][1] = i;
				if (j == s->end_pos)
					break ;
				queue[++l] = j;
			}
		}
		if (j == s->end_pos && in == 1)
			break ;
		queue[k] = -1;
	}
	ft_clean_tab(queue, s->totalroom);
	if (i >= 0)
	{
		ft_push_or_not(s, queue, j, start);
		return (1);
	}
	return (0);
}

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
	while (++k < s->totalroom)
		if (s->matrice[s->st_pos][k] == 1 && k != s->st_pos)
			s->weight[k][0] = -1;
	ft_first_bfs(s, j, queue);
	while (++i < s->totalroom)
	{
		k = -1;
		while (++k < s->totalroom)
			if (s->matrice[s->st_pos][k] == 1 && k != s->st_pos)
				s->weight[k][0] = -1;
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

int				ft_algo_two(t_s *s)
{
	int		*queue;
	int		*bloc;
	int		bloquage;
	int		sous_bloquage;
	int		start;

	if (!(queue = (int *)malloc(sizeof(int) * s->totalroom * s->totalroom)))
		ft_error(s, -6);
	if (!(bloc = (int *)malloc(sizeof(int) * s->totalroom * s->totalroom)))
		ft_error(s, -6);
	ft_init(s, bloc, queue);
	bloquage = 0;
	while (++bloquage <= s->matrice[s->st_pos][s->st_pos])
	{
		s->bfs_first = -1;
		ft_clean_tab(bloc, s->totalroom);
		ft_list_clear_tab(&s->ways);
		start = -1;
		while (++start < s->totalroom)
			if (s->matrice[s->st_pos][start] == 1 && start != s->st_pos)
				s->weight[start][0] = -1;
		start = ft_choose_the_one(bloquage, s);
		s->ret = ft_first_bfs(s, start, queue);
		ft_is_worth(s, -1);
		while (ft_lenint(bloc, s) + 1 < s->matrice[s->st_pos][s->st_pos])
		{
			ft_clean_not_first(s->weight, s->totalroom);
			s->bfs_first = -2;
			sous_bloquage = ft_choose_sous(s, start, bloc);
			bloc[ft_lenint(bloc, s)] = sous_bloquage;
			ft_second_bfs(s, start, queue, bloc);
			ft_is_worth(s, -1);
			s->ret ? ft_list_clear_tab_not_first(&s->ways): ft_list_clear_tab(&s->ways);
		}
		ft_clean_tab_tab(s->weight, s->totalroom);
		ft_list_clear_tab(&s->ways);
		break ;
	}
	free(queue);
	free(bloc);
	return (1);
}