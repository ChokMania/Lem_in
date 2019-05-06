/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 16:00:14 by mabouce           #+#    #+#             */
/*   Updated: 2019/05/06 08:37:45 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>

typedef struct		s_list
{
	void			*content;
	void			*data;
	int				i;
	int				common;
	int				*tab;
	int				**ttab;
	int				finished;
	size_t			content_size;
	struct s_list	*next;
	struct s_list	*biggest;
}					t_list;

typedef struct		s_gnl
{
	char			*str;
	int				fd;
}					t_gnl;

typedef struct		s_btree
{
	struct s_btree	*left;
	struct s_btree	*right;
	void			*content;
}					t_btree;

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack, const char *needle,
					size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
long long			ft_atolli(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
unsigned int		ft_absolute_value(int i);
void				*ft_memalloc(size_t size);
void				ft_memdel(void	**ap);
int					ft_strisnum(char *str);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strtabdel(char ***tab);
void				ft_inttabdel(int ***tab, int len);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strdjoin(char *s1, char const *s2);
char				*ft_strjoind(char const *s1, char *s2);
char				*ft_strdjoind(char *s1, char *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_lltoa(long long n);
void				ft_putchar(char c);
void				ft_putstr(char const *str);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putnbrll(long long n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *str, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);

t_list				*ft_create_elem(void *data);
t_list				*ft_create_elem_int(int i);
int					ft_list_push_back(t_list **begin_list, void *data);
int					ft_list_push_back_int(t_list **begin_list, int i);
int					ft_list_push_front(t_list **begin_list, void *data);
int					ft_list_push_front_int(t_list **begin_list, int i);
int					ft_list_size(t_list *begin_list);
void				ft_list_print_int(t_list *begin_list);
void				ft_list_print_str(t_list *begin_list);
t_list				*ft_list_last(t_list *begin_list);
void				ft_list_remove_last_int(t_list **begin_list);
void				ft_list_remove_last_data(t_list **begin_list);
void				ft_list_remove_middle_int(t_list **begin_list
					, t_list *elem);
void				ft_list_remove_middle_data(t_list **begin_list
					, t_list *elem);
void				ft_list_remove_first_int(t_list **begin_list);
void				ft_list_remove_first_data(t_list **begin_list);
t_list				*ft_list_push_params(int ac, char **av);
void				ft_list_clear(t_list **begin_list);
void				ft_list_clear_data(t_list **begin_list);
t_list				*ft_list_at(t_list *begin_list, unsigned int nbr);
void				ft_list_reverse(t_list **begin_list);
void				ft_list_foreach(t_list *begin_list, void (*f)(void *));

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_list_foreach_if(t_list *begin_list, void (*f)(void *),
					void *data_ref, int (*cmp)());
t_list				*ft_list_find(t_list *begin_list, void *data_ref,
					int (*cmp)());

void				ft_print_tab_char(char **tab);
void				ft_print_tab_int(int *tab, int size);
void				ft_print_tab_tab_int(int **tab, int len, int size);
char				*ft_strdupd(char *s);
void				ft_swap(char *a, char *b);
int					ft_power(int nb, int power);
void				ft_strrev(char **src);
int					ft_isblank(int c);
int					ft_max(int a, int b);

t_btree				*btree_create_node(void *content);
void				btree_apply_prefix(t_btree *root, void (*applyf)(void *));
void				btree_apply_suffix(t_btree *root, void (*applyf)(void *));
void				btree_apply_infix(t_btree *root, void (*applyf)(void *));
void				btree_insert_data(t_btree **root, void *content,
					int (*cmpf)(void *, void *));
int					btree_lvl_count(t_btree *root);
void				btree_print(t_btree *root);

int					get_next_line(const int fd, char **line);

void				*ft_unstack(t_list *list);

#endif
