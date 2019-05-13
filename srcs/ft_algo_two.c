/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 15:22:06 by judumay           #+#    #+#             */
/*   Updated: 2019/05/13 13:18:54 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
static void		ft_everything_push(t_s *s, int *tab, int t[5])
{
	while (t[0] > 0)
		tab[t[0]--] = -5;
	if (t[3] >= 0)
	{
		while (1)
		{
			if (t[2] == -5)
				break ;
			tab[t[0]++] = t[2];
			t[2] != s->end_pos ? s->weight[t[2]][0] = -1 : 0;
			t[2] = s->weight[t[2]][1];
		}
	}
	if (t[3] >= 0)
		if (!(ft_ways_push_front_two(s, &s->ways, tab)))
			ft_error(s, -7);
	t[2] = -1;
}

static void		ft_complete_bfs(t_s *s, int *tab, int t[5])
{
	while (t[2] != s->end_pos && ++t[4] < s->totalroom)
	{
		t[2] = -1;
		if (t[3] == s->end_pos)
		{
			t[2] = t[3];
			tab[++t[0]] = t[2];
			break ;
		}
		t[3] = ft_parse_queue(tab);
		if (t[3] < 0)
			continue ;
		while (++t[2] < s->totalroom)
			if (s->matrice[t[3]][t[2]] == 1 && t[3] != t[2]
				&& s->weight[t[2]][0] == -5 && t[2] != s->st_pos)
			{
				s->weight[t[2]][0] = s->weight[t[3]][0] + 1;
				s->weight[t[2]][1] = t[3];
				if (t[2] == s->end_pos)
					break ;
				tab[++t[0]] = t[2];
			}
		tab[t[4]] = -1;
	}
}

static int		ft_init(t_s *s, int t[5], int *tab, int k)
{
	t[0] = -1;
	while (++t[0] < s->totalroom)
		tab[t[0]] = -5;
	t[4] = -1;
	t[0] = 0;
	t[1] = k;
	t[2] = -1;
	tab[0] = t[1];
	t[3] = t[1];
	if (s->weight[t[1]][0] == -1)
		return (-1);
	s->weight[t[1]][0] = 0;
	s->weight[t[1]][1] = -5;
	return (1);
}

void			ft_first_while(t_s *s, int k, int save, int *tab)
{
	int	t[5];

	while (++save < s->totalroom)
	{
		k++;
		if (k == s->totalroom)
			k = 0;
		if (s->matrice[s->st_pos][k] == 1 && k != s->st_pos)
		{
			if (ft_init(s, t, tab, k) > 0)
			{
				ft_complete_bfs(s, tab, t);
				ft_everything_push(s, tab, t);
				while (++t[2] < s->totalroom)
				{
					if (s->weight[t[2]][0] != -1)
						s->weight[t[2]][0] = -5;
					s->weight[t[2]][1] = -5;
				}
			}
		}
	}
}


int				ft_algo_two(t_s *s)
{
	int *tab;
	int k;
	int u;

	if (!(tab = (int *)malloc(sizeof(int) * s->totalroom * s->totalroom)))
		ft_error(s, -6);
	u = 0;
	while (++u <= s->matrice[s->st_pos][s->st_pos])
	{
		k = ft_choose_the_one(u, s);
		ft_first_while(s, k, -1, tab);
		ft_reset_weight(s);
		ft_is_worth(s, -1);
		ft_list_clear_tab(&s->ways);
	}
	free(tab);
	return (1);
}*/

static	void	ft_clean_tab(int *tab, int len)
{
	int	i;

	i = -1;
	while (++i < len)
		tab[i] = -5;
}

static	int		ft_choose_sous(t_s *s, int start, int *bloc)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (++i < s->totalroom)
	{
		if (i == bloc[j])
			j++;
		else if (s->matrice[s->st_pos][i] == 1 && i != s->st_pos
			&& i != start)
			break ;
	}
	return (i);
}

static	void	ft_first_while(t_s *s, int start, int sous_bloquage, int *queue)
{
	int		save;

	save = -1;
	while (++save < s->totalroom)
	{
		k++;
		if (k == s->totalroom)
			k = 0;
		if (s->matrice[s->st_pos][k] == 1 && k != s->st_pos)
		{
			if (ft_init(s, t, tab, k) > 0)
			{
				ft_complete_bfs(s, tab, t);
				ft_everything_push(s, tab, t);
				while (++t[2] < s->totalroom)
				{
					if (s->weight[t[2]][0] != -1)
						s->weight[t[2]][0] = -5;
					s->weight[t[2]][1] = -5;
				}
			}
		}
	}
}

int				ft_algo_two(t_s *s)
{
	int		*queue;
	int		*bloc;
	int		bloquage;
	int		sous_bloquage;
	int		start;

	if (!(queue = (int *)malloc(sizeof(int) * s->totalroom * s->totalroom)))
		ft_error(s, -6);
	if (!(bloc = (int *)malloc(sizeof(int) * s->totalroom * s->totalroom)))
		ft_error(s, -6);
	bloquage = 0;
	while (++bloquage <= s->matrice[s->st_pos][s->st_pos])
	{
		ft_clean_tab(bloc, s->totalroom);
		start = ft_choose_the_one(bloquage, s);
		while (ft_lenint(bloc, s) + 1 < s->matrice[s->st_pos][s->st_pos])
		{
			sous_bloquage = ft_choose_sous(s, start, bloc);
			//ft_first_while(s, start, sous_bloquage, queue);
			bloc[ft_lenint(bloc, s)] = sous_bloquage;
		}
	}
	free(queue);
	free(bloc);
	exit(1);
}


/* le but ici est de faire :
	le but est de reproduire le meme bfs fait ci	dessus
	tout en rajoute en possibilites de tests
	la premiere boucle soccupe de la premiere colonne et le deuxieme while
	de la dexieme colonne , pour le reste on laisse faire le parsing de la matrice
	il faut maintenant ajouter le bfs + le push 
	le principe est le meme que ci dessus


exemple sur 4 salles relies a start

avant :
1 2 3 4

2 3 4 1

3 4 1 2

4 1 2 3

apres :
1 2 3 4
1 3 4 2
1 4 2 3

2 3 4 1
2 4 1 3
2 1 3 4

3 4 1 2
3 1 2 4
3 2 4 1

4 1 2 3
4 2 3 1
4 3 2 1
*/