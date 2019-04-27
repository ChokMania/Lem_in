/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 15:35:53 by mabouce           #+#    #+#             */
/*   Updated: 2018/11/10 16:34:34 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strrev(char **src)
{
	int		max;
	int		min;
	char	tmp;

	max = ft_strlen(*src);
	min = 0;
	while (min < max)
	{
		tmp = (*src)[min];
		(*src)[min] = (*src)[max - 1];
		(*src)[max - 1] = tmp;
		min++;
		max--;
	}
}
