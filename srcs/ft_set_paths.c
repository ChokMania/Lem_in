/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_paths.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 15:11:17 by mabouce           #+#    #+#             */
/*   Updated: 2019/04/29 19:28:31 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			ft_total_weight(t_s *s, int weight)
{
	int		totalway;
	int		totalweight;
	t_list	*beg;

	totalway = 0;
	totalweight = 0;
	beg = s->ways;
	while (beg)
	{
		totalway++;
		totalweight += beg->weight - 1;
		beg = beg->next;
	}
	return ((s->nbant + totalweight + weight - 1) / (totalway + 1));
}

int		ft_duplicate_ways_push(t_s *s, t_list *beg, int currentmove, int j)
{
	int i;
	t_list *new;

	if (!(ft_ways_push_front(s, &s->ways, j)))
		return (0);
	i = 0;
	new = s->ways;
	while (i < s->totalroom)
	{
		new->ttab[0][i] = beg->ttab[0][i];
		new->ttab[1][i] = beg->ttab[1][i];
		new->ttab[2][i] = beg->ttab[2][i];
		i++;
	}
	new->i = s->i++;
	new->ttab[0][currentmove] = j;
	return (1);
}

void	ft_print_tab_tab_int_tmp(t_s *s, int **tab, int len, int size)
{
	long long i;
	long long j;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < size)
		{
			if (tab[i][j] == -5)
				ft_putstr(".");
			else if (i == 0)
				miniprintf("%.2s", s->namematrice[tab[i][j]]);
			else
				ft_putnbr(tab[i][j]);
			if (j + 1 != size)
				ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}


int		ft_best_ways_found(t_s *s)
{

}

void	ft_print_ways(t_s *s)
{
	t_list *beg;

	miniprintf("%%%%Print after algo :\n\n%%%%", "BOLD", "UNDER", "END", "YELLOW");
	beg = s->finalways;
	while (beg)
	{
		miniprintf("ant name : %i\n\n", beg->i);
		ft_print_tab_tab_int_tmp(s, beg->ttab, 3, s->totalroom);
		miniprintf("\n");
		beg = beg->next;
	}
	miniprintf("%%", "END");
}

int		ft_set_paths(t_s *s)
{
	int i;
	int j;
	t_list *beg;

	i = 0;
	while (i < s->totalroom)
	{
		if (s->matrice[s->start_pos][i] == 1 && i != s->start_pos)
		{
			ft_ways_push_front(s, &s->ways, i);
			s->i++;
		}
		i++;
	}
	miniprintf("%%start paths = %i\n\n%%", "RED", ft_list_size(s->ways), "END");
	miniprintf("%%%%Print first ways :\n\n%%%%", "BOLD", "UNDER", "END", "GREEN");
	beg = s->ways;
	while (beg)
	{
		miniprintf("ant name : %i\n", beg->i);
		ft_print_tab_tab_int_tmp(s, beg->ttab, 3, s->totalroom);
		miniprintf("\n");
		beg = beg->next;
	}
	miniprintf("%%", "END");
	i = 1;
	while (i < s->totalroom && s->maxway > -2)
	{
		beg = s->ways;
		while (beg)
		{
			j = 0;
			while (j < s->totalroom && beg->finished == 0)
			{
				if (beg->ttab[0][i - 1] == s->end_pos)
				{
					miniprintf("chemins gagnants : %d\t", beg->i);
					s->maxway--;
					beg->finished = 1;
					ft_list_copy(s, &s->finalways, beg);
				}
				else if (beg->ttab[0][i - 1] > -5 && beg->finished == 0 && j != s->start_pos && s->matrice[beg->ttab[0][i - 1]][j] == 1 && beg->ttab[0][i -1] != j && beg->ttab[1][i] < 0)
				{
					if ((i < 2) || (i >= 2 && j != beg->ttab[0][i - 2]))
					{
						beg->ttab[0][i] = j;
						beg->ttab[1][i] = 1;
					}
				}
				else if (beg->ttab[0][i - 1] > -5 && beg->finished == 0 && j != s->start_pos && s->matrice[beg->ttab[0][i - 1]][j] == 1 && beg->ttab[0][i -1] != j && beg->ttab[1][i] > 0)
				{
					if ((i < 2) || (i >= 2 && j != beg->ttab[0][i - 2]))
					{
						beg->ttab[2][i - 1] = 1;
						if (!(ft_duplicate_ways_push(s, beg, i, j)))
							return (0);
					}
				}
				j++;
			}
			beg = beg->next;
		}
		i++;
	}
	ft_print_ways(s);

	return (1);
}

void		ft_set_maxway(t_s *s)
{
	s->maxway = s->matrice[s->start_pos][s->start_pos];
	s->maxway = s->maxway < s->nbant ? s->maxway : s->nbant;
	s->maxway = s->maxway < s->matrice[s->end_pos][s->end_pos]
		? s->maxway : s->matrice[s->end_pos][s->end_pos];
}

int			ft_set_paths_start(t_s *s)
{
	s->i = 0;
	s->totalplays = s->totalroom * s->nbant;
	ft_set_maxway(s);
	ft_set_paths(s);
	return (1);
}
