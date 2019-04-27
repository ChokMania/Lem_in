/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 17:10:04 by mabouce           #+#    #+#             */
/*   Updated: 2018/11/08 17:18:37 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char		*dest;
	long long	i;

	if (s)
	{
		i = ft_strlen(s) + 1;
		if (!(dest = (char *)malloc(sizeof(char) * i)))
			return (NULL);
		i = 0;
		while (s[i])
		{
			dest[i] = f(s[i]);
			i++;
		}
		dest[i] = '\0';
		return (dest);
	}
	else
		return (NULL);
}
