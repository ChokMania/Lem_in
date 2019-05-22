SHELL = sh

# Executable name, can be change
NAME = lem-in

#Visual
VISUAL				=	yes
VISUALNUM			=	2

#Compilation Modes. Default= -Wall -Wextra -Werror
SANITIZE			=	no
NOERROR				=	no
NOFLAG				=	yes

ifeq ($(SANITIZE),yes)
	CC				=	gcc -Wall -Wextra -Werror -fsanitize=address \
						-Wall -Wextra -Werror
else ifeq ($(WEVERYTHING),yes)
	CC				=	gcc -Wall -Wextra -Weverything
else
	CC				=	gcc -Wall -Wextra -Werror
endif

SRCS_NAME			=	lem_in.c					\
						ft_struct.c						\
						ft_error.c						\
						ft_is.c							\
						ft_room.c						\
						ft_matrice.c					\
						ft_print_matrice.c				\
						ft_flags_and_pipes.c			\
						ft_set_paths.c					\
						ft_print_path.c					\
						ft_utils.c						\
						ft_utils2.c						\
						ft_utils3.c						\
						ft_help_main.c					\
						ft_help_print_path.c

SRCS_PATH			=	./srcs/
INCLUDES_PATH		=	./includes/

OBJS_PATH 			=	./objs/

LIBFT				=	./libft/
LIBFTA				=	libft.a
LIBFTINCLUDES		=	./libft/includes/

INCLUDES_NAME		=	lem_in.h
INCLUDES  			=	$(addprefix $(INCLUDES_PATH), $(INCLUDES_NAME))

SRCS				=	$(addprefix $(SRCS_PATH), $(SRCS_NAME))

OBJS				=	$(patsubst $(SRCS_PATH)%.c, $(OBJS_PATH)%.o, $(SRCS))

.PHONY				:	all clean fclean re

# Text format
_DEF = $'\033[0m
_END = $'\033[0m
_GRAS = $'\033[1m
_SOUL = $'\033[4m
_CLIG = $'\033[5m
_SURL = $'\033[7m

# Colors
_BLACK = $'\033[30m
_RED = $'\033[31m
_GREEN = $'\033[32m
_YELLOW = $'\033[33m
_BLUE = $'\033[34m
_PURPLE = $'\033[35m
_CYAN = $'\033[36m
_GREY = $'\033[37m

# Background
_IBLACK = $'\033[40m
_IRED = $'\033[41m
_IGREEN = $'\033[42m
_IYELLOW = $'\033[43m
_IBLUE = $'\033[44m
_IPURPLE = $'\033[45m
_ICYAN = $'\033[46m
_IGREY = $'\033[47m

all: $(NAME)

$(LIBFT)/$(LIBFTA): 
	@make -C $(LIBFT) -j 100

$(NAME): $(LIBFT)/$(LIBFTA) $(INCLUDES) $(OBJS) 
	@echo "$(_WHITE)====================================================$(_END)"
	@echo "$(_YELLOW)		COMPILING $(NAME)$(_END)"
	@echo "$(_WHITE)====================================================$(_END)"
	@$(CC) -o $(NAME) $(OBJS) $(LIBFT)/$(LIBFTA)
	@echo "\n$(_WHITE)$(_BOLD)$@\t$(_END)$(_GREEN)[OK]\n$(_END)"
ifeq ($(SANITIZE),yes)
	@echo "Génération en mode sanitize"
else ifeq ($(NOERROR),yes)
	@echo "Génération en mode noerror"
else ifeq ($(NOFLAG),yes)
	@echo "Génération en mode noflag"
else
	@echo "Génération en mode release"
endif

clean: 
	@rm -rf $(OBJS_PATH) 2> /dev/null || true
ifeq ($(shell [[ $(VISUAL) == yes && $(VISUALNUM) == 2 ]] && echo true ), true)
	@echo "$(_YELLOW)Remove :\t$(_RED)" $(LDFLAGS)./objs/"$(_END)"
endif
	@make -C $(LIBFT) clean

fclean: clean
	@rm -f $(NAME) 
	@rm -f libft.a
	@rm -f ./libft/libft.a
ifeq ($(shell [[ $(VISUAL) == yes && $(VISUALNUM) == 2 ]] && echo true ), true)
	@echo "$(_YELLOW)Remove :\t$(_RED)" $(LDFLAGS)$(NAME)
	@echo "$(_YELLOW)Remove :\t$(_RED)" libft.a"$(_END)"
	@echo "$(_YELLOW)Remove :\t$(_RED)" ./libft/libft.a"$(_END)"
endif

re:	fclean all

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c $(INCLUDES)
	@mkdir -p ./objs/
	@$(CC) -I $(INCLUDES) -I $(LIBFTINCLUDES) \
		-I $(INCLUDES_PATH) -c $< -o $@
	@echo "$(_END)$(_GREEN)[OK]\t$(_UNDER)$(_YELLOW)	\
		COMPILE :$(_END)$(_BOLD)$(_WHITE)\t$<"
