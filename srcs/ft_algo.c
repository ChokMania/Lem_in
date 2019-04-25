#include lem_in.h
//sub 0
int start(t_s *s, t_room *t)
{
	//sub0 -> déterminer les plus courts chemins
	//creer un tableau avec les rooms et une valeur par defaut à -1 , et 0 pour start
	int     **tab;
	int k ;

	k = 0;
	if(!(tab = (int **)malloc(sizeof(int *) * (s->totalroom + 1))))
		return 0;

	while (k < s->totalroom )
	{
		tab[k] = t->name;
		//malloc une case
		if(!(tab = (int *)malloc(sizeof(int) * (2 + 1))))
			return (0);
		//donne à cette case la valeur -1 ou 0 si c'est le depart
		if(t->startpos == 1)
			tab[k][1]= 0;
		else
			tab[k][1] = -1;
		//elements deja parcour , 0 non , 1 oui
		tab[k][2] = 0;
		tab[k] [3] = '\0';
		t->next;
		k++;
	}

	//deuxeieme tableau avec les antecedents
	char     **ant;
	int f ;

	f = 0;
	if(!(tab = (char **)malloc(sizeof(char *) * (s->totalroom + 1))))
		return 0;

	while (f < s->totalroom )
	{
		ant[f] = t->name;
		//malloc une case
		if(!(tab = (char *)malloc(sizeof(char) * (1 + 1))))
			return (0);
		//donne à cette case la valeur -1 ou 0 si c'est le depart
			tab[k][1]= NULL;
		//elements deja parcour , 0 non , 1 oui
		ant[f] [2] = '\0';
		t->next;
		f++;
	}

	//deuxieme partie calcul djikstra
	

}

//on parcour en boucle le tableau pour verifier si le poid 
//le plus faible correspond à celui d'arriver
int ft_end(t_s *s, t_room *t, int **tab, char **ant)
{
	//noeud d'arrivé
	char ndend = ;
	char ndfaible = NULL;

	while(tab[i])
	{
		if (tab[i][1] < tab[i + 1][1])
			{
				//
			}
	}
}

int ft_djikstra(t_s *s, t_room *t, int **tab, char **ant)
{
	//il faut qu'on sauvegarde le chemin , on connait le chemin le plus court par le id mais il faut le sauvegarder , fin reflexion la dessus
	while(!ft_end(*s, *t, **tab, **ant))
	{
		//recuperation du noed 
		//recuperation du noeud fils
		//recuperqtiion du noeud pere
		char ndfils = ;
		char ndcourant = ;
		char ndpere = ;

		//pathfinding , algo basé sur celui d'openclassroom
	if((ant[ndfils]==null) && ((tab[ndpere][1] + 1 + < tab[ndfils][1]) || (tab[ndfils][1] == -1))
	{
		tab[ndfils][1] = tab[ndpere][1] + 1 ;
		ant[ndfils][1] = ndpere;
	}
	}
}

// il faut donc verifier les autrs hcemins pere du noeud d'arriver et regarder leur poid pour connaitre 
// les autres possibilités de chemins à prendre.

//sub1 choix des chemins à prendre en fonction du nombre de fourmis
//calcul basé sur le nombre de fourmis
// on divise par le nombre d'étapes le ombre de fourmis presentent , 
//si 2 noeud parents sont plus rapide car division par 2 du temps , donc calcul pour x noeud parents diviser par x noeuds 
//parents est < au noeud fils pour le resultat on privilegiera ces chemins

//gestion des conflits : 
