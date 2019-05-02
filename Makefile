# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: judumay <judumay@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/29 17:41:33 by mabouce           #+#    #+#              #
#    Updated: 2019/05/02 17:12:32 by judumay          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1				=	lem_in

SANITIZE			=	yes
WEVERYTHING			=	no

ifeq ($(SANITIZE),yes)
	CC				=	gcc -Wall -Wextra -Werror -fsanitize=address \
						-Wall -Wextra -Werror -O2
else ifeq ($(WEVERYTHING),yes)
	CC				=	gcc -Wall -Wextra -Weverything -O2
else
	CC				=	gcc -Wall -Wextra -Werror -O2
endif

SRCS_NAME			=	lem_in.c					\
					ft_struct.c						\
					ft_error.c						\
					ft_is.c							\
					ft_room.c						\
					ft_pipe.c						\
					ft_matrice.c					\
					ft_print_matrice.c				\
					ft_flags.c						\
					ft_set_paths.c					\
					ft_list_functions.c				\
					ft_recursively_find_best_way.c	\
					ft_print_path.c					\
					ft_utils.c						\

INCLUDES_NAME			=	lem_in.h

SRCS_PATH			=	./srcs/
INCLUDES_PATH			=	./includes/

OBJS_PATH 			=	./objs/

MINIPRINTF			=	./miniprintf/
LIBFTINCLUDES			=	./libft/includes/
MINIPRINTFINCLUDES		=	./miniprintf/includes/
INCLUDES  			=	$(addprefix $(INCLUDES_PATH), $(INCLUDES_NAME))

SRCS				=	$(addprefix $(SRCS_PATH), $(SRCS_NAME))

OBJS			=	$(patsubst $(SRCS_PATH)%.c, $(OBJS_PATH)%.o, $(SRCS))

.PHONY				:	all $(NAME1) clean fclean re

_UNDER=$'\x1b[4m$'
_GREEN=$'\x1b[32m$'
_YELLOW=$'\x1b[33m$'
_WHITE=$'\x1b[37m$'
_END=$'\x1b[0m$'
_BOLD=$'\x1b[1m$'

all: $(NAME1)


$(NAME1): $(OBJS)
	@echo "\n\n"
	@echo "$(_WHITE)====================================================$(_END)"
	@echo "$(_YELLOW)		COMPILING MINIPRINTF$(_END)"
	@echo "$(_WHITE)====================================================$(_END)"
	@echo "\n\n"
	@make -sC $(MINIPRINTF) -j
	@cp $(MINIPRINTF)/libftminiprintf.a .
	@echo "$(_WHITE)====================================================$(_END)"
	@echo "$(_YELLOW)		COMPILING LEM_IN$(_END)"
	@echo "$(_WHITE)====================================================$(_END)"
	@$(CC) -o $(NAME1) $(OBJS) libftminiprintf.a
	@echo "\n$(_WHITE)$(_BOLD)$@\t$(_END)$(_GREEN)[OK]\n$(_END)"
ifeq ($(SANITIZE),yes)
	@echo "Génération en mode sanitize"
else ifeq ($(WEVERYTHING),yes)
	@echo "Génération en mode weverything"
else
	@echo "Génération en mode release"
endif

clean:
	@echo "$(_RED)"
	rm -rf $(OBJS)
	make clean -C $(MINIPRINTF)
	rm -rf ./objs

fclean:	clean
	@echo "$(_YELLOW)"
	rm -f $(NAME1)
	rm -f libftminiprintf.a
	make fclean -C $(MINIPRINTF)

re:	fclean all

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c $(INCLUDES)
	@mkdir -p ./objs/
	@$(CC) -I $(MINIPRINTFINCLUDES) -I $(LIBFTINCLUDES) \
		-I $(INCLUDES_PATH) -c $< -o $@
	@echo "$(_END)$(_GREEN)[OK]\t$(_UNDER)$(_YELLOW)	\
		COMPILE :$(_END)$(_BOLD)$(_WHITE)\t$<"
