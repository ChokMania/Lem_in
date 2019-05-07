/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 15:28:05 by mabouce           #+#    #+#             */
/*   Updated: 2019/05/07 13:16:43 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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

int		ft_color(t_s *s)
{
	if (!(s->color = (char**)malloc(sizeof(char*) * 8)))
		return (0);
	s->color[0] = ft_strdup("\x1b[31m");
	s->color[1] = ft_strdup("\x1b[32m");
	s->color[2] = ft_strdup("\x1b[33m");
	s->color[3] = ft_strdup("\x1b[34m");
	s->color[4] = ft_strdup("\x1b[35m");
	s->color[5] = ft_strdup("\x1b[36m");
	s->color[6] = ft_strdup("\x1b[37m");
	s->color[7] = NULL;
	return (1);
}

void	ft_list_clear_tab(t_list **begin_list)
{
	t_list *save;

	save = *begin_list;
	while ((*begin_list))
	{
		save = (*begin_list);
		(*begin_list) = (*begin_list)->next;
		if (save->ttab)
			ft_inttabdel(&save->ttab, 3);
		free(save);
	}
}

void	ft_error(t_s *s, int error)
{
	ft_putstr("error num = ");
	ft_putnbr(error);
	ft_putchar('\n');
	ft_putstr_fd("ERROR\n", 2);
	if (error == -1)
		free(s);
	if (error == -2)
	{
		get_next_line(0, NULL);
		ft_strdel(&s->str);
		ft_clear_struct(s);
	}
	if (error <= -3)
	{
		if (error <= -4)
			ft_inttabdel(&s->matrice, s->totalroom);
		if (error <= -5)
			ft_inttabdel(&s->weight, s->totalroom);
		if (error <= -6)
			ft_strtabdel(&s->namematrice);
		if (error <= -7)
			free(s->tab);
		if (error <= -8)
			free(s->tb);
		if (error <= -9)
			ft_list_clear_tab(&s->ways);
		//if (error <= 10)

		if (error <= -11)
			ft_inttabdel(&s->ants_in_way, s->maxway);
		if (error <= -12)
			ft_strtabdel(&s->color);
		ft_clear_struct(s);
	}
	exit(0);
}
