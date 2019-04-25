/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 15:25:03 by mabouce           #+#    #+#             */
/*   Updated: 2019/04/24 14:00:06 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_list_clear_tab_int(t_list **begin_list)
{
	t_list	*save;

	save = *begin_list;
	while ((*begin_list))
	{
		save = (*begin_list);
		(*begin_list) = (*begin_list)->next;
		free(save->tab);
		free(save);
	}
}

void	ft_clear_struct(t_s *s)
{
	ft_room_clear(&s->room);
	ft_list_clear_data(&s->comment);
	ft_list_clear_data(&s->command);
	ft_list_clear_data(&s->input);
	ft_list_clear_tab_int(&s->ways);
	free(s);
}

int		ft_set_struct(t_s *s)
{
	s->input = NULL;
	s->comment = NULL;
	s->command = NULL;
	s->room = NULL;
	s->ways = NULL;
	s->commandstart = 0;
	s->commandend = 0;
	s->startset = 0;
	s->endset = 0;
	s->nbant = -1;
	s->nbantset = 0;
	s->totalplays = 0;
	s->settingpipe = 0;
	s->oneroomisset = 0;
	s->onepipeisset = 0;
	s->flag_c = 0;
	s->flag_m = 0;
	s->flag_n = 0;
	s->start_pos = -1;
	s->end_pos = -1;
	return (1);
}
