/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 14:21:29 by judumay           #+#    #+#             */
/*   Updated: 2019/05/24 14:01:42 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_parse_queue(int *tab)
{
	int i;

	i = -1;
	while (tab[++i] != -5)
	{
		if (tab[i] >= 0)
			break ;
	}
	if (tab[i] < 0)
		return (-4);
	return (tab[i]);
}

void	ft_clean_tab_tab(int **tab, int len, int check)
{
	int i;

	i = -1;
	if (check == 0)
		while (++i < len)
		{
			tab[i][0] = -5;
			tab[i][1] = -5;
			tab[i][2] = -5;
		}
	if (check == 1)
		while (++i < len)
		{
			if (tab[i][0] != -1)
				tab[i][0] = -5;
			tab[i][1] = -5;
			tab[i][2] = -5;
		}
}

void	ft_clean_tab(int *tab, int len)
{
	int i;

	i = -1;
	while (++i < len)
		tab[i] = -5;
}

void	ft_push_or_not(t_s *s, int *queue, int i, int start)
{
	int l;

	l = s->weight[s->end_pos][0];
	i == -4 ? queue[0] = start : 0;
	i == -4 ? i = -1 : 0;
	while (i != -1)
	{
		queue[l--] = i;
		i != s->end_pos ? s->weight[i][0] = -1 : 0;
		i = s->weight[i][1];
	}
	if (!(ft_ways_push_front_two(s, &s->ways, queue)))
	{
		free(queue);
		ft_error(s, -10);
	}
	ft_clean_tab(queue, s->ttroom);
}

int		ft_conflict(t_s *s, int i)
{
	if (s->matrice[i][i] > 2 && s->weight[i][2] == -5 && i != s->end_pos
		&& i != s->st_pos)
		return (1 + s->i++);
	return (s->weight[i][2]);
}
