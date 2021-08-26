
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
BNS_NAME	=	checker

INC			=	./includes
DIR_HKF		=	hk_func/
DIR_UTL		=	utility/
DIR_SBJ		=	subject/
DIR_BNS		=	bns/

SRC_DIR		=	./srcs/

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

# BNS_LIST	=	$(DIR_BNS)checker.c
# 				$(DIR_BNS)command1_bonus.c
# 				$(DIR_BNS)command2_bonus.c
# 				$(DIR_BNS)command3_bonus.c
# BNS_SRCS	=	$(addprefix $(SRC_DIR), $(BNS_LIST))

BNS_OBJ_LST	=	checker.o				\
				command1_bonus.o		\
				command2_bonus.o		\
				command3_bonus.o		\
				sort_check_status.o		\
				check_input.o			\
				make_stack.o			\
				list.o					\
				list_cmd.o				\
				ft_utils.o				\
				error.o					\
				get_next_line.o			\
				get_next_line_utils.o	\
				ft_absol.o				\
				ft_isdigit.o			\
				ft_memset.o				\
				ft_putendl.o			\
				ft_putstr.o				\
				ft_strcmp.o				\
				ft_strchr.o				\
				ft_strlen.o
BNS_OBJS	=	$(addprefix $(OBJ_DIR), $(BNS_OBJ_LST))

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

$(OBJ_DIR)%.o	:	$(SRC_DIR)$(DIR_BNS)%.c dir
					@$(CC) $(CFLAGS) $(CDEBUG) -I$(INC) -c $< -o $@
					@echo $(YELLOW) "Compiling...\t" $< $(EOC) $(LINE_CLEAR)

$(NAME)			:	$(OBJS)
					@echo $(GREEN) "Source files are compiled!\n" $(EOC)
					@echo $(WHITE) "Building '$@' for" $(YELLOW) "Mandatory" $(WHITE) "..." $(EOC)
					@$(CC) $(CFLAGS) $(CDEBUG) -I$(INC) -o $@ $^
					@echo $(CYAN) "'$@'(execute file) is created!\n" $(EOC)

$(BNS_NAME)		:	$(BNS_OBJS)
					@echo $(CYAN) "Bonus source files are compiled!\n" $(EOC)
					@echo $(WHITE) "Building '$@' for" $(YELLOW) "BONUS" $(WHITE) "..." $(EOC)
					@$(CC) $(CFLAGS) $(CDEBUG) -I$(INC) -o $(BNS_NAME) $^
					@echo $(CYAN) "'$(BNS_NAME)'(execute file) is created!\n" $(EOC)

# =============================================================================
# Rule
# =============================================================================

all				:	$(NAME)

bonus			:	$(BNS_NAME)

clean			:
					@$(RM) $(OBJ_DIR)
					@echo $(RED) "Object files are cleaned!\n" $(EOC)

fclean			:	clean
					@$(RM) $(NAME)
					@echo $(RED) "Execute file is removed!\n" $(EOC)

re				:	fclean all

dir				:
					mkdir -p $(OBJ_DIR)

.PHONY			:	all bonus clean fclean re dir
