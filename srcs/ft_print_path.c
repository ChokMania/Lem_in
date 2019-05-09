/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 11:51:01 by judumay           #+#    #+#             */
/*   Updated: 2019/05/09 08:42:48 by judumay          ###   ########.fr       */
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
				s->flag_c ? miniprintf("%s", s->color[s->j % 7]) : 0;
				miniprintf("L%d-%s", s->ants_in_way[s->j][i],
					s->namematrice[beg->ttab[0][i]]);
				miniprintf(" "); //espace en trop;
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
	while (ants && ++max < s->maxway && (i = -1))
		while (ants && ++i < max)
			while (ants && tab[i][0] + tab[i][1] != tab[max][0] + tab[max][1])
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
	i = -1;
	while (++i < s->maxway)
		tab[i][1] > 0 ? tab[i][2] = 1 : 0;
}

int			ft_print_path_while_malloc(t_s *s, t_list *beg, int **tab)
{
	while (++s->i < s->maxway)
	{
		s->j = -1;
		if (!(s->ants_in_way[s->i] = (int*)malloc(sizeof(int) *
			s->totalroom)))
			return (-9);
		if (!(tab[s->i] = (int*)malloc(sizeof(int) * 3)))
			return (-9);
		while (++s->j < s->totalroom)
			s->ants_in_way[s->i][s->j] = -5;
		tab[s->i][0] = ft_lenint(beg->ttab[0], s);
		tab[s->i][1] = 0;
		beg = beg->next;
	}
	ft_dispatch_ants(tab, s);
	!s->flag_n ? miniprintf("\n") : 0;
	if (!ft_color(s))
		ft_error(s, -10);
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
	s->i = -1;
	s->k = s->maxway;
	if (!(s->ants_in_way = (int**)malloc(sizeof(int*) * (s->maxway))))
		ft_error(s, -9);
	if (!(tab = (int**)malloc(sizeof(int*) * (s->maxway))))
	{
		ft_inttabdel(&tab, s->maxway);
		ft_error(s, -9);
	}
	if ((i = ft_print_path_while_malloc(s, beg, tab)) < 0)
	{
		ft_inttabdel(&tab, s->maxway);
		ft_error(s, -9);
	}
	ft_print_path_suite(s, number_ants, tab);
	ft_inttabdel(&tab, s->maxway);
	return (1);
}
