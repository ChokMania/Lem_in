/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrice.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 15:05:18 by mabouce           #+#    #+#             */
/*   Updated: 2019/05/07 11:28:59 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			ft_set_matrice_laplacienne(t_s *s)
{
	t_room	*beg;

	s->i = 0;
	beg = s->room;
	while (s->start_pos == -1 || s->end_pos == -1)
	{
		if (beg->startpos == 1)
			s->start_pos = s->i;
		else if (beg->startpos == 2)
			s->end_pos = s->i;
		beg = beg->next;
		s->i++;
	}
	s->i = -1;
	while (++s->i < s->totalroom && (s->j = -1))
	{
		s->k = 0;
		while (++s->j < s->totalroom)
			if (s->matrice[s->i][s->j] == 1)
				s->k++;
		s->matrice[s->i][s->i] = s->k;
		if ((s->i == s->start_pos || s->i == s->end_pos) && s->k < 1)
			return (-6);
	}
	return (1);
}

int			ft_make_matrice(t_s *s, char *name1, char *name2)
{
	int		tab[2];

	s->i = 0;
	s->k = 0;
	while (s->namematrice[s->i])
	{
		if (!ft_strcmp(s->namematrice[s->i], name1) && ++s->k)
			tab[0] = s->i;
		if (!ft_strcmp(s->namematrice[s->i], name2) && ++s->k)
			tab[1] = s->i;
		if (s->k == 2)
			break ;
		s->i++;
	}
	if (s->k != 2)
		return (-6);
	s->matrice[tab[0]][tab[1]] = 1;
	s->matrice[tab[1]][tab[0]] = 1;
	return (1);
}

int			ft_create_name_matrice(t_s *s)
{
	t_room	*beg;

	beg = s->room;
	if (!(s->namematrice = (char **)malloc(sizeof(char *)
					* (s->totalroom + 1))))
		return (-5);
	s->i = -1;
	while (beg)
	{
		if (!(s->namematrice[++(s->i)] = ft_strdup(beg->name)))
			return (-6);
		beg = beg->next;
	}
	s->namematrice[++(s->i)] = NULL;
	return (1);
}

long long	ft_total_room(t_room *room)
{
	int		i;
	t_room	*beg;

	i = 0;
	beg = room;
	while (beg)
	{
		i++;
		beg = beg->next;
	}
	return (i);
}

int			ft_matrice(t_s *s, char *name1, char *name2)
{
	if (s->settingpipe == 0 && (s->settingpipe = 1))
	{
		s->totalroom = ft_total_room(s->room);
		s->i = -1;
		if (!(s->matrice = (int **)malloc(sizeof(int *) * (s->totalroom + 1))))
			return (-3);
		if (!(s->weight = (int **)malloc(sizeof(int *) * (s->totalroom + 1))))
			return (-4);
		while (++s->i < s->totalroom && (s->j = -1))
		{
			if (!(s->matrice[s->i] = (int *)malloc(sizeof(int) * s->totalroom)))
				return (-5);
			if (!(s->weight[s->i] = (int *)malloc(sizeof(int) * s->totalroom)))
				return (-5);
			while (++(s->j) < s->totalroom && (s->matrice[s->i][s->j] = -5))
				s->weight[s->i][s->j] = -5;
		}
		if ((s->ret = ft_create_name_matrice(s)) < 0)
			return (s->ret);
	}
	if ((s->ret = ft_make_matrice(s, name1, name2)) < 0)
		return (s->ret);
	return (1);
}
