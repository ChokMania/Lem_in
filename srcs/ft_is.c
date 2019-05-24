/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 15:56:28 by judumay           #+#    #+#             */
/*   Updated: 2019/05/24 14:35:04 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_is_comment(t_s *s)
{
	if (ft_strncmp(s->str, "##", 2) == 0 && s->str[2] && s->str[2] != '#')
		return (0);
	if (ft_strncmp(s->str, "#", 1) == 0)
		return (1);
	return (0);
}

int		ft_is_command(t_s *s)
{
	char *str;

	str = s->str;
	str = str + 2;
	if (ft_strequ(str, "start"))
	{
		if (s->commandstart != 0)
			return (-1);
		s->commandstart = 1;
	}
	if (ft_strequ(str, "end"))
	{
		if (s->commandend != 0)
			return (-1);
		s->commandend = 1;
	}
	return (1);
}

int		ft_check_name_room(t_s *s, char *name)
{
	t_room *beg;

	beg = s->room;
	while (beg)
	{
		if (ft_strcmp(name, beg->name) == 0)
			return (0);
		beg = beg->next;
	}
	return (1);
}

int		ft_is_room(t_s *s)
{
	char **room;

	if (!(s->i = 0) && (!s->str[0] || s->str[0] == 'L' || s->str[0] == '#'))
		return (-1);
	if (!(room = ft_strsplit(s->str, ' ')))
		return (-1);
	while (room[s->i])
		s->i++;
	if (s->i != 3)
	{
		ft_strtabdel(&room);
		return (-1);
	}
	s->i = -1;
	while (room[0][++s->i])
		if (room[0][s->i] == '-')
		{
			ft_strtabdel(&room);
			return (-1);
		}
	if ((s->i = 1) && (!ft_strisnum(room[1]) || !ft_strisnum(room[2])
			|| !ft_check_name_room(s, room[0])))
		s->i = -1;
	ft_strtabdel(&room);
	return (s->i);
}

int		ft_is_pipe(t_s *s)
{
	char **pipe;

	s->i = 0;
	if (!(pipe = ft_strsplit(s->str, '-')))
		return (-1);
	while (pipe[s->i])
		s->i++;
	if (s->i != 2)
	{
		ft_strtabdel(&pipe);
		return (-1);
	}
	if (!pipe[0][0] || pipe[0][0] == 'L' || pipe[0][0] == '#')
	{
		ft_strtabdel(&pipe);
		return (-1);
	}
	if (!pipe[1][0] || pipe[1][0] == 'L' || pipe[1][0] == '#')
	{
		ft_strtabdel(&pipe);
		return (-1);
	}
	ft_strtabdel(&pipe);
	return (1);
}
