/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 18:00:47 by judumay           #+#    #+#             */
/*   Updated: 2019/03/11 18:00:48 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftprintf.h>

int		ft_printf(char *format, ...)
{
	__int32_t	ret;
	t_printf	*p;

	p = NULL;
	ret = 0;
	if (!format || !(p = init_t_printf(p)))
		return (-1);
	va_start(p->ap, format);
	ft_printf_display(p, format);
	va_end(p->ap);
	ret = p->ret;
	if (p->error == 1)
		ret = -1;
	reset_t_printf(p);
	del_t_printf(p);
	return (ret);
}
