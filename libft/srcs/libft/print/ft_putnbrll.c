/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrll.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 13:38:40 by judumay           #+#    #+#             */
/*   Updated: 2019/05/24 14:35:04 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_putnbrll(long long n)
{
	unsigned long long	nb;

	if (n < 0)
	{
		nb = -n;
		ft_putchar('-');
	}
	else
		nb = n;
	if (nb >= 10)
		ft_putnbrll(nb / 10);
	ft_putchar(nb % 10 + 48);
}
