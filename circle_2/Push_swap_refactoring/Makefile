
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
# Command Variables -fsanitize=address
# =============================================================================

CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra
CDEBUG		=	-g
RM			=	rm -rf

# =============================================================================
# File Variables
# =============================================================================

NAME		=	push_swap

INC			=	./includes
DIR_HKF		=	hk_func/
DIR_UTL		=	utility/
DIR_SBJ		=	subject/

SRC_DIR		=	./srcs/
SRC_LIST	=	$(DIR_SBJ)push_swap.c			\
				$(DIR_SBJ)check_input.c			\
				$(DIR_SBJ)make_stack.c			\
				$(DIR_SBJ)merge_to_a.c			\
				$(DIR_SBJ)merge_to_b.c			\
				$(DIR_SBJ)sort.c				\
				$(DIR_SBJ)sort_utils.c			\
				$(DIR_SBJ)sort_check_status.c	\
				$(DIR_SBJ)optimize.c			\
				$(DIR_HKF)ft_absol.c			\
				$(DIR_HKF)ft_isdigit.c			\
				$(DIR_HKF)ft_memset.c			\
				$(DIR_HKF)ft_putendl.c			\
				$(DIR_HKF)ft_putstr.c			\
				$(DIR_HKF)ft_strchr.c			\
				$(DIR_HKF)ft_strcmp.c			\
				$(DIR_HKF)ft_strdup.c			\
				$(DIR_HKF)ft_strjoin.c			\
				$(DIR_HKF)ft_strlen.c			\
				$(DIR_HKF)get_next_line.c		\
				$(DIR_HKF)get_next_line_utils.c	\
				$(DIR_UTL)error.c				\
				$(DIR_UTL)list.c				\
				$(DIR_UTL)list_cmd.c			\
				$(DIR_UTL)command1.c			\
				$(DIR_UTL)command2.c			\
				$(DIR_UTL)command3.c			\
				$(DIR_UTL)ft_utils.c
SRCS		=	$(addprefix $(SRC_DIR), $(SRC_LIST))

OBJ_DIR		=	./objs/
OBJ_LIST	=	push_swap.o				\
				check_input.o			\
				make_stack.o			\
				merge_to_a.o			\
				merge_to_b.o			\
				sort.o					\
				sort_utils.o			\
				sort_check_status.o		\
				optimize.o				\
				ft_absol.o				\
				ft_isdigit.o			\
				ft_memset.o				\
				ft_putendl.o			\
				ft_putstr.o				\
				ft_strchr.o				\
				ft_strcmp.o				\
				ft_strdup.o				\
				ft_strjoin.o			\
				ft_strlen.o				\
				get_next_line.o			\
				get_next_line_utils.o	\
				error.o					\
				list.o					\
				list_cmd.o				\
				command1.o				\
				command2.o				\
				command3.o				\
				ft_utils.o
OBJS		=	$(addprefix $(OBJ_DIR), $(OBJ_LIST))

# =============================================================================
# Target Generating
# =============================================================================

$(OBJ_DIR)%.o	:	$(SRC_DIR)$(DIR_HKF)%.c	dir
					@$(CC) $(CFLAGS) $(CDEBUG) -I$(INC) -c $< -o $@
					@echo $(YELLOW) "Compiling...\t" $< $(EOC) $(LINE_CLEAR)

$(OBJ_DIR)%.o	:	$(SRC_DIR)$(DIR_UTL)%.c dir
					@$(CC) $(CFLAGS) $(CDEBUG) -I$(INC) -c $< -o $@
					@echo $(YELLOW) "Compiling...\t" $< $(EOC) $(LINE_CLEAR)

$(OBJ_DIR)%.o	:	$(SRC_DIR)$(DIR_SBJ)%.c dir
					@$(CC) $(CFLAGS) $(CDEBUG) -I$(INC) -c $< -o $@
					@echo $(YELLOW) "Compiling...\t" $< $(EOC) $(LINE_CLEAR)

$(NAME)			:	$(OBJS)
					@echo $(GREEN) "Source files are compiled!\n" $(EOC)
					@echo $(WHITE) "Building '$(NAME)' for" $(YELLOW) "Mandatory" $(WHITE) "..." $(EOC)
					@$(CC) $(CFLAGS) $(CDEBUG) -I$(INC) -o $@ $^
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

dir				:
					mkdir -p $(OBJ_DIR)

.PHONY			:	all clean fclean re dir
