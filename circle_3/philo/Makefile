# =============================================================================
# Command Variables
# =============================================================================

CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra
CDEBUG		=	-g -fsanitize=address
RM			=	rm -rf

# =============================================================================
# File Variables
# =============================================================================

NAME		=	philo
INC			=	./include/
SRC_DIR		=	./srcs/
DIR_HFT		=	hk_function/
DIR_UTL		=	utility/
DIR_SBJ		=	subject/
SRC_LIST	=	$(DIR_SBJ)philo.c		\
				$(DIR_SBJ)routine.c		\
				$(DIR_SBJ)lifetime.c	\
				$(DIR_UTL)error.c		\
				$(DIR_UTL)message.c		\
				$(DIR_UTL)time.c		\
				$(DIR_HFT)ft_atoi.c		\
				$(DIR_HFT)ft_strlen.c	\
				$(DIR_HFT)ft_putnbr.c	\
				$(DIR_HFT)ft_putstr.c	\
				$(DIR_HFT)ft_putendl.c
SRCS		=	$(addprefix $(SRC_DIR), $(SRC_LIST))
OBJS_DIR	=	./objs
OBJ_LIST	=	philo.o		\
				routine.o	\
				lifetime.o	\
				error.o		\
				message.o	\
				time.o		\
				ft_atoi.o	\
				ft_strlen.o	\
				ft_putnbr.o	\
				ft_putstr.o	\
				ft_putendl.o
OBJS		=	$(addprefix $(OBJS_DIR)/, $(OBJ_LIST))

# =============================================================================
# Target Generating
# =============================================================================

$(OBJS_DIR)/%.o	:	$(SRC_DIR)$(DIR_SBJ)%c $(SRC_DIR)$(DIR_HFT)%c $(SRC_DIR)$(DIR_UTL)%c
					mkdir -p $(OBJS_DIR)
					$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

$(NAME)			:	$(OBJS)
					$(CC) $(CFLAGS) -I$(INC) -o $@ $^


# =============================================================================
# Rule
# =============================================================================

all		:	$(NAME)

clean	:
			$(RM) $(OBJS)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re
