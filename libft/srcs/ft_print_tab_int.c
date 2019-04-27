/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tab_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 16:18:45 by mabouce           #+#    #+#             */
/*   Updated: 2019/04/18 16:15:31 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_tab_int(int *tab, int size)
{
	long long i;

	i = 0;
	while (i < size)
	{
		ft_putnbr(tab[i]);
		ft_putchar('\n');
		i++;
	}
}
