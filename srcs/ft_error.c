/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 15:28:05 by mabouce           #+#    #+#             */
/*   Updated: 2019/05/22 15:22:22 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_list_clear_tab(t_list **begin_list)
{
	t_list *save;

	save = *begin_list;
	while ((*begin_list))
	{
		save = (*begin_list);
		(*begin_list) = (*begin_list)->next;
		if (save->tab)
			free(save->tab);
		free(save);
	}
}

static void	ft_error_one(t_s *s, int error)
{
	if (error <= -7)
		;
	if (error <= -8)
		;
	if (error <= -9)
		ft_list_clear_tab(&s->ways);
	if (error <= -10)
		ft_list_clear_tab(&s->finalways);
	if (error <= -11)
		ft_inttabdel(&s->ants_in_way, s->maxway);
	if (error <= -12)
		ft_strtabdel(&s->color);
	ft_clear_struct(s);
}

void		ft_error(t_s *s, int error)
{
	error != 1 ? ft_putstr_fd("ERROR\n", 2) : 0;
	if (error == -1 || error == 1)
		free(s);
	if (error == -2)
	{
		get_next_line(0, NULL);
		ft_strdel(&s->str);
		ft_clear_struct(s);
	}
	if (error <= -3)
	{
		get_next_line(0, NULL);
		if (error <= -4)
			ft_inttabdel(&s->matrice, s->totalroom);
		if (error <= -5)
			ft_inttabdel(&s->weight, s->totalroom);
		if (error <= -6)
			ft_strtabdel(&s->namematrice);
		ft_error_one(s, error);
	}
	exit(0);
}
