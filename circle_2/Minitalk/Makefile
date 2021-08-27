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

SEV_OBJS	=	server.o		\
				server_get.o
CLT_OBJS	=	client.o		\
				client_send.o
UTL_OBJS	=	ft_utils1.o		\
				ft_utils2.o

$(OBJ_DIR)%.o	:	$(SRC_DIR)$(DIR_SEV)%.c dir
					$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

$(OBJ_DIR)%.o	:	$(SRC_DIR)$(DIR_CLT)%.c dir
					$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

$(OBJ_DIR)%.o	:	$(SRC_DIR)$(DIR_UTL)%.c dir
					$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

$(NAME)			:	$(OBJ_DIR)$(SEV_OBJS) $(OBJ_DIR)$(UTL_OBJS)
					$(CC) $(CFLAGS) -I$(INC_DIR) -o $@ $^

$(CLT_NAME)		:	$(OBJ_DIR)$(CLT_OBJS) $(OBJ_DIR)$(UTL_OBJS)
					$(CC) $(CFLAGS) -I$(INC_DIR) -o $@ $^

all				:	$(NAME)	$(CLT_NAME)

clean			:
					$(RM) $(OBJ_DIR)

fclean			:	clean
					$(RM) $(NAME) $(CLT_NAME)

re				:	fclean all

bonus			:	re

dir				:
					mkdir -p $(OBJ_DIR)

.PHONY			:	all clean fclean re bonus dir
