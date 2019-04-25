/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 15:06:36 by mabouce           #+#    #+#             */
/*   Updated: 2019/04/18 16:48:08 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_set_db(t_struct *stru)
{
	stru->db[0] = "sa";
	stru->db[1] = "sb";
	stru->db[2] = "ss";
	stru->db[3] = "pa";
	stru->db[4] = "pb";
	stru->db[5] = "ra";
	stru->db[6] = "rb";
	stru->db[7] = "rr";
	stru->db[8] = "rra";
	stru->db[9] = "rrb";
	stru->db[10] = "rrr";
}

int		ft_check_line(t_struct *stru)
{
	stru->i = 0;
	ft_set_db(stru);
	while (stru->i < 11)
	{
		if (ft_strequ(stru->line, stru->db[stru->i]) == 1)
			return (1);
		stru->i++;
	}
	return (0);
}

int		ft_check_flags(char *str, t_struct *stru)
{
	int	i;

	if (str[0] == '-')
	{
		i = 1;
		if (!str[i])
			return (0);
		while (str[i])
		{
			if (str[i] == 'l')
				stru->flag_light = 1;
			else if (str[i] == 'v')
				stru->flag_visu = 1;
			else if (str[i] == 'n')
				stru->flag_count_instru = 1;
			else
				return (0);
			i++;
		}
		return (1);
	}
	else
		return (0);
}

int		ft_push_av(t_struct *stru)
{
	int	i;

	i = 1;
	while (stru->split[stru->j][i])
	{
		if (stru->split[stru->j][i] < '0' || stru->split[stru->j][i] > '9')
			return (0);
		i++;
	}
	stru->lli = ft_atolli(stru->split[stru->j]);
	if (stru->lli > 2147483647 || stru->lli < -2147483648)
		return (0);
	ft_check_double(stru, stru->lli);
	if (!(ft_list_push_back(&stru->pile_a, (void *)stru->lli)))
		return (0);
	return (1);
}

int		ft_check_av_and_fill(t_struct *stru)
{
	stru->j = 0;
	while (stru->split[stru->j])
	{
		if (ft_check_flags(stru->split[stru->j], stru) == 1)
		{
			stru->j++;
			continue;
		}
		if (stru->split[stru->j][0] < '0' || stru->split[stru->j][0] > '9')
		{
			if (stru->split[stru->j][0] == '+'
					|| stru->split[stru->j][0] == '-')
			{
				if (stru->split[stru->j][1] < '0'
						|| stru->split[stru->j][1] > '9')
					return (0);
			}
			else
				ft_error(stru, -2);
		}
		if (!(ft_push_av(stru)))
			return (0);
		stru->j++;
	}
	return (1);
}
