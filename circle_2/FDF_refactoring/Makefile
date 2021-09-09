
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
MLX_FLAGS	=	-framework OpenGL -framework AppKit -fsanitize=address

INC_DIR 	=	./include
DIR_SBJ		=	subject/
DIR_HKF		=	hk_function/
DIR_UTL		=	utility/

SRCS_DIR	=	./srcs/
OBJS_DIR	=	./objs/
# SRCS_OBJ	=	$(DIR_SBJ)fdf.o					\
# 				$(DIR_SBJ)parse1.o				\
# 				$(DIR_SBJ)parse2.o				\
# 				$(DIR_SBJ)parse_utils.o			\
# 				$(DIR_SBJ)iso_vector.o			\
# 				$(DIR_UTL)vector.o				\
# 				$(DIR_UTL)ft_utils.o			\
# 				$(DIR_UTL)event_move.o			\
# 				$(DIR_UTL)event_zoom.o			\
# 				$(DIR_HKF)get_next_line.o		\
# 				$(DIR_HKF)get_next_line_utils.o	\
# 				$(DIR_HKF)ft_atoi_hex.o			\
# 				$(DIR_HKF)ft_atoi.o				\
# 				$(DIR_HKF)ft_isdigit.o			\
# 				$(DIR_HKF)ft_memset.o			\
# 				$(DIR_HKF)ft_split.o			\
# 				$(DIR_HKF)ft_strlen.o			\
# 				$(DIR_HKF)ft_strchr.o			\

SRCS_OBJ	=	fdf.o					\
				parse1.o				\
				parse2.o				\
				parse_utils.o			\
				iso_vector.o			\
				bresenham1.o			\
				bresenham2.o			\
				bresenham_utils.o		\
				pixel_print.o			\
				pixel_utils.o			\
				make_ptr.o				\
				vector.o				\
				ft_utils.o				\
				event_move.o			\
				event_zoom.o			\
				get_next_line.o			\
				get_next_line_utils.o	\
				ft_atoi_hex.o			\
				ft_atoi.o				\
				ft_isdigit.o			\
				ft_memset.o				\
				ft_split.o				\
				ft_strlen.o

OBJS	=	$(addprefix $(OBJS_DIR), $(SRCS_OBJ))

LIBS = libmlx.a

NAME = fdf

RM = rm -rf

all		:	$(NAME)

$(OBJS_DIR)%.o	:	$(SRCS_DIR)$(DIR_SBJ)%.c
					mkdir -p $(OBJS_DIR)
					$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

$(OBJS_DIR)%.o	:	$(SRCS_DIR)$(DIR_UTL)%.c
					mkdir -p $(OBJS_DIR)
					$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

$(OBJS_DIR)%.o	:	$(SRCS_DIR)$(DIR_HKF)%.c
					mkdir -p $(OBJS_DIR)
					$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

$(NAME)	:	$(OBJS)
			$(CC) -I$(INC_DIR) -o $@ $(MLX_FLAGS) $^ $(LIBS)

clean	:
			$(RM) $(OBJS_DIR)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re bonus
