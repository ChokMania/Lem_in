/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help_print_path.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 18:09:53 by judumay           #+#    #+#             */
/*   Updated: 2019/05/21 14:26:28 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static	int	ft_move_ants(t_s *s, t_list *beg, int k, int j)
{
	int		i;

	i = s->k + 1;
	while (--i >= 0)
	{
		if (s->ants_in_way[s->j][i] >= 0)
		{
			if (i == s->k)
				s->ants_in_way[s->j][i] = -5;
			else
			{
				k == 1 || j == 2 ? miniprintf(" ") : 0;
				s->flag_c ? miniprintf("%s", s->color[s->j % 7]) : 0;
				k = 1;
				miniprintf("L%d-%s", s->ants_in_way[s->j][i]
					, s->namematrice[beg->tab[i]]);
				s->ants_in_way[s->j][i + 1] = s->ants_in_way[s->j][i];
				s->ants_in_way[s->j][i] = -5;
				s->flag_c ? miniprintf("\x1b[0m") : 0;
				s->p++;
			}
		}
	}
	return (k);
}

static void	ft_choice_put(t_s *s, int exception)
{
	int save;

	save = s->p;
	s->p = exception >= 1 ? 0 : s->p;
	s->p ? ft_putchar('\n') : 0;
	s->p = save;
}

static void	ft_print_suite_suite(t_s *s, int exception, int number_ants
	, int **tab)
{
	t_list	*beg;
	int		k;

	k = 0;
	while (s->p)
	{
		s->p = 0;
		s->i == 0 ? s->p = 1 : 0;
		s->j = -1;
		beg = s->finalways;
		k = 0;
		while (beg)
		{
			s->j++;
			s->k = ft_lenint(beg->tab, s);
			if (tab[s->j][1]-- > 0 && (number_ants = ++s->i))
				s->ants_in_way[s->j][0] = number_ants;
			k = ft_move_ants(s, beg, k, exception);
			exception >= 1 ? exception = 2 : 0;
			beg = beg->next;
		}
		ft_choice_put(s, exception);
	}
}

void		ft_print_path_suite(t_s *s, int number_ants, int **tab)
{
	int	exception;

	exception = tab[0][0] == 1 ? 1 : 0;
	s->i = 0;
	s->p = 1;
	ft_print_suite_suite(s, exception, number_ants, tab);
	exception >= 1 ? ft_putchar('\n') : 0;
}
