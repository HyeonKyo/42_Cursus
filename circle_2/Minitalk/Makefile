CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra
RM			=	rm -rf

NAME		=	server
CLT_NAME	=	client

INC_DIR		=	./includes/
SRC_DIR		=	./srcs/
OBJ_DIR		=	./objs/

DIR_SEV		=	sev/
DIR_CLT		=	clt/
DIR_UTL		=	utility/

SEV_OBJ_LST	=	server.o		\
				server_get.o
SEV_OBJS	=	$(addprefix $(OBJ_DIR), $(SEV_OBJ_LST))

CLT_OBJ_LST	=	client.o		\
				client_send.o
CLT_OBJS	=	$(addprefix $(OBJ_DIR), $(CLT_OBJ_LST))

UTL_OBJ_LST	=	ft_utils1.o		\
				ft_utils2.o		\
				error.o
UTL_OBJS	=	$(addprefix $(OBJ_DIR), $(UTL_OBJ_LST))

$(OBJ_DIR)%.o	:	$(SRC_DIR)$(DIR_SEV)%.c
					@mkdir -p $(OBJ_DIR)
					$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

$(OBJ_DIR)%.o	:	$(SRC_DIR)$(DIR_CLT)%.c
					@mkdir -p $(OBJ_DIR)
					$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

$(OBJ_DIR)%.o	:	$(SRC_DIR)$(DIR_UTL)%.c
					@mkdir -p $(OBJ_DIR)
					$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

all				:	$(CLT_NAME)	$(NAME)

$(NAME)			:	$(SEV_OBJS) $(UTL_OBJS)
					$(CC) $(CFLAGS) -I$(INC_DIR) -o $@ $^

$(CLT_NAME)		:	$(CLT_OBJS) $(UTL_OBJS)
					$(CC) $(CFLAGS) -I$(INC_DIR) -o $@ $^

clean			:
					$(RM) $(OBJ_DIR)

fclean			:	clean
					$(RM) $(NAME) $(CLT_NAME)

re				:	fclean all

bonus			:	all

.PHONY			:	all clean fclean re bonus
