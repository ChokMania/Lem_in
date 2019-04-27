/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:50:43 by mabouce           #+#    #+#             */
/*   Updated: 2019/03/06 15:36:23 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_nbr_of_words(char const *s, char c)
{
	long long	i;
	int			b;
	int			nbwords;

	i = 0;
	b = 0;
	nbwords = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			if (b == 0)
				nbwords++;
			b = 1;
		}
		else
			b = 0;
		i++;
	}
	return (nbwords);
}

static char		**ft_strsplit_two(char const *s, char c)
{
	long long	i;
	long long	j;
	int			x;
	int			nbwords;
	char		**tab;

	nbwords = ft_nbr_of_words(s, c);
	if (!(tab = (char **)malloc(sizeof(char *) * (nbwords + 1))))
		return (NULL);
	i = 0;
	j = -1;
	while (++j < nbwords && s[i])
	{
		x = 0;
		while (s[i] == c && s[i])
			i++;
		while (s[i + x] != c && s[i + x])
			x++;
		tab[j] = ft_strsub(s, i, x);
		i = i + x;
	}
	tab[j] = NULL;
	return (tab);
}

char			**ft_strsplit(char const *s, char c)
{
	if (s)
		return (ft_strsplit_two(s, c));
	return (NULL);
}
