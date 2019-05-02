/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 11:51:01 by judumay           #+#    #+#             */
/*   Updated: 2019/05/02 14:55:08 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_move_ants(t_s *s, t_list *beg)
{
	int		i;

	i = s->k + 1;
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
			if (tab[s->j][1]-- > 0)
			{
				s->nbant--;
				number_ants = ++s->i;
				s->ants_in_way[s->j][0] = number_ants;
			}
			ft_move_ants(s, beg);
			beg = beg->next;
		}
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

int			ft_print_path_while_malloc(t_s *s, t_list *beg, int **tab)
{
	while (++s->i < s->maxway)
	{
		s->j = -1;
		if (!(s->ants_in_way[s->i] = (int*)malloc(sizeof(int) *
			s->totalroom)))
			return (-10);
		if (!(tab[s->i] = (int*)malloc(sizeof(int) * 3)))
			return (-11);
		while (++s->j < s->totalroom)
			s->ants_in_way[s->i][s->j] = -5;
		tab[s->i][0] = ft_lenint(beg->ttab[0], s);
		tab[s->i][1] = 0;
		beg = beg->next;
	}
	return (1);
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
		ft_error(s, -8);
	if (!(tab = (int**)malloc(sizeof(int*) * (s->maxway + 1))))
		ft_error(s, -9);
	if ((i = ft_print_path_while_malloc(s, beg, tab)) < 0)
		ft_error(s, i);
	i = s->i;
	ft_dispatch_ants(tab, s);
	!s->flag_n ? miniprintf("\n") : 0;
	ft_print_path_suite(s, number_ants, tab);
	return (1);
}
