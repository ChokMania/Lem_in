/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_paths.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 15:11:17 by mabouce           #+#    #+#             */
/*   Updated: 2019/04/30 18:40:14 by mabouce          ###   ########.fr       */
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

int		ft_way_is_in_conflict(t_s *s, t_list *first, t_list *second)
{
	int i;
	int	j;

	i = 0;
	while (i < s->totalroom)
	{
		if (first->ttab[0][i] < 0)
			return (0);
		j = 0;
		while (j < s->totalroom)
		{
			if (second->ttab[0][j] < 0)
				return (0);
			else if (second->ttab[0][j] == first->ttab[0][i])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int		ft_way_have_no_conflict(t_s *s, t_list *current)
{
	int i;

	i = 0;
	while (i < s->totalroom)
	{
		if (current->ttab[2][i] > 0)
			return (0);
		i++;
	}
	return (1);
}

int		ft_lenint(int *tab, t_s *s)
{
	int		i;

	i = 0;
	while (tab[i] != -5 && i != s->totalroom)
		i++;
	return (i);
}


long long	ft_calc_nb_room_by_ways(t_s *s, int *tab, int maxway)
{
	int			i;
	int			j;
	long long 	count;
	t_list		*beg;

	i = 0;
	count = 0;
	beg = s->finalways;
	while (i < maxway)
	{
		j = 0;
		while (j < tab[i])
		{
			j++;
			beg = beg->next;
		}
		count += ft_lenint(beg->ttab[0], s);
		i++;
	}
	return (count);
}

long long	ft_best_ways_found_recursiv(t_s *s, int maxway, t_list *current)
{
	t_list *first;
	int i;
	int j;

	if (!(current->tab = (int *)malloc(sizeof(int) * s->totalroom)))
		return (0);
	ft_memset((void *)(current->tab), -5, s->totalroom);
	maxway = ft_set_maxway(s);
	i = 0;
	j = 0;
	first = s->finalways;
	while (first && maxway > 0)
	{
		if (!ft_way_is_in_conflict(s, first, current))
		{
			current->tab[i] = j;
			maxway--;	
			i++;
		}
		j++;
		first = first->next;
	}
	if (maxway > 0)
	{
		//need to free current->tab
		return (0);
	}
	return (ft_calc_nb_room_by_ways(s, current->tab, maxway));
}

int		ft_best_ways_found(t_s *s)
{
	t_list *current;
	long long	maxway;
	long long   bestresult;
	long long   currentresult;

	maxway = ft_set_maxway(s);
	current = s->finalways;
	bestresult = 0;
	currentresult = 0;
	while (current)
	{
		if ((currentresult = ft_best_ways_found_recursiv(s, maxway, current)))
			if (bestresult == 0 || bestresult > currentresult)
				bestresult = currentresult;
		current = current->next;
	}
	return (1);
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
		}
		i++;
	}
	//miniprintf("%%start paths = %i\n\n%%", "RED", ft_list_size(s->ways), "END");
	//miniprintf("%%%%Print first ways :\n\n%%%%", "BOLD", "UNDER", "END", "GREEN");
	beg = s->ways;
	/*	while (beg)
		{
		miniprintf("ant name : %i\n", beg->i);
		ft_print_tab_tab_int_tmp(s, beg->ttab, 3, s->totalroom);
		miniprintf("\n");
		beg = beg->next;
		}
		miniprintf("%%", "END");*/
	i = 1;
	while (i < s->totalroom)
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
					if (s->maxway <= 0)
					{
						if (ft_best_ways_found(s))
							return (1);
					}
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
	return (1);
}

long long	ft_set_maxway(t_s *s)
{
	long long i;

	i = 0;
	i = s->matrice[s->start_pos][s->start_pos];
	i = i < s->nbant ? i : s->nbant;
	i = i < s->matrice[s->end_pos][s->end_pos]
		? i : s->matrice[s->end_pos][s->end_pos];
	return (i);
}

int			ft_set_paths_start(t_s *s)
{
	s->i = 0;
	s->totalplays = s->totalroom * s->nbant;
	s->maxway = ft_set_maxway(s);
	ft_set_paths(s);
	ft_print_ways(s);
	return (1);
}
