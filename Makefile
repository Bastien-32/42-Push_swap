# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: badal-la <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/23 19:45:10 by badal-la          #+#    #+#              #
#    Updated: 2025/01/28 14:04:33 by badal-la         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                  MANDATORY                                   #
# **************************************************************************** #

DIR = mandatory

SRC = $(DIR)/big_sorts.c \
	$(DIR)/check_args_and_stack.c \
	$(DIR)/ft_split_ps.c \
	$(DIR)/init_stack.c \
	$(DIR)/move_number.c \
	$(DIR)/push_swap.c \
	$(DIR)/push.c \
	$(DIR)/reverse_rotate.c \
	$(DIR)/rotate.c \
	$(DIR)/second_sort.c \
	$(DIR)/sort_b_to_a.c \
	$(DIR)/sort.c \
	$(DIR)/sort4_and_sort5.c \
	$(DIR)/swap.c \
	$(DIR)/utils_sort.c \
	$(DIR)/utils.c

OBJS = $(SRC:.c=.o)

NAME = push_swap

# **************************************************************************** #
#                                   BONUS                                      #
# **************************************************************************** #

DIR_BONUS = bonus

SRC_BONUS = $(DIR)/big_sorts.c \
			$(DIR)/check_args_and_stack.c \
			$(DIR_BONUS)/checker.c \
			$(DIR)/ft_split_ps.c \
			$(DIR)/init_stack.c \
			$(DIR)/move_number.c \
			$(DIR)/push.c \
			$(DIR)/reverse_rotate.c \
			$(DIR)/rotate.c \
			$(DIR)/second_sort.c \
			$(DIR)/sort_b_to_a.c \
			$(DIR)/sort.c \
			$(DIR)/sort4_and_sort5.c \
			$(DIR)/swap.c \
			$(DIR)/utils_sort.c \
			$(DIR)/utils.c \
			$(SRC_GNL)

DIR_GNL = get_next_line

SRC_GNL = $(DIR_GNL)/get_next_line_bonus.c \
          $(DIR_GNL)/get_next_line_utils_bonus.c

OBJS_BONUS = $(SRC_BONUS:.c=.o)

NAME_BONUS	= checker

# **************************************************************************** #
#                                  VARIABLES                                   #
# **************************************************************************** #

CC = gcc

FLAGS = -Wall -Werror -Wextra -g

INCLUDE = -I includes -I $(DIR_GNL)

%.o: %.c
		$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@
		
# **************************************************************************** #
#                               MANDATORY RULES                                #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo ✅ "Mandatory part compiled\n"

# **************************************************************************** #
#                                BONUS RULES                                   #
# **************************************************************************** #

bonus : $(NAME_BONUS)

$(NAME_BONUS) : $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJS_BONUS) -o $(NAME_BONUS)
	@echo ✅ "Bonus part compiled\n"

# **************************************************************************** #
#                                CLEAN RULES                                   #
# **************************************************************************** #

clean:
	rm -f $(OBJS)
	rm -f $(OBJS_BONUS)
	@echo ✅ "Objects files removed\n"

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)
	@echo ✅ "Executables and objects files removed\n"

re:	fclean all

.PHONY: all bonus clean fclean re