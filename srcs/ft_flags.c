/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 16:37:02 by mabouce           #+#    #+#             */
/*   Updated: 2019/04/22 13:07:42 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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
			if (s->av[i][j] == 'c')
				s->flag_c = 1;
			else if (s->av[i][j] == 'm')
				s->flag_m = 1;
			else if (s->av[i][j] == 'n')
				s->flag_n = 1;
			j++;
		}
		i++;
	}
}

void	ft_apply_flag(t_s *s)
{
	ft_print_matrice(s);
	!s->flag_n ? ft_putnbrll(s->nbant) : 0;
	!s->flag_n ? ft_putchar('\n') : 0;
	!s->flag_n ? ft_list_print_str(s->input) : 0;
}
