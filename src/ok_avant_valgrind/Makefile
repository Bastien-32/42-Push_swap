SRC = big_sorts.c check_args_and_stack.c ft_split_ps.c init_stack.c \
		move_number.c push_swap.c push.c reverse_rotate.c rotate.c \
		second_sort.c sort_b_to_a.c sort.c swap.c utils_sort.c utils.c \


OBJS = ${SRC:.c=.o}

NAME = push_swap 

CC = gcc

FLAGS = -Wall -Werror -Wextra -g

%.o: %.c
		${CC} ${FLAGS} -c $< -o $@

all: ${NAME}

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
		rm -f ${OBJS}

fclean: clean
		rm -f ${NAME}

re:	fclean all

.PHONY: all clean fclean re