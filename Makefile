################	  MANDATORY		################
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
####################################################

################		BONUS		################
DIR_BONUS = bonus

SRC_BONUS = $(DIR_BONUS)/big_sorts.c \
			$(DIR_BONUS)/check_args_and_stack.c \
			$(DIR_BONUS)/checker.c \
			$(DIR_BONUS)/ft_split_ps.c \
			$(DIR_BONUS)/init_stack.c \
			$(DIR_BONUS)/move_number.c \
			$(DIR_BONUS)/push.c \
			$(DIR_BONUS)/reverse_rotate.c \
			$(DIR_BONUS)/rotate.c \
			$(DIR_BONUS)/second_sort.c \
			$(DIR_BONUS)/sort_b_to_a.c \
			$(DIR_BONUS)/sort.c \
			$(DIR_BONUS)/sort4_and_sort5.c \
			$(DIR_BONUS)/swap.c \
			$(DIR_BONUS)/utils_sort.c \
			$(DIR_BONUS)/utils.c \
			$(SRC_GNL)

DIR_GNL = get_next_line

SRC_GNL = $(DIR_GNL)/get_next_line_bonus.c \
          $(DIR_GNL)/get_next_line_utils_bonus.c

OBJS_BONUS = $(SRC_BONUS:.c=.o)

NAME_BONUS	= checker
####################################################

CC = gcc

FLAGS = -Wall -Werror -Wextra -g

INCLUDE = -I includes -I $(DIR_GNL)

%.o: %.c
		$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

########################## 	  MANDATORY COMMANDS 	##########################
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo ✅ "Mandatory part compiled\n"
##############################################################################

##########################		BONUS COMMANDS	 	##########################
bonus : $(NAME_BONUS)

$(NAME_BONUS) : $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJS_BONUS) -o $(NAME_BONUS)
	@echo ✅ "Bonus part compiled\n"
##############################################################################

##########################		CLEAN COMMANDS	 	##########################
clean:
	rm -f $(OBJS)
	rm -f $(OBJS_BONUS)
	@echo ✅ "Objects files removed\n"

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)
	@echo ✅ "Executables and objects files removed\n"

re:	fclean all
##############################################################################

.PHONY: all bonus clean fclean re