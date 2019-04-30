/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_matrice.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 16:15:58 by mabouce           #+#    #+#             */
/*   Updated: 2019/04/30 18:16:54 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_room_print(t_room *room)
{
	if (!(room))
		return ;
	while (room)
	{
		ft_putstr(room->name);
		ft_putstr(" x=");
		ft_putnbrll(room->x);
		ft_putstr(" y=");
		ft_putnbrll(room->y);
		if (room->startpos == 1)
			ft_putstr(" - start");
		else if (room->startpos == 2)
			ft_putstr(" - end");
		ft_putchar('\n');
		room = room->next;
	}
}

int			ft_check_name(t_s *s, char *str)
{
	t_room	*beg;

	beg = s->room;
	while (ft_strcmp(beg->name, str) != 0)
		beg = beg->next;
	return (beg->startpos);
}

void		ft_print_matrice_suite(t_s *s, int i, int j)
{
	while (++i < s->totalroom)
	{
		j = -1;
		if (!ft_check_name(s, s->namematrice[i]))
			miniprintf("%% %2.2s", "YELLOW", s->namematrice[i]);
		if (ft_check_name(s, s->namematrice[i]) == 1)
			miniprintf("%% %2.2s", "GREEN", s->namematrice[i]);
		if (ft_check_name(s, s->namematrice[i]) == 2)
			miniprintf("%% %2.2s", "RED", s->namematrice[i]);
		miniprintf("%% | ", "END");
		while (++j < s->totalroom)
		{
			s->matrice[i][j] ? ft_putstr("\033[34m") : ft_putstr("\033[0m");
			s->matrice[i][j] > 1 ? ft_putstr("\033[36m") : 0;
			i == j ? ft_putstr("\033[35m") : 0;
			ft_putnbrll(s->matrice[i][j]);
			miniprintf("%%", "END");
			j + 1 != s->totalroom ? ft_putstr("  ") : 0;
		}
		ft_putstr(" |\n");
	}
	ft_putstr("     ");
	while (i-- > 0)
		ft_putstr("---");
	ft_putchar('\n');
}

void		ft_print_matrice(t_s *s)
{
	long long	i;

	if (s->flag_c && s->flag_m)
	{
		i = -1;
		ft_putstr("    ");
		while (++i < s->totalroom)
		{
			if (!ft_check_name(s, s->namematrice[i]))
				miniprintf("%% %2.2s", "YELLOW", s->namematrice[i]);
			if (ft_check_name(s, s->namematrice[i]) == 1)
				miniprintf("%% %2.2s", "GREEN", s->namematrice[i]);
			if (ft_check_name(s, s->namematrice[i]) == 2)
				miniprintf("%% %2.2s", "RED", s->namematrice[i]);
			miniprintf("%%", "END");
		}
		ft_putstr("\n     ");
		while (i-- > 0)
			ft_putstr("---");
		ft_putchar('\n');
		ft_print_matrice_suite(s, -1, -1);
	}
	else if (s->flag_m == 1)
		ft_print_tab_tab_int(s->matrice, s->totalroom, s->totalroom);
}
