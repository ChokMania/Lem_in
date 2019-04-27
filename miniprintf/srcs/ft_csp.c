/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_csp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 16:00:43 by mabouce           #+#    #+#             */
/*   Updated: 2019/04/22 16:00:44 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniprintf.h"

char	*ft_char(t_ms *s)
{
	char	c;
	char	*tmp;

	if (!(tmp = ft_strnew(2)))
		return (NULL);
	c = va_arg(s->va, int);
	ft_memset((void *)tmp, c, 1);
	return (tmp);
}

char	*ft_string(t_ms *s)
{
	char	*tmp;

	if (!(tmp = ft_strdup(va_arg(s->va, char *))))
		return (NULL);
	return (tmp);
}
