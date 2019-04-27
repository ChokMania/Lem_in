/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 14:12:10 by mabouce           #+#    #+#             */
/*   Updated: 2018/11/12 10:02:14 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*tmp;
	unsigned char	*tmp_dest;
	unsigned int	i;

	tmp = (unsigned char *)src;
	tmp_dest = (unsigned char *)dst;
	i = 0;
	while (i < n)
	{
		tmp_dest[i] = tmp[i];
		i++;
	}
	return (dst);
}
