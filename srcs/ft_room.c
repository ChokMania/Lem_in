/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_room.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 17:08:39 by judumay           #+#    #+#             */
/*   Updated: 2019/05/24 14:35:04 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_room_clear(t_room **room)
{
	t_room *save;

	while ((*room))
	{
		save = (*room);
		(*room) = (*room)->next;
		ft_strdel(&save->name);
		free(save);
	}
}

t_room	*ft_create_room(char *name, long long x, long long y, int startpos)
{
	t_room *new;

	if (!(new = (t_room *)malloc(sizeof(t_room))))
		return (NULL);
	new->next = NULL;
	new->name = name;
	if (startpos == 1)
	{
		new->startpos = 1;
	}
	else if (startpos == 2)
	{
		new->startpos = 2;
	}
	else
		new->startpos = 0;
	new->x = x;
	new->y = y;
	new->poid = 0;
	return (new);
}

int		ft_push_front_room(t_room **room, char *name, long long tab[2]
	, int startpos)
{
	t_room *tmp;

	if (*room && room)
	{
		if (!(tmp = ft_create_room(name, tab[0], tab[1], startpos)))
			return (0);
		tmp->next = *room;
		*room = tmp;
	}
	else
	{
		if (!(*room = ft_create_room(name, tab[0], tab[1], startpos)))
			return (0);
	}
	return (1);
}

int		ft_push_room_suite(t_s *s, char **room, char *name, int startpos)
{
	long long	tab[2];

	tab[0] = ft_atolli(room[1]);
	tab[1] = ft_atolli(room[2]);
	if (!(ft_push_front_room(&(s->room), name, tab, startpos)))
	{
		ft_strtabdel(&room);
		ft_strdel(&name);
		return (0);
	}
	ft_strtabdel(&room);
	return (1);
}

int		ft_push_room(t_s *s)
{
	char		**room;
	char		*name;
	int			startpos;

	if (!(room = ft_strsplit(s->str, ' ')))
		return (0);
	if (!(name = ft_strdup(room[0])))
	{
		ft_strtabdel(&room);
		return (0);
	}
	startpos = 0;
	if (s->commandstart == 1 && s->startset == 0 && (s->startset = 1))
		startpos = 1;
	else if (s->commandend == 1 && s->endset == 0 && (s->endset = 1))
		startpos = 2;
	if (!ft_push_room_suite(s, room, name, startpos))
		return (0);
	return (1);
}
