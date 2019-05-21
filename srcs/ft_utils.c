/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 14:19:40 by judumay           #+#    #+#             */
/*   Updated: 2019/05/21 14:44:56 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			*ft_intdup(int *i1, int len)
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

t_list		*ft_sort_list(t_list *lst, t_s *s)
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
