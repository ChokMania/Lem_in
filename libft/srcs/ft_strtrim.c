/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 15:49:02 by mabouce           #+#    #+#             */
/*   Updated: 2019/03/03 16:59:49 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	long long	i;
	long long	max;
	char		*result;

	if (s)
	{
		i = 0;
		max = ft_strlen(s) - 1;
		while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i])
			i++;
		while ((s[max] == ' ' || s[max] == '\n'
					|| s[max] == '\t') && max >= 0)
			max--;
		if (i > max + 1)
			return (ft_strnew(0));
		if (!(result = ft_strsub(s, i, max - i + 1)))
			return (NULL);
		else
			return (result);
	}
	return (NULL);
}
