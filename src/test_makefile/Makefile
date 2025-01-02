LIBC = check_args_and_stack.c ft_split_ps.c init_stack.c lib_utils.c push_swap.c \
		sorts.c push.c rotate.c reverse_rotate.c swap.c\

SRC = ${LIBC}

OBJS = ${SRC:.c=.o}

NAME = push_swap.a 

CC = gcc

FLAGS = -Wall -Werror -Wextra

%.o: %.c
		${CC} ${FLAGS} -c $< -o $@

all: ${NAME}

clean:
		rm -f ${OBJS}

fclean: clean;
		rm -f ${NAME}

re:	fclean all

.PHONY: all clean fclean re