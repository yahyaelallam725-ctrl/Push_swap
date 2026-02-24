NAME	= push_swap
CC		= cc
CFLAGS	= -Wall -Wextra -Werror

SRCS	= assign_index.c \
		  chunks_push_a.c \
		  chunks_push_b.c \
		  closest_pos.c \
		  find_pos.c \
		  ft_atol.c \
		  ft_check_dup.c \
		  ft_free_args.c \
		  ft_isnum.c \
		  ft_lstadd_back.c \
		  ft_lstadd_front.c \
		  ft_pop_top.c \
		  ft_push_a.c \
		  ft_push_b.c \
		  ft_rev_rotate.c \
		  ft_rotate.c \
		  ft_split.c \
		  ft_swap.c \
		  is_sorted.c \
		  linked_lists_utils.c \
		  push_swap.c \
		  range_index.c \
		  sort_five.c \
		  sort_four.c \
		  sort_three.c \
		  sort_two.c \
		  stack_init.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

.SECONDARY: $(OBJS)