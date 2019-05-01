/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 09:41:37 by mabouce           #+#    #+#             */
/*   Updated: 2019/05/01 17:03:20 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "miniprintf.h"

typedef struct						s_room
{
	char							*name;

	long long						x;
	long long						y;
	long long						poid;
	int								startpos;
	struct s_room					*next;
}									t_room;

typedef struct						s_struct
{
	int								i;
	int								j;
	int								k;
	int								p;
	int								totalplays;
	int								ret;
	int								ac;
	long long						nbant;
	long long						maxway;
	long long						maxwaytwo;
	int								nbantset;
	int								commandstart;
	int								commandend;
	int								startset;
	int								endset;
	int								settingpipe;
	int								oneroomisset;
	int								onepipeisset;
	int								flag_c;
	int								flag_m;
	int								flag_n;
	int								start_pos;
	int								end_pos;
	int								*tab;
	long long						totalroom;

	int								**matrice;
	int								**weight;

	char							**namematrice;
	char							**av;

	char							*str;

	t_list							*input;
	t_list							*comment;
	t_list							*command;
	t_list							*ways;
	t_list							*finalways;
	t_room							*room;
}									t_s;

void								ft_error(t_s *s, int error);

int									ft_read_input(t_s *s);

void								ft_clear_struct(t_s *s);
int									ft_set_struct(t_s *s);

int									ft_is_comment(t_s *s);
int									ft_is_command(t_s *s);
int									ft_check_name_room(t_s *s, char *name);
int									ft_is_room(t_s *s);
int									ft_is_pipe(t_s *s);

t_room								*ft_create_room(char *name, long long x
									, long long y, int startpos);
int									ft_push_room(t_s *s);
int									ft_push_room_suite(t_s *s, char **room
									, char *name, int startpos);
int									ft_push_front_room(t_room **room
									, char *name, long long tab[2]
									, int startpos);
void								ft_room_print(t_room *room);
void								ft_room_clear(t_room **room);

int									ft_push_pipe(t_s *s);

int									ft_matrice(t_s *s, char *name1
									, char *name2);
long long							ft_total_room(t_room *room);
int									ft_create_name_matrice(t_s *s);
int									ft_set_matrice_laplacienne(t_s *s);
int									ft_make_matrice(t_s *s, char *name1
									, char *name2);

void								ft_print_matrice(t_s *s);

void								ft_set_flags(t_s *s);
void								ft_apply_flag(t_s *s);

int									ft_set_paths_start(t_s *s);
long long							ft_set_maxway(t_s *s);
int									ft_set_paths(t_s *s);

int									ft_ways_push_front(t_s *s, t_list **begin_list, int i);
int									ft_way_is_in_conflict(t_s *s, t_list *first, t_list *second);
t_list 								*ft_create_elem_tab_way(t_s *s, int i);
void								ft_list_print_int_remake(t_s *s);
t_list 								*ft_create_elem_tab_final_way(t_s *s, t_list *copy);
int									ft_list_copy(t_s *s, t_list **begin_list, t_list *copy);

int									ft_check_previous_conflict(t_s *s, int *tab, int j);
int									ft_recursively_find_best_way(t_s *s, t_list *beg, t_list *first, int j);

#endif
