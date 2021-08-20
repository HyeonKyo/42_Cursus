
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS =  command1.c command2.c command3.c ft_utils1.c ft_utils2.c \
		input1.c input2.c list.c list_cmd.c optimize.c \
		pre_sort1.c pre_sort2.c pre_sort3.c push_swap.c \
		sort1.c sort2.c sort_check_status.c sort_optimize.c sort_utils.c
BNS_SRCS = checker.c ft_utils1.c ft_utils2.c list_cmd.c list.c input1.c \
			input2.c sort_check_status.c command1_bonus.c command2_bonus.c \
			command3_bonus.c get_next_line.c get_next_line_utils.c
OBJS = $(SRCS:.c=.o)
BNS_OBJS = $(BNS_SRCS:.c=.o)
INC_DIR = ./includes
NAME = push_swap
BNS_NAME = checker
RM = rm -rf

all		:	$(NAME)

$(NAME)	:	$(OBJS)
			$(CC) $(CFLAGS) -o $@ $^

.c.o	:
			$(CC) $(CFLAGS) -c $(SRCS) -I$(INC_DIR)

clean	:
			$(RM) $(OBJS) $(BNS_OBJS)

fclean	:	clean
			$(RM) $(NAME) $(BNS_NAME)

re		:	fclean all

bonus	:	$(BNS_OBJS)
			$(CC) $(CFLAGS) -c $(BNS_SRCS) -I$(INC_DIR)
			$(CC) $(CFLAGS) -o $(BNS_NAME) $^

.PHONY	:	all clean fclean re bonus
 