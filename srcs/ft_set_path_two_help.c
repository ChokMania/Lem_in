/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_path_two_help.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 15:03:06 by judumay           #+#    #+#             */
/*   Updated: 2019/05/13 11:40:29 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_parse_queue(int *tab)
{
	int i;

	i = -1;
	while (tab[++i] != -5)
	{
		if (tab[i] >= 0)
			break ;
	}
	if (tab[i] < 0)
		return (-4);
	return (tab[i]);
}

void	ft_reset_weight(t_s *s)
{
	int	i;

	i = -1;
	while (++i < s->totalroom)
	{
		s->weight[i][0] = -5;
		s->weight[i][1] = -5;
	}
}

int		ft_choose_the_one(int u, t_s *s)
{
	int i;

	i = -1;
	while (u > 0)
	{
		i++;
		if (s->matrice[s->st_pos][i] == 1 && i != s->st_pos)
			u--;
	}
	return (i);
}

int		*ft_intdup(int *i1, int len)
{
	int		*i2;
	int		i;

	i = 0;
	if (!(i2 = (int *)malloc(sizeof(int) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		i2[i] = i1[i];
		i++;
	}
	return (i2);
}

t_list	*ft_sort_list(t_list *lst, t_s *s)
{
	t_list	*tmp;
	int		*t;

	tmp = lst;
	while (lst != NULL && lst->next != NULL && !(s->ret = 0))
		if (ft_lenint(lst->tab, s) > ft_lenint(lst->next->tab, s))
		{
			!(t = ft_intdup(lst->tab, s->totalroom)) ? ft_error(s, -8) : 0;
			free(lst->tab);
			!(lst->tab = ft_intdup(lst->next->tab, s->totalroom))
				? s->ret = -9 : 0;
			free(lst->next->tab);
			!s->ret && !(lst->next->tab = ft_intdup(t, s->totalroom))
				? s->ret = -9 : 0;
			if (s->ret == -9)
			{
				free(t);
				ft_error(s, -8);
			}
			free(t);
			lst = tmp;
		}
		else
			lst = lst->next;
	return (tmp);
}
