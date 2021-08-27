
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

SRC_DIR		=	./srcs/
OBJ_DIR		=	./objs/

DIR_HKF		=	hk_func/
DIR_UTL		=	utility/
DIR_SBJ		=	subject/
DIR_BNS		=	bns/

SBJ_OBJ_LST	=	push_swap.o				\
				check_input.o			\
				make_stack.o			\
				merge_to_a.o			\
				merge_to_b.o			\
				optimize_command.o		\
				sort_check_status.o		\
				sort_utils.o			\
				sort.o

HKF_OBJ_LST	=	ft_absol.o				\
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
				get_next_line_utils.o

UTL_OBJ_LST	=	error.o					\
				list.o					\
				list_cmd.o				\
				cmd_utils.o				\
				command1.o				\
				command2.o				\
				command3.o				\
				ft_utils.o

SBJ_OBJS	=	$(addprefix $(OBJ_DIR), $(SBJ_OBJ_LST))
HKF_OBJS	=	$(addprefix $(OBJ_DIR), $(HKF_OBJ_LST))
UTL_OBJS	=	$(addprefix $(OBJ_DIR), $(UTL_OBJ_LST))

BNS_OBJ_LST	=	checker.o				\
				cmd_bonus.o				\
				command1_bonus.o		\
				command2_bonus.o		\
				command3_bonus.o		\
				check_input.o			\
				make_stack.o			\
				sort_check_status.o

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

$(NAME)			:	$(SBJ_OBJS) $(UTL_OBJS) $(HKF_OBJS)
					@echo $(GREEN) "Source files are compiled!\n" $(EOC)
					@echo $(WHITE) "Building [$@] for" $(YELLOW) "Mandatory" $(WHITE) "..." $(EOC)
					@$(CC) $(CFLAGS) $(CDEBUG) -I$(INC) -o $@ $^
					@echo $(CYAN) "[$@] is created!\n" $(EOC)

$(BNS_NAME)		:	$(BNS_OBJS) $(UTL_OBJS) $(HKF_OBJS)
					@echo $(GREEN) "Bonus source files are compiled!\n" $(EOC)
					@echo $(WHITE) "Building [$@] for" $(YELLOW) "BONUS" $(WHITE) "..." $(EOC)
					@$(CC) $(CFLAGS) $(CDEBUG) -I$(INC) -o $@ $^
					@echo $(CYAN) "[$@] is created!\n" $(EOC)

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
					@$(RM) $(BNS_NAME)
					@echo $(RED) "Execute file is removed!\n" $(EOC)

re				:	fclean all

dir				:
					mkdir -p $(OBJ_DIR)

.PHONY			:	all bonus clean fclean re dir
