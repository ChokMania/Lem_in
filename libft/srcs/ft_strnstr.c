/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:01:00 by mabouce           #+#    #+#             */
/*   Updated: 2018/11/10 17:40:44 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*dest;

	dest = (char *)haystack;
	i = 0;
	if (needle[0] == '\0')
		return (dest);
	while (dest[i] && i < len)
	{
		j = 0;
		while (dest[i + j] == needle[j] && (i + j) < len)
		{
			j++;
			if (needle[j] == '\0')
				return (dest + i);
		}
		i++;
	}
	return (NULL);
}
