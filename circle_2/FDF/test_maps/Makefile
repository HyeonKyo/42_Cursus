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

INC_DIR 	=	./include
MLX_DIR		=	./mlx/
DIR_SBJ		=	subject/
DIR_HKF		=	hk_function/
DIR_UTL		=	utility/

SRCS_DIR	=	./srcs/
OBJS_DIR	=	./objs/

SRCS_OBJ	=	fdf.o					\
				parse1.o				\
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

OBJS	=	$(addprefix $(OBJS_DIR), $(SRCS_OBJ))

LIBS	=	libmlx.a

NAME	=	fdf

RM		=	rm -rf

$(OBJS_DIR)%.o	:	$(SRCS_DIR)$(DIR_SBJ)%.c
					@mkdir -p $(OBJS_DIR)
					$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

$(OBJS_DIR)%.o	:	$(SRCS_DIR)$(DIR_UTL)%.c
					@mkdir -p $(OBJS_DIR)
					$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

$(OBJS_DIR)%.o	:	$(SRCS_DIR)$(DIR_HKF)%.c
					@mkdir -p $(OBJS_DIR)
					$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

$(NAME)			:	$(OBJS)
					@$(MAKE) -C $(MLX_DIR)
					@cp $(MLX_DIR)$(LIBS) ./
					$(CC) -I$(INC_DIR) -o $@ $(MLX_FLAGS) $^ $(LIBS)

all				:	$(NAME)

clean			:
					$(RM) $(OBJS_DIR)

fclean			:	clean
					$(MAKE) -C $(MLX_DIR) clean
					$(RM) $(LIBS)
					$(RM) $(NAME)

re				:	fclean all

.PHONY			:	all clean fclean re
