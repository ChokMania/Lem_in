/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 15:11:32 by mabouce           #+#    #+#             */
/*   Updated: 2019/05/13 09:02:40 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			ft_help_create(t_s *s, int **tab, t_list *copy, int i)
{
	int		k;
	int		j;

	j = -1;
	while (++j < 3 && (k = -1))
	{
		if (!(tab[j] = (int *)malloc(sizeof(int) * s->totalroom)))
			return (0);
		while (++k < s->totalroom)
			tab[j][k] = (i == 1 ? copy->ttab[j][k] : -5);
	}
	return (1);
}

t_list		*ft_create_elem_tab_way(t_s *s, int i, int **tab)
{
	t_list	*new;

	new = NULL;
	if (!(new = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	new->tab = NULL;
	new->ttab = NULL;
	if (!(tab = (int **)malloc(sizeof(int *) * (3))))
	{
		free(new);
		return (NULL);
	}
	if (!ft_help_create(s, tab, NULL, 0))
	{
		ft_inttabdel(&tab, s->totalroom);
		new->ttab = NULL;
		return (NULL);
	}
	tab[0][0] = i;
	tab[1][0] = 1;
	new->finished = 0;
	new->next = NULL;
	new->i = s->i++;
	new->ttab = tab;
	return (new);
}

t_list		*ft_create_elem_tab_final_way(t_s *s, t_list *copy, int **tab)
{
	t_list	*new;

	if (!(new = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	new->tab = NULL;
	new->ttab = NULL;
	if (!(tab = (int **)malloc(sizeof(int *) * (3))))
	{
		free(new);
		return (NULL);
	}
	if (!ft_help_create(s, tab, copy, 1))
	{
		ft_inttabdel(&tab, s->totalroom);
		new->ttab = NULL;
		return (NULL);
	}
	new->finished = 1;
	new->next = NULL;
	new->i = s->i++;
	new->ttab = tab;
	return (new);
}

int			ft_ways_push_front(t_s *s, t_list **begin_list, int i)
{
	int		**tab;
	t_list	*tmp;

	tab = NULL;
	if (*begin_list && begin_list)
	{
		if ((tmp = ft_create_elem_tab_way(s, i, tab)) == NULL)
			return (0);
		tmp->next = (*begin_list);
		(*begin_list) = tmp;
	}
	else
	{
		if (!((*begin_list) = ft_create_elem_tab_way(s, i, tab)))
			return (0);
	}
	return (1);
}

int			ft_list_copy(t_s *s, t_list **begin_list, t_list *copy)
{
	t_list	*tmp;
	int		**tab;

	tab = NULL;
	if (*begin_list && begin_list)
	{
		tmp = *begin_list;
		while (tmp->next)
			tmp = tmp->next;
		if (!(tmp->next = ft_create_elem_tab_final_way(s, copy, tab)))
			return (0);
	}
	else
	{
		if (!((*begin_list) = ft_create_elem_tab_final_way(s, copy, tab)))
			return (0);
	}
	return (1);
}
