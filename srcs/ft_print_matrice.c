/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_matrice.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 16:15:58 by mabouce           #+#    #+#             */
/*   Updated: 2019/05/22 13:22:23 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	ft_check_name(t_s *s, char *str)
{
	t_room	*beg;

	beg = s->room;
	while (ft_strcmp(beg->name, str) != 0)
		beg = beg->next;
	return (beg->startpos);
}

static void	ft_print_matrice_m(t_s *s, int i, int j)
{
	while (++i < s->totalroom)
	{
		j = -1;
		while (++j < s->totalroom)
		{
			s->matrice[i][j] == -5 ? miniprintf(" 0")
				: miniprintf("%2d", s->matrice[i][j]);
			j + 1 != s->totalroom ? ft_putstr("  ") : 0;
		}
		ft_putstr("\n");
	}
	ft_putchar('\n');
}

static void	ft_print_matrice_suite(t_s *s, int i, int j)
{
	while (++i < s->totalroom && (j = -1))
	{
		if (!ft_check_name(s, s->namematrice[i]))
			miniprintf("%% %3.3s", "YELLOW", s->namematrice[i]);
		if (ft_check_name(s, s->namematrice[i]) == 1)
			miniprintf("%% %3.3s", "GREEN", s->namematrice[i]);
		if (ft_check_name(s, s->namematrice[i]) == 2)
			miniprintf("%% %3.3s", "RED", s->namematrice[i]);
		miniprintf("%% | ", "END");
		while (++j < s->totalroom)
		{
			s->matrice[i][j] ? ft_putstr("\033[34m") : ft_putstr("\033[0m");
			s->matrice[i][j] == 1 ? ft_putstr("\033[32m") : 0;
			i == j ? ft_putstr("\033[35m") : 0;
			s->matrice[i][j] == -5 ? miniprintf(" 0")
				: miniprintf("%2d", s->matrice[i][j]);
			miniprintf("%%", "END");
			j + 1 != s->totalroom ? ft_putstr("  ") : 0;
		}
		ft_putstr(" |\n");
	}
	ft_putstr("      ");
	while (i-- > 0)
		ft_putstr("----");
	ft_putchar('\n');
}

void		ft_print_matrice(t_s *s)
{
	long long	i;

	if (s->flag_c && s->flag_m)
	{
		i = -1;
		ft_putstr("     ");
		while (++i < s->totalroom)
		{
			if (!ft_check_name(s, s->namematrice[i]))
				miniprintf("%% %3.3s", "YELLOW", s->namematrice[i]);
			if (ft_check_name(s, s->namematrice[i]) == 1)
				miniprintf("%% %3.3s", "GREEN", s->namematrice[i]);
			if (ft_check_name(s, s->namematrice[i]) == 2)
				miniprintf("%% %3.3s", "RED", s->namematrice[i]);
			miniprintf("%%", "END");
		}
		ft_putstr("\n      ");
		while (i-- > 0)
			ft_putstr("----");
		ft_putchar('\n');
		ft_print_matrice_suite(s, -1, -1);
	}
	else if (s->flag_m == 1)
		ft_print_matrice_m(s, -1, -1);
}
