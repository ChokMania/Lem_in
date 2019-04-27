/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:52:54 by mabouce           #+#    #+#             */
/*   Updated: 2018/11/11 14:52:32 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	unsigned char	*src;
	char			*dest;

	if (s)
	{
		i = 0;
		src = (unsigned char *)s;
		if (!(dest = (char *)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		while (i < start)
			i++;
		ft_strncpy(dest, ((const char *)src + i), len);
		dest[len] = '\0';
		return (dest);
	}
	else
		return (NULL);
}
