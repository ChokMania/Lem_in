/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 13:59:40 by judumay           #+#    #+#             */
/*   Updated: 2019/05/15 18:23:23 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_list_remove_first_data_finalways(t_list **begin_list)
{
	t_list	*tmp;

	tmp = *begin_list;
	if (*begin_list && begin_list)
	{
		if ((*begin_list)->next)
		{
			*begin_list = tmp->next;
			ft_inttabdel(&tmp->ttab, 3);
			free(tmp);
			tmp = NULL;
		}
	}
}

void	ft_list_remove_middle_data_finalways(t_s *s
	, t_list **begin_list, t_list *elem)
{
	t_list	*tmp;
	t_list	*tmpnext;

	tmp = *begin_list;
	if (*begin_list && begin_list)
	{
		if (tmp == elem)
			ft_list_remove_first_data_finalways(&s->ways);
		else if (tmp->next)
		{
			while (tmp && tmp->next && tmp->next != elem)
				tmp = tmp->next;
			tmpnext = tmp->next;
			tmp->next = tmp->next->next;
			ft_inttabdel(&tmpnext->ttab, 3);
			free(tmpnext);
			tmpnext = NULL;
		}
		else
		{
			ft_list_remove_last_data_finalways(&s->ways);
		}
	}
}

void	ft_list_remove_last_data_finalways(t_list **begin_list)
{
	t_list	*tmp;
	t_list	*beg;

	beg = *begin_list;
	tmp = beg;
	if (*begin_list && begin_list)
	{
		while (tmp->next)
		{
			beg = tmp;
			tmp = tmp->next;
		}
		ft_inttabdel(&beg->next->ttab, 3);
		free(beg->next);
		beg->next = NULL;
	}
}

void	ft_del_useless_list_elem(t_s *s)
{
	t_list	*beg;
	t_list	*next;
	int		i;
	int		j;

	beg = s->finalways;
	i = -1;
	j = 0;
	while (++i < s->totalroom && s->tab[i] != -5)
	{
		while (beg && j < s->tab[i])
		{
			next = beg->next;
			beg == s->finalways
				? ft_list_remove_first_data_finalways(&s->finalways)
				: ft_list_remove_middle_data_finalways(s, &s->finalways, beg);
			beg = next;
			j++;
		}
		j == s->tab[i] && (++j) ? beg = beg->next : 0;
	}
	while (beg && beg->next)
		ft_list_remove_last_data_finalways(&s->finalways);
	if (beg)
		ft_list_remove_last_data_finalways(&s->finalways);
}
