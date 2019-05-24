/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 16:01:34 by judumay           #+#    #+#             */
/*   Updated: 2019/05/24 14:35:04 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniprintf.h"

void	ft_set_struct_mini(t_ms *s)
{
	if (!(s->output = ft_strnew(0)))
		ft_error_miniprintf(s, -2);
	s->width = 0;
	s->accu = 0;
	s->conv = "csdi%";
	s->zero_fill = 0;
}
