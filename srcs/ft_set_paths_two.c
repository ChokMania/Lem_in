/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_paths_two.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 15:11:17 by mabouce           #+#    #+#             */
/*   Updated: 2019/05/07 19:10:15 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			ft_duplicate_ways_push_algo_two(t_s *s, t_list **save, t_list *current, int currentmove, int j)
{
	int		i;
	t_list	*new;

	if (!(ft_ways_push_front(s, save, j)))
		return (0);
	i = 0;
	new = *save;
	miniprintf("ici\n");
	while (i < s->totalroom)
	{
		new->ttab[0][i] = current->ttab[0][i];
		new->ttab[1][i] = current->ttab[1][i];
		new->ttab[2][i] = current->ttab[2][i];
		i++;
	}
	new->ttab[0][currentmove] = j;
	new->weight = current->weight;
	return (1);
}

int			ft_set_paths_two(t_s *s)
{
	int	i;
	int	j;
	int	ok;
	t_list *beg;
	t_list *current;
	t_list	*prev;
	t_list *save;

	current = NULL;

	i = 0;
	s->conflit = 0;
	s->tmpconflit = 0;
	while (i < s->totalroom)
	{
		if (s->matrice[s->start_pos][i] == 1 && i != s->start_pos)
		{
			if (!(ft_ways_push_front(s, &s->ways, i)))
				return (-9);
		}
		s->weight[i][0] = -5;
		i++;
	}
	beg = s->ways;
	while (beg)
	{
		ft_list_copy(s, &current, beg);
		current->finished = 0;
		save = current;
		i = 1;
		while (i < s->totalroom)
		{
			miniprintf("%%turn : %i%%\n", "YELLOW", i - 1, "END");
			current = save;
			miniprintf("%%list current size = %d. Current->finished : %i\n\n%%", "GREEN" ,ft_list_size(current), current->finished,"END");
			prev = save;
			while (current)
			{
				ok = 0;
				j = 0;
				while (j < s->totalroom)
				{
					if (current->ttab[0][i - 1] == s->end_pos)
					{
						current->finished = 1;
						if (!(ft_list_copy(s, &s->finalways, current)))
							return (-10);
						miniprintf("%%Arrived modafucka\n%%", "RED", "END");
						break;
					}
					else if (current->ttab[0][i - 1] > -5 && j != s->start_pos && s->matrice[current->ttab[0][i - 1]][j]
							== 1 && current->ttab[0][i - 1] != j && current->ttab[1][i] < 0
								&& (s->matrice[j][j] > 1 || j == s->end_pos))
					{
						if ((i < 2) || (i >= 2 && j != current->ttab[0][i - 2]))
						{
							if (ft_check_prev(current, i, j) == 1)
							{
								if (s->weight[j][0] > i || s->weight[j][0] == -5)
								{
									current->ttab[0][i] = j;
									current->ttab[1][i] = 1;
									s->weight[j][0] = i;
								}
							}
						}
					}
					else if (current->ttab[0][i - 1] > -5 && j != s->start_pos && s->matrice[current->ttab[0][i - 1]][j] == 1
							&& current->ttab[0][i - 1] != j && current->ttab[1][i] > 0
								&& (s->matrice[j][j] > 1 || j == s->end_pos))
					{
						if ((i < 2) || (i >= 2 && j != current->ttab[0][i - 2]))
						{
							if (ft_check_prev(current, i, j) == 1)
							{
								if (s->weight[j][0] > i || s->weight[j][0] == -5)
								{
									miniprintf("%%On duplique :)\n%%", "BLUE", "END");
									current->ttab[2][i - 1] = 1;
									s->weight[j][0] = i;
									if (!(ft_duplicate_ways_push_algo_two(s, &save, current, i, j)))
										return (0);
								}
							}
						}
					}
					j++;
				}
				if (current->finished == 1)
					break ;
				if (current->ttab[0][i] == -5)
				{
					miniprintf("%%REMOVING\n%%", "RED", "END");
					if (current == save && (ok = 1))
						prev = prev->next;
					ft_list_remove_middle_data_finalways(s, &save, current);
					current = prev;
				}
				prev = current;
				if (ok == 0)
					current = current->next;
			}
			if (current && current->finished == 1)
				break ;
			i++;
		}
		ft_list_clear_tab(&current);
		//ft_print_tab_tab_int(s->weight, s->totalroom, 1);
		//while (i < s->totalroom)
		//	s->weight[i++][0] = -5;
		miniprintf("out\n\n\n");
		beg = beg->next;
	}
	//ft_print_ways(s, s->finalways);
	//placer un taken sur toutes les salles de s->finalways;
	return (1);
}
	
	/*beg = s->ways;
	prev = s->ways;
	i = 1;
	while (i < 5)
	{
		beg = s->ways;
		prev = s->ways;
		while (beg)
		{
			beg->weight++;
			ok = 0;
			j = 0;
			while (j < s->totalroom && beg->finished == 0)
			{
				if (beg->ttab[0][i - 1] == s->end_pos)
				{
					s->maxway--;
					beg->finished = 1;
					if (!(ft_list_copy(s, &s->finalways, beg)))
						return (-10);
					return (0);
				}
				else if (beg->ttab[0][i - 1] > -5 && beg->finished == 0
					&& j != s->start_pos && s->matrice[beg->ttab[0][i - 1]][j]
						== 1 && beg->ttab[0][i - 1] != j && beg->ttab[1][i] < 0
							&& (s->matrice[j][j] > 1 || j == s->end_pos))
				{
					if ((i < 2) || (i >= 2 && j != beg->ttab[0][i - 2]))
					{
						if (ft_check_prev(beg, i, j) == 1)
						{
							beg->ttab[0][i] = j;
							beg->ttab[1][i] = 1;
						}
					}
				}
				else if (beg->ttab[0][i - 1] > -5 && beg->finished == 0 &&
					j != s->start_pos && s->matrice[beg->ttab[0][i - 1]][j] == 1
						&& beg->ttab[0][i - 1] != j && beg->ttab[1][i] > 0
							&& (s->matrice[j][j] > 1 || j == s->end_pos))
				{
					if ((i < 2) || (i >= 2 && j != beg->ttab[0][i - 2]))
					{
						if (ft_check_prev(beg, i, j) == 1)
						{
							beg->ttab[2][i - 1] = 1;
							if (!(ft_duplicate_ways_push(s, beg, i, j)))
								return (0);
						}
					}
				}
				j++;
			}
			if (beg->ttab[0][i] == -5)
			{
				if (beg == s->ways && (ok = 1))
					prev = prev->next;
				ft_list_remove_middle_data_finalways(s, &s->ways, beg);
				beg = prev;
			}
			prev = beg;
			if (ok == 0)
				beg = beg->next;
		}
		i++;
	}*/

int			ft_set_paths_start_two(t_s *s)
{
	int i;

	s->i = -1;
	if (!(s->tab = (int *)malloc(sizeof(int) * s->totalroom)))
		ft_error(s, -7);
	while (++s->i < s->totalroom)
		s->tab[s->i] = -5;
	i = -1;
	if (!(s->tb = (int *)malloc(sizeof(int) * s->totalroom)))
		ft_error(s, -8);
	while (++i < s->totalroom)
		s->tb[i] = -5;
	s->i = 0;
	s->maxway = ft_set_maxway(s);
	if ((s->ret = ft_set_paths_two(s)) < -1)
		ft_error(s, s->ret);
	//ft_print_ways(s, s->finalways);
	//ft_del_useless_list_elem(s);
	return (1);
}
