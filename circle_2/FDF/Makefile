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
CFLAGS		=	-Wall -Wextra -Werror -g
MLX_FLAGS	=	-framework OpenGL -framework AppKit
RM			=	rm -rf

# =============================================================================
# File Variables
# =============================================================================

NAME	=	fdf

LIBS	=	libmlx.a

SRCS_DIR	=	./srcs/
OBJS_DIR	=	./objs/
INC_DIR 	=	./include
MLX_DIR		=	./mlx/
DIR_SBJ		=	subject/
DIR_HKF		=	hk_function/
DIR_UTL		=	utility/
DIR_BNS		=	bonus/

COM_OBJ_LST	=	parse1.o				\
				parse2.o				\
				iso_vector.o			\
				bresenham1.o			\
				bresenham2.o			\
				bresenham_utils.o		\
				anti_aliased.o			\
				pixel_print.o			\
				pixel_utils.o			\
				make_ptr.o				\
				ft_utils.o				\
				parse_utils.o			\
				get_next_line.o			\
				get_next_line_utils.o	\
				ft_atoi_hex.o			\
				ft_atoi.o				\
				ft_isdigit.o			\
				ft_memset.o				\
				ft_split.o				\
				ft_strchr.o				\
				ft_strlen.o

MAN_OBJ_LST	=	fdf.o

BNS_OBJ_LST	=	fdf_bonus.o				\
				event_control_bonus.o	\
				event_move_bonus.o		\
				event_zoom_bonus.o		\
				event_rotate_bonus.o	\
				vector_bonus.o

COM_OBJS	=	$(addprefix $(OBJS_DIR), $(COM_OBJ_LST))
MAN_OBJS	=	$(addprefix $(OBJS_DIR), $(MAN_OBJ_LST))
BNS_OBJS	=	$(addprefix $(OBJS_DIR), $(BNS_OBJ_LST))

ifdef IS_BONUS
	OBJS = $(BNS_OBJS) $(COM_OBJS)
else
	OBJS = $(MAN_OBJS) $(COM_OBJS)
endif

# =============================================================================
# Target Generating
# =============================================================================

$(OBJS_DIR)%.o	:	$(SRCS_DIR)$(DIR_SBJ)%.c
					@mkdir -p $(OBJS_DIR)
					@$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@
					@echo $(YELLOW) "Compiling...\t" $< $(EOC) $(LINE_CLEAR)

$(OBJS_DIR)%.o	:	$(SRCS_DIR)$(DIR_UTL)%.c
					@mkdir -p $(OBJS_DIR)
					@$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@
					@echo $(YELLOW) "Compiling...\t" $< $(EOC) $(LINE_CLEAR)

$(OBJS_DIR)%.o	:	$(SRCS_DIR)$(DIR_HKF)%.c
					@mkdir -p $(OBJS_DIR)
					@$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@
					@echo $(YELLOW) "Compiling...\t" $< $(EOC) $(LINE_CLEAR)

$(OBJS_DIR)%.o	:	$(SRCS_DIR)$(DIR_BNS)%.c
					@mkdir -p $(OBJS_DIR)
					@$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@
					@echo $(YELLOW) "Compiling...\t" $< $(EOC) $(LINE_CLEAR)

$(NAME)			:	$(OBJS)
					@$(MAKE) -C $(MLX_DIR)
					@cp $(MLX_DIR)$(LIBS) ./
					@$(CC) $(CFLAGS) -I$(INC_DIR) $(MLX_FLAGS) $(LIBS) -o $@  $^
					@echo $(CYAN) "'$(NAME)'(execute file) is created!\n" $(EOC)

# =============================================================================
# Rule
# =============================================================================

all				:	$(NAME)

clean			:
					@$(RM) $(OBJS_DIR)
					@echo $(RED) "Object files is cleaned.\n" $(EOC)

fclean			:	clean
					@$(MAKE) -C $(MLX_DIR) clean
					@$(RM) $(LIBS)
					@$(RM) $(NAME)
					@echo $(RED) "Execute files is cleaned.\n" $(EOC)

re				:	fclean all

bonus			:
					make IS_BONUS=1 all

.PHONY			:	all clean fclean re bonus
