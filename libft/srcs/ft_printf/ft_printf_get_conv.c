/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_get_conv.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 17:59:22 by judumay           #+#    #+#             */
/*   Updated: 2019/03/11 17:59:25 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftprintf.h>

static void		ft_pritnf_get_conv2(t_printf *p, const char *format)
{
	if (format[p->index] == 's')
		p->conv = FT_PRINTF_S;
	else if (format[p->index] == 'u')
		p->conv = FT_PRINTF_U;
	else if (format[p->index] == 'x')
		p->conv = FT_PRINTF_X;
	else if (format[p->index] == 'X')
		p->conv = FT_PRINTF_XX;
	else if (format[p->index] == 'f')
		p->conv = FT_PRINTF_F;
	else if (format[p->index] == '%')
		p->conv = FT_PRINTF_PERCENT;
	else
		p->conv = NO_INPUT;
}

void			ft_printf_get_conv(t_printf *p, const char *format)
{
	if (format[p->index] == 'c')
		p->conv = FT_PRINTF_C;
	else if (format[p->index] == 'd' || format[p->index] == 'i')
		p->conv = FT_PRINTF_D;
	else if (format[p->index] == 'o')
		p->conv = FT_PRINTF_O;
	else if (format[p->index] == 'p')
		p->conv = FT_PRINTF_P;
	else
		ft_pritnf_get_conv2(p, format);
}
