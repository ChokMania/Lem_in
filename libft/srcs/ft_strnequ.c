/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnrequ.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 17:47:35 by mabouce           #+#    #+#             */
/*   Updated: 2018/11/11 13:46:06 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	i;

	if (n < 1)
		return (1);
	if (s1 && s2)
	{
		i = 0;
		while (s1[i] && i < n)
		{
			if (s1[i] != s2[i])
				return (0);
			i++;
		}
		if (i < n && s2[i])
			return (0);
		return (1);
	}
	else if ((s1 && !s2) || (!s1 && s2))
		return (0);
	else
		return (1);
}
