/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_absolute_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 15:38:13 by mabouce           #+#    #+#             */
/*   Updated: 2019/02/16 15:38:32 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_absolute_value(int i)
{
	unsigned int result;

	if (i < 0)
		result = -i;
	else
		result = i;
	return (result);
}
