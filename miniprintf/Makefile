# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mabouce <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/29 17:41:15 by mabouce           #+#    #+#              #
#    Updated: 2019/04/30 18:15:54 by mabouce          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	libftminiprintf.a
SRCS_NAME		=	miniprintf.c			\
					ft_error_miniprintf.c	\
					ft_fill.c				\
					ft_csp.c				\
					ft_mod.c				\
					ft_diouxx.c				\
					ft_struct.c				\
					ft_width.c				\
					ft_accu.c				\

LIBFTINCLUDES	=	../libft/includes
LIBFT			=	../libft/
INCLUDES		=	./includes/
CC				=	gcc -Wall -Wextra -Werror
.PHONY			=	all $(NAME) $(OBJ) clean fclean re

SRCS_PATH		=	./srcs/

OBJS_PATH		=	./objs/

SRCS			=	$(addprefix $(SRCS_PATH), $(SRCS_NAME))

OBJS			=	$(patsubst $(SRCS_PATH)%.c, $(OBJS_PATH)%.o, $(SRCS))

_UNDER=$'\x1b[4m$'
_GREEN=$'\x1b[32m$'
_YELLOW=$'\x1b[33m$'
_WHITE=$'\x1b[37m$'
_END=$'\x1b[0m$'
_BOLD=$'\x1b[1m$'

all:	$(NAME)

$(NAME): $(OBJS)
	@echo "\n\n"
	@echo "$(_WHITE)====================================================$(_END)"
	@echo "$(_YELLOW)		COMPILING LIBFT$(_END)"
	@echo "$(_WHITE)====================================================$(_END)"
	@echo "\n\n"
	@make -C $(LIBFT) -j
	@cp $(LIBFT)/libft.a $(NAME)
	@ar rcs $(NAME) $(OBJS)
	@echo "\n$(_WHITE)$(NAME)\t$(_GREEN)[OK]$(_END)\n"

clean:
	rm -rf objs
	make clean -C $(LIBFT)

fclean:	clean
	rm -f $(NAME)
	make fclean -C $(LIBFT)

re:	fclean all

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	@mkdir -p objs
	@$(CC) -I $(LIBFTINCLUDES) -I $(INCLUDES) -c $< -o $@
	@echo "$(_END)$(_GREEN)[OK]\t$(_UNDER)$(_YELLOW)	\
	COMPILE :$(_END)$(_BOLD)$(_WHITE)\t$<"
