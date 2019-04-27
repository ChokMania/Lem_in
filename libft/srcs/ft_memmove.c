/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 14:12:10 by mabouce           #+#    #+#             */
/*   Updated: 2018/11/08 12:12:40 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*tmp_dest;
	unsigned char	*tmp_src;
	size_t			i;

	tmp_dest = (unsigned char *)dst;
	tmp_src = (unsigned char *)src;
	i = 0;
	if (dst > src)
		while (i < len)
		{
			tmp_dest[len - i - 1] = tmp_src[len - i - 1];
			i++;
		}
	else
		while (i < len)
		{
			tmp_dest[i] = tmp_src[i];
			i++;
		}
	return (tmp_dest);
}
