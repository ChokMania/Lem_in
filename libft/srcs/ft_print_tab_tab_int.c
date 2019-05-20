/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tab_tab_int.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 15:24:02 by mabouce           #+#    #+#             */
/*   Updated: 2019/05/20 15:17:45 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_tab_tab_int(int **tab, int len, int size)
{
	long long i;
	long long j;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < size)
		{
			ft_putnbrll(tab[i][j]);
			if (j + 1 != size)
				ft_putstr("    ");
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
