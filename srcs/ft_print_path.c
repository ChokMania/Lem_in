/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 11:51:01 by judumay           #+#    #+#             */
/*   Updated: 2019/04/30 17:31:25 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_lenint(int *tab, t_s *s)
{
	int		i;

	i = 0;
	while (tab[i] != -5 && i != s->totalroom)
		i++;
	return (i);
}


int			ft_color(t_s *s)
{
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

void		ft_move_ants(t_s *s, int ants, t_list *beg)
{
	int		i;

	i = s->k;
	while (--i >= 0)
	{
		if (s->ants_in_way[s->j][i] >= 0)
		{
			if (i == s->k)
				s->ants_in_way[s->j][i] = -5;
			else
			{
				s->flag_c ? miniprintf("%s", s->color[s->j]) : 0;
				miniprintf("L%d-%s", s->ants_in_way[s->j][i],
					s->namematrice[beg->ttab[0][i]]);
				miniprintf(" ");
				s->flag_c ? miniprintf("\x1b[0m") : 0;
				s->ants_in_way[s->j][i + 1] = s->ants_in_way[s->j][i];
				s->ants_in_way[s->j][i] = -5;
				s->p++;
			}
		}
	}
}

void		ft_print_path_suite(t_s *s, int number_ants, int **tab)
{
	t_list	*beg;

	s->i = 0;
	s->p = 1;
	while (s->p)
	{
		s->p = 0;
		s->i == 0 ? s->p = 1 : 0;
		s->j = -1;
		beg = s->finalways;
		while (beg)
		{
			s->j++;
			s->k = ft_lenint(beg->ttab[0], s);
			number_ants = number_ants < s->nbant
				&& number_ants > -1 ? number_ants + 1 : -1;
			if (tab[s->j][1]-- > 0)
				s->ants_in_way[s->j][0] = number_ants;
			ft_move_ants(s, number_ants, beg);
			beg = beg->next;
		}
		s->i++;
		s->p ? ft_putchar('\n') : 0;
	}
}

void		ft_dispatch_ants(int **tab, t_s *s)
{
	int		ants;
	int		i;
	int		max;

	max = 0;
	ants = s->nbant;
	while (++max < s->maxway && (i = -1))
		while (++i < max)
			while (tab[i][0] + tab[i][1] != tab[max][0] + tab[max][1])
			{
				tab[i][1]++;
				ants--;
			}
	while (ants && (i = -1))
		while (++i < max)
		{
			if (ants == 0)
				break ;
			ants--;
			tab[i][1]++;
		}
}

int			ft_print_path(t_s *s)
{
	int		number_ants;
	int		**tab;
	t_list	*beg;
	int		i;

	beg = s->finalways;
	s->maxway = ft_list_size(s->finalways);
	number_ants = 0;
	if (!ft_color(s))
		ft_error(s, -8);
	s->i = -1;
	s->k = s->maxway;
	if (!(s->ants_in_way = (int**)malloc(sizeof(int*) * (s->maxway + 1))))
		;//ft_error(s, -9);
	if (!(tab = (int**)malloc(sizeof(int*) * (s->maxway + 1))))
		;//ft_error(s, -9);
	while (++s->i < s->maxway)
	{
		s->j = -1;
		if (!(s->ants_in_way[s->i] = (int*)malloc(sizeof(int) *
			s->totalroom)))
			;//ft_error(s, -9);
		/**/if (!(tab[--s->k] = (int*)malloc(sizeof(int) * 3)))
			;//ft_error(s, -9);
		while (++s->j < s->totalroom)
			s->ants_in_way[s->i][s->j] = -5;
		/**/tab[s->k][0] = ft_lenint(beg->ttab[0], s);
		/**/tab[s->k][1] = 0;
		beg = beg->next;
	}
	i = s->i;
	ft_dispatch_ants(tab, s);
	ft_print_path_suite(s, number_ants, tab);
	return (1);
}
