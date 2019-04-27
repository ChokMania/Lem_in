/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:01:00 by mabouce           #+#    #+#             */
/*   Updated: 2018/11/08 14:13:56 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		j;
	char	*dest;

	dest = (char *)haystack;
	i = 0;
	if (needle[0] == '\0')
		return (dest);
	while (dest[i])
	{
		j = 0;
		while (dest[i + j] == needle[j])
		{
			j++;
			if (needle[j] == '\0')
				return (dest + i);
		}
		i++;
	}
	return (NULL);
}
