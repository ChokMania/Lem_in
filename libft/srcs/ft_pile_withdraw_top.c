/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_withdraw_top.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 13:28:34 by mabouce           #+#    #+#             */
/*   Updated: 2019/03/03 16:45:24 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_stack_withdraw_top(t_stack *stack)
{
	int		withdrawnbr;
	t_stack	*withdrawelem;

	if (stack == NULL)
		exit(0);
	withdrawnbr = 0;
	withdrawelem = stack->next;
	if (stack != NULL && stack->next != NULL)
	{
		withdrawnbr = withdrawelem->nbr;
		stack->next = withdrawelem->next;
		free(withdrawelem);
	}
	return (withdrawnbr);
}
