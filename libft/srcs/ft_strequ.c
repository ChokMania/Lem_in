/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 17:28:39 by mabouce           #+#    #+#             */
/*   Updated: 2018/11/11 13:46:04 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	long long	i;

	if (s1 && s2)
	{
		i = 0;
		while (s1[i])
		{
			if (s1[i] != s2[i])
				return (0);
			i++;
		}
		if (s2[i])
			return (0);
		return (1);
	}
	else if ((s1 && !s2) || (!s1 && s2))
		return (0);
	else
		return (1);
}
