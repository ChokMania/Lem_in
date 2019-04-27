/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 13:40:53 by mabouce           #+#    #+#             */
/*   Updated: 2018/11/08 15:31:47 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*d;
	int		save;

	i = 0;
	save = -1;
	d = (char *)s;
	while (d[i])
	{
		if (d[i] == c)
			save = i;
		i++;
	}
	if (save > -1)
		return (d + save);
	if (c == d[i])
		return (d + i);
	return (NULL);
}
