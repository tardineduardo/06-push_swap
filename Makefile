SRC = src/push_swap.c \

UTILS = src/validate_args.c \
		src/init_stack.c \
		src/init_stack_debug.c \
		src/moves/moves_sa_sb_ss.c \
		src/moves/moves_ra_rb_rr.c \
		src/moves/moves_rra_rrb_rrr.c \
		src/moves/moves_pa_pb.c \
		src/algo/move_node_to_top.c	\
		src/play/play.c \
		src/play/play_print_labels.c \
		src/play/play_print_values.c \
		src/algo/solve.c \
		src/algo/even_nodes_per_stack.c \
		src/algo/find_lowest_cost.c \
		src/algo/move_cheapest_node.c \
		src/algo/repostion_dst_stack.c \
		src/algo/update_sorted_status.c \
		src/algo/swapping.c \
		src/algo/calculate_all_costs.c \

OBJS_SRC = $(SRC:.c=.o) $(UTILS:.c=.o)

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g
#CFLAGS = -g

NAME = push_swap
LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

all: $(NAME)

$(NAME): $(OBJS_SRC) $(LIBFT)
		$(CC) $(CFLAGS) $(OBJS_SRC) $(LIBFT) -o $(NAME)

$(LIBFT): $(LIBFT_OBJS)
		$(MAKE) -C $(LIBFT_PATH) all

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		$(RM) $(OBJS_SRC) #$(OBJS_BONUS)
		$(MAKE) -C $(LIBFT_PATH) clean

fclean: clean
		$(RM) $(NAME)
		$(MAKE) -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re
