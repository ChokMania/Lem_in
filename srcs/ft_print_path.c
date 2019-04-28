/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 11:51:01 by judumay           #+#    #+#             */
/*   Updated: 2019/04/26 18:29:19 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			ft_color(t_s *s)
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

int			*ft_intdup(int *i1, int len)
{
	int		*i2;

	if (!(i2 = (int *)ft_memalloc(sizeof(int) * (len + 1))))
		return (NULL);
	while (len > -1)
	{
		i2[len] = i1[len];
		len--;
	}
	return (i2);
}

void		ft_move_ants(t_s *s, int ants)
{
	int		i;

	i = s->k;
	while (--i >= 0)
	{
		if (s->ants_in_way[s->j][i] >= 0)
		{
			if (i == s->k - 1)
				s->ants_in_way[s->j][i] = -1;
			else
			{
				s->ants_in_way[s->j][i + 1] = s->ants_in_way[s->j][i];
				s->ants_in_way[s->j][i] = -1;
				if (s->flag_c)
					miniprintf("%s", s->color[s->j]);
				miniprintf("L%d-%s", s->ants_in_way[s->j][i + 1],
					s->namematrice[s->finalway[s->j][i + 1]]);
				if (s->j != s->maxway - 1)
					miniprintf(" ");
				miniprintf("\x1b[0m");
				s->p++;
			}
		}
	}
}

void		ft_print_path_suite(t_s *s, int number_ants)
{
	s->i = 0;
	s->p = 1;
	while (s->p)
	{
		s->p = 0;
		s->i == 0 ? s->p = 1 : 0;
		s->j = -1;
		while (++s->j < s->maxway)
		{
			s->k = ft_lenint(s->finalway[s->j]);
			number_ants = number_ants < s->nbant
				&& number_ants > -1 ? number_ants + 1 : -1;
			if (s->i != 0)
				ft_move_ants(s, number_ants);
			s->ants_in_way[s->j][0] = number_ants;
		}
		s->i++;
		s->p ? ft_putchar('\n') : 0;
	}
}

int			ft_print_path(t_s *s)
{
/*
**int tab1[5] = {7, 5, 4, 6, -1};
**int tab2[4] = {7, 3, 6, -1};
**int tab3[6] = {7, 2, 1, 0, 6, -1};
**s->maxway = 3;
**s->finalway = malloc(4);
**s->finalway[0] = ft_intdup(tab1, 6);
**s->finalway[1] = ft_intdup(tab2, 4);
**s->finalway[2] = ft_intdup(tab3, 7);
**s->finalway[3] = NULL;
*/
	int		number_ants;

	number_ants = 0;
	if (!ft_color(s))
		ft_error(s, -8);
	s->i = -1;
	if (!(s->ants_in_way = (int**)malloc(sizeof(int*) * (s->maxway + 1))))
		ft_error(s, -9);
	while (++s->i < s->maxway)
	{
		s->j = -1;
		if (!(s->ants_in_way[s->i] = (int*)malloc(sizeof(int) *
			s->totalroom)))
			ft_error(s, -9);
		while (++s->j < s->totalroom)
			s->ants_in_way[s->i][s->j] = -1;
	}
	ft_print_path_suite(s, number_ants);
	return (1);
}
