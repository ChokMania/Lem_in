/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mod.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 16:01:21 by judumay           #+#    #+#             */
/*   Updated: 2019/05/24 14:35:04 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniprintf.h"

char	*ft_mod(t_ms *s)
{
	char *tmp;

	tmp = va_arg(s->va, char *);
	if (ft_strcmp(tmp, "UNDER") == 0)
		return (ft_strdup("\x1b[4m"));
	if (ft_strcmp(tmp, "END") == 0)
		return (ft_strdup("\x1b[0m"));
	if (ft_strcmp(tmp, "BOLD") == 0)
		return (ft_strdup("\x1b[1m"));
	if (ft_strcmp(tmp, "WHITE") == 0)
		return (ft_strdup("\x1b[37m"));
	if (ft_strcmp(tmp, "GREEN") == 0)
		return (ft_strdup("\x1b[32m"));
	if (ft_strcmp(tmp, "YELLOW") == 0)
		return (ft_strdup("\x1b[33m"));
	if (ft_strcmp(tmp, "RED") == 0)
		return (ft_strdup("\x1b[31m"));
	if (ft_strcmp(tmp, "BLUE") == 0)
		return (ft_strdup("\x1b[34m"));
	return (ft_strdup("%"));
}
