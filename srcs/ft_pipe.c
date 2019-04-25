/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 17:43:02 by mabouce           #+#    #+#             */
/*   Updated: 2019/04/22 16:48:56 by judumay          ###   ########.fr       */
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
