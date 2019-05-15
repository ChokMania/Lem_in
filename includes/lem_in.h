/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 09:41:37 by mabouce           #+#    #+#             */
/*   Updated: 2019/05/15 18:17:35 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "miniprintf.h"

typedef struct		s_room
{
	char			*name;

	long long		x;
	long long		y;
	long long		poid;
	int				startpos;
	struct s_room	*next;
}					t_room;

typedef struct		s_struct
{
	int				i;
	int				j;
	int				k;
	int				p;
	int				algo;
	int				ret;
	int				ac;
	long long		nbant;
	long long		maxway;
	long long		maxwaytwo;
	int				nbantset;
	int				commandstart;
	int				commandend;
	int				startset;
	int				endset;
	int				settingpipe;
	int				oneroomisset;
	int				onepipeisset;
	int				flag_c;
	int				flag_m;
	int				flag_n;
	int				st_pos;
	int				end_pos;
	int				conflit;
	int				tmpconflit;
	int				liaisons;
	int				*tab;
	int				*tb;
	int				max_weight;
	long long		totalroom;
	int				bfs_first;

	int				**matrice;
	int				**ants_in_way;
	int				**weight;

	char			**namematrice;
	char			**av;
	char			**color;

	char			*str;

	t_list			*input;
	t_list			*comment;
	t_list			*command;
	t_list			*ways;
	t_list			*finalways;
	t_list			*first;
	t_room			*room;
}					t_s;

void				ft_error(t_s *s, int error);

int					ft_read_input(t_s *s);

void				ft_clear_struct(t_s *s);
int					ft_set_struct(t_s *s);

int					ft_is_comment(t_s *s);
int					ft_is_command(t_s *s);
int					ft_check_name_room(t_s *s, char *name);
int					ft_is_room(t_s *s);
int					ft_is_pipe(t_s *s);

t_room				*ft_create_room(char *name, long long x
					, long long y, int startpos);
int					ft_push_room(t_s *s);
int					ft_push_room_suite(t_s *s, char **room
					, char *name, int startpos);
int					ft_push_front_room(t_room **room
					, char *name, long long tab[2]
					, int startpos);
void				ft_room_print(t_room *room);
void				ft_room_clear(t_room **room);

int					ft_push_pipe(t_s *s);

int					ft_matrice(t_s *s, char *name1
					, char *name2);
long long			ft_total_room(t_room *room);
int					ft_create_name_matrice(t_s *s);
int					ft_set_matrice_laplacienne(t_s *s);
int					ft_make_matrice(t_s *s, char *name1
					, char *name2);

void				ft_print_matrice(t_s *s);

void				ft_set_flags(t_s *s);
void				ft_apply_flag(t_s *s);

int					ft_set_paths_start(t_s *s);
int					ft_check_prev(t_list *beg, int i, int j);
long long			ft_set_maxway(t_s *s);
int					ft_set_paths(t_s *s);
int					ft_duplicate_ways_push(t_s *s, t_list *beg, int currentmove
					, int j);

int					ft_ways_push_front(t_s *s, t_list **begin_list, int i);
int					ft_way_is_in_conflict(t_s *s, t_list *first
					, t_list *second);
int					ft_ways_push_front(t_s *s, t_list **begin_list, int i);
int					ft_list_copy(t_s *s, t_list **begin_list, t_list *copy);
t_list				*ft_create_elem_tab_final_way(t_s *s, t_list *copy
					, int **tab);

int					ft_check_previous_conflict(t_s *s, int *tab, int j);
int					ft_recursively_best_way(t_s *s, t_list *beg, int j, int p);

int					ft_best_ways_found(t_s *s);
int					ft_print_path(t_s *s);
int					ft_lenint(int *tab, t_s *s);

void				ft_list_remove_last_data_finalways(t_list **begin_list);
void				ft_list_remove_first_data_finalways(t_list **begin_list);
void				ft_list_remove_middle_data_finalways(t_s *s
					, t_list **begin_list, t_list *elem);
void				ft_del_useless_list_elem(t_s *s);

int					ft_color(t_s *s);
void				ft_list_clear_tab(t_list **begin_list);
void				ft_list_clear_tab_int(t_list **begin_list);
void				ft_error_two(t_s *s, int error);
void				ft_error_one(t_s *s, int error);

void				ft_calcul_nb_pipes(t_s *s);
int					ft_detect_room_or_pipe(t_s *s);
int					ft_detect_line_type(t_s *s);

int					ft_ways_push_front_two(t_s *s, t_list **begin_list
					, int *tab);
t_list				*ft_create_elem_tab_way_two(t_s *s, int *tab);

int					ft_parse_queue(int *tab);
void				ft_reset_weight(t_s *s);
int					ft_choose_the_one(int u, t_s *s);
int					*ft_intdup(int *i1, int len);
t_list				*ft_sort_list(t_list *lst, t_s *s);

void				ft_reverse_final(t_s *s);
void				ft_is_worth(t_s *s, int i);
int					ft_set_paths_start_two(t_s *s);

int					ft_algo_two(t_s *s);

void				ft_print_path_suite(t_s *s, int number_ants, int **tab);

void				ft_clean_tab_tab(int **tab, int len1);
void				ft_clean_tab(int *tab, int len);
void				ft_clean_tab_tab_token(int **tab, int len1);
void				ft_clean_not_first(int **tab, int len1);
void				ft_clear_tab_f(t_list **begin_list);

int					ft_first_bfs(t_s *s, int start, int *queue);
int					ft_choose_sous(t_s *s, int start, int *bloc);
void				ft_init_bfs(t_s *s, int tab[5], int *queue, int start);
void				ft_push_or_not(t_s *s, int *queue, int i, int start);
void				ft_make_start(t_s *s);
#endif
