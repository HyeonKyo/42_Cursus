# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeonkyokim <hyeonkyokim@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/29 14:35:33 by hyeonkki          #+#    #+#              #
#    Updated: 2021/09/30 21:25:27 by hyeonkyokim      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# =============================================================================
# Color Variables
# =============================================================================

BLACK		= 	"\033[0;30m"
GRAY		= 	"\033[1;30m"
RED			=	"\033[1;31m"
GREEN		=	"\033[1;32m"
YELLOW		=	"\033[1;33m"
PURPLE		=	"\033[0;35m"
CYAN		=	"\033[1;36m"
WHITE		=	"\033[1;37m"
EOC			=	"\033[0;0m"
LINE_CLEAR	=	"\x1b[1A\x1b[M"

# =============================================================================
# Command Variables
# =============================================================================

CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra
RM			=	rm -rf

# =============================================================================
# File Variables
# =============================================================================

NAME		=	philo

INC			=	./include
DIR_HFT		=	hk_function/
DIR_UTL		=	utility/
DIR_SBJ		=	subject/

SRC_DIR		=	./srcs/
OBJ_DIR		=	./objs/

OBJ_LIST	=	philo.o			\
				routine.o		\
				lifetime.o		\
				error.o			\
				setup_dinning.o	\
				message.o		\
				print_state.o	\
				routine_utils.o	\
				time.o			\
				ft_atoi.o		\
				ft_strlen.o		\
				ft_putnbr.o		\
				ft_putstr.o		\
				ft_putendl.o
OBJS		=	$(addprefix $(OBJ_DIR), $(OBJ_LIST))

# =============================================================================
# Target Generating
# =============================================================================

$(OBJ_DIR)%.o	:	$(SRC_DIR)$(DIR_SBJ)%.c
					@mkdir -p $(OBJ_DIR)
					@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@
					@echo $(YELLOW) "Compiling...\t" $< $(EOC) $(LINE_CLEAR)

$(OBJ_DIR)%.o	:	$(SRC_DIR)$(DIR_HFT)%.c
					@mkdir -p $(OBJ_DIR)
					@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@
					@echo $(YELLOW) "Compiling...\t" $< $(EOC) $(LINE_CLEAR)

$(OBJ_DIR)%.o	:	$(SRC_DIR)$(DIR_UTL)%.c
					@mkdir -p $(OBJ_DIR)
					@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@
					@echo $(YELLOW) "Compiling...\t" $< $(EOC) $(LINE_CLEAR)

$(NAME)			:	$(OBJS)
					@echo $(GREEN) "Source files are compiled!\n" $(EOC)
					@echo $(WHITE) "Building '$(NAME)' for" $(YELLOW) "Mandatory" $(WHITE) "..." $(EOC)
					@$(CC) $(CFLAGS) -I$(INC) -o $@ $^
					@echo $(CYAN) "'$(NAME)'(execute file) is created!\n" $(EOC)

# =============================================================================
# Rule
# =============================================================================

all				:	$(NAME)

clean			:
					@$(RM) $(OBJ_DIR)
					@echo $(RED) "Object files are cleaned!\n" $(EOC)

fclean			:	clean
					@$(RM) $(NAME)
					@echo $(RED) "Execute file is removed!\n" $(EOC)

re				:	fclean all

.PHONY			:	all clean fclean re
