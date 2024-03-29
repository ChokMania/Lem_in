/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 13:30:28 by judumay           #+#    #+#             */
/*   Updated: 2019/05/24 14:35:04 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_print_int(t_list *begin_list)
{
	if (begin_list == NULL)
		return ;
	while (begin_list != NULL)
	{
		ft_putnbr((long long)begin_list->data);
		ft_putchar('\n');
		begin_list = begin_list->next;
	}
}

void	ft_list_print_str(t_list *begin_list)
{
	if (begin_list == NULL)
		return ;
	while (begin_list != NULL)
	{
		ft_putstr((char *)begin_list->data);
		ft_putchar('\n');
		begin_list = begin_list->next;
	}
}
