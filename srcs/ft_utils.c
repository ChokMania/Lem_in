/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 13:59:40 by judumay           #+#    #+#             */
/*   Updated: 2019/05/07 10:09:15 by judumay          ###   ########.fr       */
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

void	ft_print_ways(t_s *s)
{
	t_list *beg;

	miniprintf("%%", "YELLOW");
	beg = s->finalways;
	while (beg)
	{
		miniprintf("ant name : %i\n\n", beg->i);
		ft_print_tab_tab_int_tmp(s, beg->ttab, 3, s->totalroom);
		beg = beg->next;
	}
	miniprintf("%%", "END");
}

void	ft_list_remove_middle_data_finalways(t_s *s, t_list **begin_list, t_list *elem)
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
	i = 0;
	j = 0;
	while (i < s->totalroom && s->tab[i] != -5)
	{
		while (beg && j < s->tab[i])
		{
			next = beg->next;
			if (beg == s->finalways)
				ft_list_remove_first_data_finalways(&s->finalways);
			else
				ft_list_remove_middle_data_finalways(s, &s->finalways, beg);
			beg = next;
			j++;
		}
		if (j == s->tab[i])
		{
			beg = beg->next;
			j++;
		}
		i++;
	}
	while (beg && beg->next)
		ft_list_remove_last_data_finalways(&s->finalways);
	if (beg)
		ft_list_remove_last_data_finalways(&s->finalways);
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
				ft_putstr("");
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
