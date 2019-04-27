/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 11:44:08 by mabouce           #+#    #+#             */
/*   Updated: 2018/11/11 13:35:06 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;
	size_t	dst_len;

	i = ft_strlen(dst);
	dst_len = i;
	src_len = ft_strlen(src);
	if (size < dst_len + 1)
		return (src_len + size);
	else
	{
		while (*src != '\0' && i < size - 1)
		{
			dst[i] = *src++;
			i++;
		}
		dst[i] = '\0';
	}
	return (dst_len + src_len);
}
