/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help_algo22.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 18:15:34 by judumay           #+#    #+#             */
/*   Updated: 2019/05/15 18:18:34 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_clear_tab_f(t_list **begin_list)
{
	t_list *save;

	save = *begin_list;
	while ((*begin_list)->next)
	{
		save = (*begin_list);
		(*begin_list) = (*begin_list)->next;
		if (save->ttab)
			ft_inttabdel(&save->ttab, 3);
		if (save->tab)
			free(save->tab);
		free(save);
	}
}

void	ft_clean_not_first(int **tab, int len1)
{
	int	i;
	int j;

	i = -1;
	j = -1;
	while (++i < len1)
	{
		if (tab[i][0] != -1)
			tab[i][0] = -5;
		tab[i][1] = -5;
	}
}

void	ft_clean_tab_tab_token(int **tab, int len1)
{
	int	i;
	int j;

	i = -1;
	j = -1;
	while (++i < len1)
	{
		if (tab[i][0] != -1 && tab[i][0] != -2)
			tab[i][0] = -5;
		tab[i][1] = -5;
	}
}

void	ft_clean_tab(int *tab, int len)
{
	int	i;

	i = -1;
	while (++i < len)
		tab[i] = -5;
}

void	ft_clean_tab_tab(int **tab, int len1)
{
	int	i;
	int j;

	i = -1;
	j = -1;
	while (++i < len1)
	{
		tab[i][0] = -5;
		tab[i][1] = -5;
	}
}
