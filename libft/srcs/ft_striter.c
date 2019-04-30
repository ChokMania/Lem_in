/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:52:20 by mabouce           #+#    #+#             */
/*   Updated: 2018/11/11 14:37:53 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striter(char *s, void (*f)(char *))
{
	long long	i;

	i = 0;
	if (s && f)
		while (s[i])
		{
			f(&s[i]);
			i++;
		}
}