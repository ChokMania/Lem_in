/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 10:25:55 by mabouce           #+#    #+#             */
/*   Updated: 2018/11/08 11:48:14 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*dest;
	unsigned int	i;

	dest = (unsigned char*)s;
	i = 0;
	while (i < n)
	{
		if (dest[i] == (unsigned char)c)
			return (dest + i);
		i++;
	}
	return (NULL);
}
