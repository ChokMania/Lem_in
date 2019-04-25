/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 15:28:05 by mabouce           #+#    #+#             */
/*   Updated: 2019/04/24 14:57:33 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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
			free(s->pastway);
		ft_clear_struct(s);
	}
	exit(0);
}
