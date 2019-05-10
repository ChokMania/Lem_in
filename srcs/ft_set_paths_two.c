/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_paths_two.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 15:11:17 by mabouce           #+#    #+#             */
/*   Updated: 2019/05/10 13:34:45 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			ft_parse_queue(int *tab)
{
	int i;

	i = -1;
	while (tab[++i] != -5)
	{
		if (tab[i] >= 0)
			break ;
	}
	if (tab[i] < 0)
		return (-4);
	return (tab[i]);
}

void	ft_reset_weight(t_s *s)
{
	int	i;

	i = -1;
	while (++i < s->totalroom)
	{
		s->weight[i][0] = -5;
		s->weight[i][1] = -5;
	}
}

int		ft_choose_the_one(int u, t_s *s)
{
	int i;

	i = 0;
	while (u > 0)
	{
		if (s->matrice[s->st_pos][i] == 1 && i != s->st_pos)
			u--;
		i++;
	}
	return (i);
}

void		ft_reverse_final(t_s *s)
{
	t_list	*beg;
	int		t;
	int		i;
	int		j;

	beg = s->finalways;
	while (beg)
	{
		i = 0;
		j = ft_lenint(beg->tab, s) - 1;
		while (i < j)
		{
			t = beg->tab[j];
			beg->tab[j] = beg->tab[i];
			beg->tab[i] = t;
			j--;
			i++;
		}
		beg = beg->next;
	}
}

void		ft_is_worth(t_s *s)
{
	int		i;
	int		total;
	t_list	*beg;

	i = -1;
	beg = s->ways;
	total = 0;
	while (beg && (i = 0))
	{
		while (beg->tab[i] != -5 && i < s->totalroom)
			i++;
		total += i - 1;
		beg = beg->next;
	}
	beg = s->ways;
	if ((!ft_list_size(s->finalways) || (s->nbant + total)
		/ ft_list_size(s->finalways) > (s->nbant + s->max_weight)
		/ ft_list_size(s->ways)))
	{
		s->finalways ? ft_list_clear(&s->finalways) : 0;
		s->max_weight = total;
		while (beg)
		{
			ft_ways_push_front_two(s, &s->finalways, beg->tab);
			beg = beg->next;
		}
	}
}

int			ft_algo_two(t_s *s)
{
	int *tab;
	int i_q;
	int beg;
	int	i;
	int	j;
	int k;
	int u;
	int	save;
	int totalroom;

	if (!(tab = (int *)malloc(sizeof(int) * s->totalroom * s->totalroom)))
		return (0);
	u = 0;
	while (++u <= s->matrice[s->st_pos][s->st_pos])
	{
		save = -1;
		k = ft_choose_the_one(u , s);
		while (++save < s->totalroom)
		{
			k++;
			if (k == s->totalroom)
				k = 0;
			if (s->matrice[s->st_pos][k] == 1 && k != s->st_pos)
			{
				i_q = -1;
				while (++i_q < s->totalroom)
					tab[i_q] = -5;
				totalroom = -1;
				i_q = 0;
				beg = k;
				j = -1;
				s->weight[beg][0] = 0;
				s->weight[beg][1] = -5;
				tab[0] = beg;
				i = beg;
				while (j != s->end_pos && ++totalroom < s->totalroom)
				{
					j = -1;
					if (i == s->end_pos)
					{
						j = i;
						tab[++i_q] = j;
						break ;
					}
					i = ft_parse_queue(tab);
					if (i < 0)
						continue;
					while (++j < s->totalroom)
					{
						if (s->matrice[i][j] == 1 && i != j && s->weight[j][0] == -5 && j != s->st_pos)
						{
							s->weight[j][0] = s->weight[i][0] + 1;
							s->weight[j][1] = i;
							if (j == s->end_pos)
							{
								break ;
							}
							tab[++i_q] = j;
						}
					}
					tab[totalroom] = -1;
				}
				while (i_q > 0)
					tab[i_q--] = -5;
				if (i >= 0)
				{
					while (1)
					{
						if (j == -5)
							break ;
						tab[i_q++] = j;
						j != s->end_pos ? s->weight[j][0] = -1 : 0;
						j = s->weight[j][1];
					}
				}
				if (i >= 0)
					if (!(ft_ways_push_front_two(s, &s->ways, tab)))
						return (0);
				j = -1;
				while (++j < s->totalroom)
				{
					if (s->weight[j][0] != -1)
					{
						s->weight[j][0] = -5;
						s->weight[j][1] = -5;
					}
				}
			}
		}
		ft_reset_weight(s);
		ft_is_worth(s);
		ft_list_clear(&s->ways);
	}
	return (1);
}

int		*ft_intdup(int *i1, int len)
{
	int		*i2;
	int		i;

	i = 0;
	if (!(i2 = (int *)ft_memalloc(sizeof(int) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		i2[i] = i1[i];
		i++;
	}
	return (i2);
}

static void		list_swap(t_list *l1, t_list *l2, t_s *s)
{
	int		*overflow;

	overflow = ft_intdup(l1->tab, s->totalroom);
	l1->tab = ft_intdup(l2->tab, s->totalroom);
	l2->tab = ft_intdup(overflow, s->totalroom);
}

t_list			*ft_sort_list(t_list *lst, t_s *s)
{
	t_list			*tmp;

	tmp = lst;
	while (lst != NULL && lst->next != NULL)
	{
		if (ft_lenint(lst->tab, s) > ft_lenint(lst->next->tab, s))
		{
			list_swap(lst, lst->next, s);
			lst = tmp;
		}
		else
			lst = lst->next;
	}
	return (tmp);
}

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
	ft_algo_two(s);
	ft_reverse_final(s);
	ft_sort_list(s->finalways, s);
	return (1);
}
