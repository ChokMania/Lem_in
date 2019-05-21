/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 17:43:02 by mabouce           #+#    #+#             */
/*   Updated: 2019/05/21 14:54:27 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_print_ways(t_s *s, t_list *way)
{
	t_list *beg;
	int		j;

	j = 0;
	miniprintf("%%", "YELLOW");
	beg = way;
	while (beg)
	{
		while (j < s->totalroom)
		{
			if (beg->tab[j] == -5)
				ft_putstr("");
			else
				miniprintf("|%s|", s->namematrice[beg->tab[j]]);
			if (j + 1 != s->totalroom)
				ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		beg = beg->next;
	}
	miniprintf("%%", "END");
}

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
	while (++start < s->totalroom)
		if (s->matrice[s->st_pos][start] == 1 && start != s->st_pos)
			s->weight[start][0] = -1;
}

int			ft_algo(t_s *s)
{
	int *queue;
	int start;
	int k;
	int save;

	if (!(queue = (int*)malloc(sizeof(int) * s->totalroom)))
		ft_error(s, 6);
	ft_clean_tab(queue, s->totalroom);
	k = 0;
	while (++k <= s->matrice[s->st_pos][s->st_pos] && (save = -1))
	{
		start = ft_find_first(s, k) - 1;
		ft_make_start(s);
		while (++save < s->totalroom)
		{
			++start == s->totalroom ? start = 0 : 0;
			if (s->matrice[s->st_pos][start] == 1 && start != s->st_pos)
			{
				ft_bfs(s, start, queue);
				ft_clean_tab_tab(s->weight, s->totalroom, 1);
			}
		}
		ft_clean_tab_tab(s->weight, s->totalroom, 0);
		ft_is_worth(s, 0);
		ft_list_clear_tab(&s->ways);
	}
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