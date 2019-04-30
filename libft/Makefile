# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mabouce <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 14:11:45 by mabouce           #+#    #+#              #
#    Updated: 2019/04/30 18:15:59 by mabouce          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libft.a
CC =	gcc -Wall -Wextra -Werror
SRCS_NAME	=	ft_memset.c			\
				ft_bzero.c			\
				ft_memcpy.c			\
				ft_memccpy.c		\
				ft_memmove.c		\
				ft_memchr.c			\
				ft_memcmp.c			\
				ft_strlen.c			\
				ft_strdup.c			\
				ft_strdupd.c		\
				ft_strcpy.c			\
				ft_strncpy.c		\
				ft_strcat.c			\
				ft_strncat.c		\
				ft_strlcat.c		\
				ft_strchr.c			\
				ft_strrchr.c		\
				ft_strstr.c			\
				ft_strnstr.c		\
				ft_strcmp.c			\
				ft_strncmp.c		\
				ft_atoi.c			\
				ft_atolli.c			\
				ft_isalpha.c		\
				ft_isdigit.c		\
				ft_isalnum.c		\
				ft_isascii.c		\
				ft_isprint.c		\
				ft_toupper.c		\
				ft_tolower.c		\
				ft_absolute_value.c	\
									\
				ft_memalloc.c	\
				ft_memdel.c		\
				ft_strisnum.c		\
				ft_strnew.c		\
				ft_strdel.c		\
				ft_strtabdel.c	\
				ft_inttabdel.c	\
				ft_strclr.c		\
				ft_striter.c	\
				ft_striteri.c	\
				ft_strmap.c		\
				ft_strmapi.c	\
				ft_strequ.c		\
				ft_strnequ.c	\
				ft_strsub.c		\
				ft_strjoin.c	\
				ft_strdjoin.c	\
				ft_strdjoind.c	\
				ft_strjoind.c	\
				ft_strtrim.c	\
				ft_strsplit.c	\
				ft_itoa.c		\
				ft_lltoa.c		\
				ft_putchar.c	\
				ft_putstr.c		\
				ft_putnbr.c		\
				ft_putnbrll.c		\
				ft_putendl.c	\
				ft_putchar_fd.c	\
				ft_putstr_fd.c	\
				ft_putendl_fd.c	\
				ft_putnbr_fd.c	\
				ft_max.c		\
								\
				ft_create_elem.c			\
				ft_create_elem_int.c		\
				ft_list_push_back.c			\
				ft_list_push_back_int.c		\
				ft_list_push_front.c		\
				ft_list_push_front_int.c	\
				ft_list_size.c				\
				ft_list_last.c				\
				ft_list_remove_last.c		\
				ft_list_remove_first.c		\
				ft_list_remove_middle.c		\
				ft_list_push_params.c		\
				ft_list_clear.c				\
				ft_list_clear_data.c		\
				ft_list_at.c				\
				ft_list_reverse.c			\
				ft_list_foreach.c			\
				ft_list_print.c				\
											\
				ft_lstnew.c		\
				ft_lstdelone.c	\
				ft_lstdel.c		\
				ft_lstadd.c		\
				ft_lstiter.c	\
				ft_lstmap.c		\
								\
				ft_print_tab_char.c	\
				ft_print_tab_int.c	\
				ft_print_tab_tab_int.c	\
				ft_swap.c			\
				ft_power.c			\
				ft_strrev.c			\
				ft_isblank.c		\
				btree_apply_infix.c	\
				btree_apply_prefix.c\
				btree_apply_suffix.c\
				btree_create_node.c	\
				btree_lvl_count.c	\
				btree_insert_data.c	\
				btree_int_cmp.c		\
				btree_print.c		\
									\
				get_next_line.c	\
								\
				ft_unstack.c\

SRCS_PATH	=	./srcs/

OBJS_PATH	=	./objs/

SRCS		=	$(addprefix $(SRCS_PATH), $(SRCS_NAME))

OBJS		=	$(patsubst $(SRCS_PATH)%c, $(OBJS_PATH)%o, $(SRCS))

.PHONY		:	all clean fclean re

INCLUDES	=	./includes/
	
_BOLD=$'\x1b[1m$'
_UNDER=$'\x1b[4m$'
_GREY=$'\x1b[30m$'
_RED=$'\x1b[31m$'
_GREEN=$'\x1b[32m$'
_YELLOW=$'\x1b[33m$'
_BLUE=$'\x1b[34m$'
_PURPLE=$'\x1b[35m$'
_CYAN=$'\x1b[36m$'
_WHITE=$'\x1b[37m$'
_END=$'\x1b[0m$'
_REV=$'\x1b[7m$'

all:	$(NAME)

$(NAME): $(OBJS) 
	@ar rcs $(NAME) $(OBJS)

clean:
	@echo "$(_RED)"
	rm -rf objs

fclean: clean
	@echo "$(_YELLOW)"
	/bin/rm -f $(NAME)

re: fclean all

$(OBJS_PATH)%.o : $(SRCS_PATH)%.c
	@mkdir -p objs
	@$(CC) -I $(INCLUDES) -c $< -o $@
	@echo "$(_END)$(_GREEN)[OK]\t$(_UNDER)$(_YELLOW)	\
	COMPILE :$(_END)$(_BOLD)$(_WHITE)\t$<"
