/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 13:40:53 by mabouce           #+#    #+#             */
/*   Updated: 2018/11/08 13:54:23 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*d;

	i = 0;
	d = (char *)s;
	while (d[i])
	{
		if (d[i] == c)
			return (d + i);
		i++;
	}
	if (c == d[i])
		return (d + i);
	return (NULL);
}
