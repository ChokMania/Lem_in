/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_push_in.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 16:10:41 by mabouce           #+#    #+#             */
/*   Updated: 2019/03/03 16:45:34 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_stack_push_top(t_stack *stack, int nbr)
{
	t_stack *new;

	new = ft_create_stack_elem(nbr);
	if (stack == NULL || new == NULL)
		exit(0);
	new->next = stack->next;
	stack->next = new;
}
