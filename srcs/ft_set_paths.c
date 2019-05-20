/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_paths.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 15:11:17 by mabouce           #+#    #+#             */
/*   Updated: 2019/05/20 17:16:54 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		*ft_intdup(int *i1, int len)
{
	int		*i2;
	int		i;

	i = 0;
	if (!(i2 = (int *)malloc(sizeof(int) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		i2[i] = i1[i];
		i++;
	}
	return (i2);
}

t_list	*ft_sort_list(t_list *lst, t_s *s)
{
	t_list	*tmp;
	int		*t;

	tmp = lst;
	while (lst != NULL && lst->next != NULL && !(s->ret = 0))
		if (ft_lenint(lst->tab, s) > ft_lenint(lst->next->tab, s))
		{
			!(t = ft_intdup(lst->tab, s->totalroom)) ? ft_error(s, -8) : 0;
			free(lst->tab);
			!(lst->tab = ft_intdup(lst->next->tab, s->totalroom))
				? s->ret = -9 : 0;
			free(lst->next->tab);
			!s->ret && !(lst->next->tab = ft_intdup(t, s->totalroom))
				? s->ret = -9 : 0;
			if (s->ret == -9)
			{
				free(t);
				ft_error(s, -8);
			}
			free(t);
			lst = tmp;
		}
		else
			lst = lst->next;
	return (tmp);
}

void		ft_is_worth(t_s *s, int i)
{
	int		total;
	t_list	*beg;

	beg = s->ways;
	total = 0;
	while (beg && !(i = 0))
	{
		while (beg->tab[i] != -5 && i < s->totalroom)
			i++;
		total += i - 1;
		beg = beg->next;
	}
	if ((beg = s->ways) && (!ft_list_size(s->finalways)
		|| (float)(s->nbant + s->max_weight) / (float)ft_list_size(s->finalways)
		> (float)(s->nbant + total) / (float)ft_list_size(s->ways)))
	{
		s->finalways ? ft_list_clear_tab(&s->finalways) : 0;
		s->max_weight = total;
		while (beg)
		{
			if (!(ft_ways_push_front_two(s, &s->finalways, beg->tab)))
				ft_error(s, -8);
			beg = beg->next;
		}
	}
}

void	ft_print_tab_int_tmp(t_s *s, int *tab, int size)
{
	int j = 0;

	while (j < size)
	{
		if (tab[j] == -5)
			ft_putstr("");
		else
			miniprintf("%10s", s->namematrice[tab[j]]);
		if (j + 1 != size)
			ft_putchar(' ');
		j++;
	}
	ft_putchar('\n');
}

void	ft_print_ways(t_s *s, t_list *way)
{
	t_list *beg;

	miniprintf("%%", "YELLOW");
	beg = way;
	while (beg)
	{
		ft_print_tab_int_tmp(s, beg->tab, s->totalroom);
		beg = beg->next;
	}
	miniprintf("%%", "END");
}

t_list		*ft_create_elem_tab_way_two(t_s *s, int *tab)
{
	t_list	*new;
	int		i;

	i = -1;
	if (!(new = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	new->tab = NULL;
	if (!(new->tab = (int*)malloc(sizeof(int) * s->totalroom)))
	{
		free(new);
		return (NULL);
	}
	while (++i < s->totalroom)
		new->tab[i] = tab[i];
	new->ttab = NULL;
	new->next = NULL;
	return (new);
}

int			ft_ways_push_front_two(t_s *s, t_list **begin_list, int *tab)
{
	t_list	*tmp;

	if (*begin_list && begin_list)
	{
		if ((tmp = ft_create_elem_tab_way_two(s, tab)) == NULL)
			return (0);
		tmp->next = (*begin_list);
		(*begin_list) = tmp;
	}
	else
	{
		if (!((*begin_list) = ft_create_elem_tab_way_two(s, tab)))
			return (0);
	}
	return (1);
}

int		ft_parse_queue(int *tab)
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

static void	ft_clean_tab_tab(int **tab, int len, int check)
{
	int i;

	i = -1;
	if (check == 0)
		while (++i < len)
		{
			tab[i][0] = -5;
			tab[i][1] = -5;
			tab[i][2] = -5;
		}
	if (check == 1)
		while (++i < len)
		{
			if (tab[i][0] != -1)
				tab[i][0] = -5;
			tab[i][1] = -5;
			tab[i][2] = -5;
		}
}

static void	ft_clean_tab(int *tab, int len)
{
	int i;

	i = -1;
	while (++i < len)
		tab[i] = -5;
}
void	ft_push_or_not(t_s *s, int *queue, int i, int start)
{
	int l;

	ft_clean_tab(queue, s->totalroom);
	l = s->weight[s->end_pos][0];
	i == -4 ? queue[++l] = start : 0;
	i == -4 ? i = -1 : 0;
	while (i != -1)
	{
		queue[l--] = i;
		i != s->end_pos ? s->weight[i][0] = -1 : 0;
		i = s->weight[i][1];
	}
	if (!(ft_ways_push_front_two(s, &s->ways, queue)))
		ft_error(s, -7);
	ft_clean_tab(queue, s->totalroom);
}

static int ft_bfs(t_s *s, int start, int *queue)
{
	int i;
	int j;
	int k;
	int in;
	int count;
	int save;

	count = -1;
	k = 0;
	s->weight[start][0] = 0;
	s->weight[start][1] = -1;
	queue[0] = start;
	while (++count < s->totalroom)
	{
		j = -1;
		i = ft_parse_queue(queue);
		save = 0;
		if ((start == s->end_pos && (j = -4)) || i < 0)
			break ;
		while (++j < s->totalroom)
		{
			if (s->matrice[i][j] == 1 && i != j && s->weight[j][0] == -5
				&& j != s->st_pos)
			{
				if (save == 1)
					s->weight[i][2] = 1;
				save = 1;
				in = 1;
				s->weight[j][0] = s->weight[i][0] + 1;
				s->weight[j][1] = i;
				if (j == s->end_pos)
					break ;
				queue[++k] = j;
			}
		}
		queue[count] = -1;
		if (j == s->end_pos && in == 1)
			break ;
	}
	if (i < 0 && j != -4)
	{
		//miniprintf("Bloqué\n");
		return (0);//remonter les conflits
	}
	else
		ft_push_or_not(s, queue, j, start);//faire le truc
	return (1);
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

void	ft_make_start(t_s *s)
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
		ft_error(0, 0);//
	ft_clean_tab(queue, s->totalroom);
	k = 0;
	while (++k <= s->matrice[s->st_pos][s->st_pos])
	{
		save = -1;
		start = ft_find_first(s, k);
		ft_make_start(s);
		while (++save < s->totalroom)
		{
			if (start == s->totalroom)
				start = 0;
			if (s->matrice[s->st_pos][start] == 1 && start != s->st_pos)
			{
				ft_bfs(s, start, queue);
				ft_clean_tab_tab(s->weight, s->totalroom, 1);
			}
			start++;
		}
		ft_clean_tab_tab(s->weight, s->totalroom, 0);
	/*	miniprintf("AVANT : %d\n", k);
		ft_print_ways(s, s->ways);
		miniprintf("\n");
		ft_print_ways(s, s->finalways);
	*/	ft_is_worth(s, 0);
	/*	miniprintf("APRES : %d\n", k);
		ft_print_ways(s, s->finalways);
	*/	ft_list_clear_tab(&s->ways);
	}
	free(queue);
	return (1);
}

long long	ft_set_maxway(t_s *s)
{
	long long i;

	i = 0;
	i = s->matrice[s->st_pos][s->st_pos];
	i = i < s->nbant ? i : s->nbant;
	i = i < s->matrice[s->end_pos][s->end_pos]
		? i : s->matrice[s->end_pos][s->end_pos];
	return (i);
}

int			ft_set_paths_start(t_s *s)
{
	s->i = -1;
	s->maxway = ft_set_maxway(s);
	ft_algo(s);
	ft_sort_list(s->finalways, s);
	return (1);
}
