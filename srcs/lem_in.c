/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 14:41:24 by mabouce           #+#    #+#             */
/*   Updated: 2019/05/09 17:10:13 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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

void	ft_main_algo_one(t_s *s)
{
	ft_set_paths_start(s);
	ft_list_size(s->finalways) > 0 ? ft_print_path(s) : 0;
	ft_inttabdel(&s->matrice, s->totalroom);
	ft_inttabdel(&s->weight, s->totalroom);
	ft_strtabdel(&s->namematrice);
	free(s->tab);
	free(s->tb);
	ft_inttabdel(&s->ants_in_way, s->maxway);
	ft_strtabdel(&s->color);
	ft_list_clear_tab(&s->ways);
	ft_list_clear_tab(&s->finalways);
	ft_clear_struct(s);
}

void	ft_main_algo_two(t_s *s)
{
	ft_set_paths_start_two(s);
	ft_list_size(s->finalways) > 0 ? ft_print_path(s) : 0;
	ft_inttabdel(&s->matrice, s->totalroom);
	ft_inttabdel(&s->weight, s->totalroom);
	ft_strtabdel(&s->namematrice);
	//ft_inttabdel(&s->ants_in_way, s->maxway);
	//ft_strtabdel(&s->color);
	ft_list_clear_tab(&s->finalways);
	ft_clear_struct(s);
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
	ft_apply_flag(s);
	ft_calcul_nb_pipes(s);
	s->algo = s->liaisons / 2 - s->totalroom < 70 ? 1 : 2;
	s->algo = 2;
	s->algo == 1 ? ft_main_algo_one(s) : ft_main_algo_two(s);
	return (0);
}
