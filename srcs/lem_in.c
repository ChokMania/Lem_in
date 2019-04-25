/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 14:41:24 by mabouce           #+#    #+#             */
/*   Updated: 2019/04/24 15:24:38 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** map : nopath / empty / bigants
*/

int		ft_detect_room_or_pipe(t_s *s)
{
	if (ft_is_room(s) > 0)
	{
		s->oneroomisset = 1;
		if (s->settingpipe == 1)
			return (-2);
		if (!(ft_push_room(s)))
			return (-2);
	}
	else if (ft_is_pipe(s) > 0 && s->startset == 1 && s->endset == 1)
	{
		s->onepipeisset = 1;
		if (!(ft_push_pipe(s)))
			return (-2);
	}
	else
		return (-2);
	return (1);
}

int		ft_detect_line_type(t_s *s)
{
	if (ft_strncmp(s->str, "##", 2) == 0 && s->str[2] && s->str[2] != '#')
	{
		if (ft_is_command(s) < 0)
			return (-2);
	}
	else if (ft_is_comment(s))
	{
		if (!(ft_list_push_back(&s->comment, ft_strdup(s->str))))
			return (-2);
	}
	else if (ft_detect_room_or_pipe(s) < 0)
		return (-2);
	if (!(ft_list_push_back(&s->input, ft_strdupd(s->str))))
		return (-2);
	return (1);
}

int		ft_read_input(t_s *s)
{
	int	i;

	i = 0;
	while ((s->ret = get_next_line(0, &s->str)))
	{
		i = 1;
		if (s->ret < 0 || (s->nbantset == 0 && (!ft_is_comment(s)
						&& !ft_strisnum(s->str))))
			return (-2);
		else if (s->nbantset == 0 && ft_strisnum(s->str))
		{
			s->nbant = ft_atolli(s->str);
			if (s->nbant < 0)
				return (-2);
			s->nbantset = 1;
			ft_strdel(&s->str);
		}
		else if ((ft_detect_line_type(s)) < 1)
			return (-2);
	}
	if (i == 0)
		return (-1);
	return (1);
}

int		main(int ac, char **av)
{
	t_s	*s;
	int	ret;

	if (!(s = (t_s *)malloc(sizeof(t_s))))
		ft_error(s, 0);
	s->av = av;
	s->ac = ac;
	ft_set_struct(s);
	ft_set_flags(s);
	if ((ret = ft_read_input(s)) < 1 || !s->onepipeisset || !s->oneroomisset)
		ft_error(s, ret);
	if ((ret = ft_set_matrice_laplacienne(s)) < 1)
		ft_error(s, ret);
	ft_set_paths_start(s);
//	ft_select_paths(s);
	ft_apply_flag(s);
	ft_inttabdel(&s->matrice, s->totalroom);
	ft_inttabdel(&s->weight, s->totalroom);
	ft_strtabdel(&s->namematrice);
	free(s->pastway);
	ft_clear_struct(s);
	return (0);
}
