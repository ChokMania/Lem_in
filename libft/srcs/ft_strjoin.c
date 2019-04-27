/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 15:41:37 by mabouce           #+#    #+#             */
/*   Updated: 2019/03/05 16:20:52 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	long long	size_s1;
	long long	size_s2;
	long long	i;
	char		*dest;

	if (s1 && s2)
	{
		i = 0;
		size_s1 = ft_strlen((char *)s1);
		size_s2 = ft_strlen((char *)s2);
		if (!(dest = (char *)malloc(sizeof(char) * (size_s1 + size_s2 + 1))))
			return (NULL);
		while (s1[i])
		{
			dest[i] = s1[i];
			i++;
		}
		dest[i] = '\0';
		ft_strcat(dest, s2);
		return (dest);
	}
	else
		return (NULL);
}
