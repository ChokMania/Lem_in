/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 11:51:01 by judumay           #+#    #+#             */
/*   Updated: 2019/05/24 12:14:44 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				ft_color(t_s *s)
{
	s->color = NULL;
	if (!(s->color = (char**)malloc(sizeof(char*) * 8)))
		return (0);
	s->color[0] = ft_strdup("\x1b[31m");
	s->color[1] = ft_strdup("\x1b[32m");
	s->color[2] = ft_strdup("\x1b[33m");
	s->color[3] = ft_strdup("\x1b[34m");
	s->color[4] = ft_strdup("\x1b[35m");
	s->color[5] = ft_strdup("\x1b[36m");
	s->color[6] = ft_strdup("\x1b[37m");
	s->color[7] = NULL;
	return (1);
}

static void		ft_dispatch_ants(int **tab, t_s *s)
{
	int		ants;
	int		i;
	int		max;

	max = 0;
	i = -1;
	ants = s->nbant;
	while (ants > 0 && ++max < s->maxway)
	{
		while (ants > 0 && tab[max - 1][1] + tab[max - 1][0]
			< tab[max][1] + tab[max][0])
		{
			i = -1;
			while (ants > 0 && ++i < max && ants--)
				tab[i][1]++;
		}
	}
	i = -1;
	while (ants > 0)
	{
		if (++i == s->maxway)
			i = 0;
		ants--;
		tab[i][1] += 1;
	}
}

static int		ft_print_path_while_malloc(t_s *s, t_list *beg, int **tab)
{
	while (++s->i < s->maxway)
	{
		s->j = -1;
		if (!(s->ants_in_way[s->i] = (int*)malloc(sizeof(int) * s->ttroom)))
			return (-11);
		if (!(tab[s->i] = (int*)malloc(sizeof(int) * 3)))
			return (-11);
		while (++s->j < s->ttroom)
			s->ants_in_way[s->i][s->j] = -5;
		tab[s->i][0] = ft_li(beg->tab, s);
		tab[s->i][1] = 0;
		beg = beg->next;
	}
	ft_dispatch_ants(tab, s);
	!s->flag_n ? miniprintf("\n") : 0;
	if (!ft_color(s))
	{
		ft_inttabdel(&tab, s->maxway);
		ft_error(s, -11);
	}
	return (1);
}

int				ft_print_path(t_s *s)
{
	int		number_ants;
	int		**tab;
	t_list	*beg;
	int		i;

	beg = s->finalways;
	s->maxway = ft_list_size(s->finalways);
	number_ants = 0;
	s->i = -1;
	s->k = s->maxway;
	if (!(s->ants_in_way = (int**)malloc(sizeof(int*) * (s->maxway))))
		ft_error(s, -10);
	if (!(tab = (int**)malloc(sizeof(int*) * (s->maxway))))
	{
		free(s->ants_in_way);
		ft_error(s, -10);
	}
	if ((i = ft_print_path_while_malloc(s, beg, tab)) < 0)
	{
		ft_inttabdel(&tab, s->maxway);
		ft_error(s, -11);
	}
	ft_print_path_suite(s, number_ants, tab);
	ft_inttabdel(&tab, s->maxway);
	return (1);
}
