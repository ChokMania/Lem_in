/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_stack_elem.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 16:06:38 by mabouce           #+#    #+#             */
/*   Updated: 2019/01/24 13:37:39 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_stack		*ft_create_stack_elem(int nbr)
{
	t_stack *new;

	if (!(new = malloc(sizeof(t_stack))))
		return (NULL);
	new->next = NULL;
	new->nbr = nbr;
	return (new);
}
