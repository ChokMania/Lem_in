/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoind.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 13:49:37 by judumay           #+#    #+#             */
/*   Updated: 2019/05/24 14:35:04 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoind(char const *s1, char *s2)
{
	char	*str;

	if (s2)
	{
		if (!(str = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
			exit(0);
		ft_strcat(str, s1);
		ft_strcat(str, s2);
		ft_strdel(&s2);
		return (str);
	}
	return (NULL);
}
