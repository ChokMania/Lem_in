/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_paths_one_cont_one.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramard <lramard@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 10:17:59 by lramard           #+#    #+#             */
/*   Updated: 2019/05/08 17:35:48 by lramard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			ft_way_have_no_conflict(t_s *s, t_list *current)
{
	int i;

	i = 0;
	while (i < s->totalroom)
	{
		if (current->ttab[2][i] > 0)
			return (0);
		i++;
	}
	return (1);
}

int		ft_sp_check_connection(t_s *s, t_list *beg, int i, int j)
{
	if (beg->ttab[0][i - 1] == s->end_pos)
	{
		if ((s->ret = ft_sp_way_is_finished(s, beg)) == 1)
			return (1);
		else if (s->ret < 0)
			return (s->ret);
	}
	else if (beg->ttab[0][i - 1] > -5 && beg->finished == 0
		&& j != s->start_pos && s->matrice[beg->ttab[0][i - 1]][j]
		== 1 && beg->ttab[0][i - 1] != j && beg->ttab[1][i] < 0
		&& (s->matrice[j][j] > 1 || j == s->end_pos))
	{
		ft_sp_way_is_continuing(beg, i, j);
	}
	else if (beg->ttab[0][i - 1] > -5 && beg->finished == 0 &&
		j != s->start_pos && s->matrice[beg->ttab[0][i - 1]][j] == 1
		&& beg->ttab[0][i - 1] != j && beg->ttab[1][i] > 0
		&& (s->matrice[j][j] > 1 || j == s->end_pos))
	{
		if ((s->ret = ft_sp_way_is_duplicating(s, beg, i, j)) < 0)
			return (s->ret);
	}
	return (0);
}
