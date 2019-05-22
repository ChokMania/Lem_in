/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_and_pipes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 16:37:02 by mabouce           #+#    #+#             */
/*   Updated: 2019/05/22 14:34:25 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_push_pipe(t_s *s)
{
	char **pipe;
	char *name1;
	char *name2;

	if (!(pipe = ft_strsplit(s->str, '-')))
		return (0);
	if (!(name2 = ft_strdup(pipe[1]))
		|| !(name1 = ft_strdup(pipe[0])))
	{
		if (!(name2))
			ft_strdel(&name1);
		ft_strtabdel(&pipe);
		return (0);
	}
	if (!ft_strcmp(name1, name2) || ft_matrice(s, name1, name2) < 1)
	{
		ft_strtabdel(&pipe);
		ft_strdel(&name1);
		ft_strdel(&name2);
		return (0);
	}
	ft_strtabdel(&pipe);
	ft_strdel(&name1);
	ft_strdel(&name2);
	return (1);
}

void	ft_set_flags(t_s *s)
{
	int	i;
	int j;

	i = 1;
	while (i < s->ac)
	{
		j = 1;
		if (!s->av[i][j])
			return ;
		while (s->av[i][j])
		{
			s->av[i][j] == 'c' ? s->flag_c = 1 : 0;
			s->av[i][j] == 'h' ? s->flag_h = 1 : 0;
			s->av[i][j] == 'm' ? s->flag_m = 1 : 0;
			if (s->av[i][j] == 'n')
			{
				s->flag_n = 1;
				if (s->av[i][j + 1] == 'n')
					s->flag_nn = 1;
			}
			j++;
		}
		i++;
	}
}

void	ft_apply_flag(t_s *s)
{
	!s->flag_n ? ft_putnbrll(s->nbant) : 0;
	!s->flag_n ? ft_putchar('\n') : 0;
	!s->flag_n ? ft_list_print_str(s->input) : 0;
	ft_print_matrice(s);
}
