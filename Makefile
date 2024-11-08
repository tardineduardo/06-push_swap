MAIN =  src/push_swap.c \

# PLAY =	src/play/play_swap.c \

UTILS = src/validate_args.c \
		src/init_stack.c \

ALGO = 	src/algo/even_nodes_per_stack.c \
		src/algo/costs.c \
		src/algo/find_hi_lo_nodes.c \
		src/algo/gridlock.c \
		src/algo/move.c \
		src/algo/split_by_order.c \
		src/algo/swapping.c \
		src/algo/update_sorted_status.c \

MOVES =	src/moves/moves_sa_sb_ss.c \
		src/moves/moves_ra_rb_rr.c \
		src/moves/moves_rra_rrb_rrr.c \
		src/moves/moves_pa_pb.c \

# COSTS = src/algo/costs/all_costs.c \
# 		src/algo/costs/cost_opo.c \
# 		src/algo/costs/cost_rev.c \
# 		src/algo/costs/cost_rot.c \
# 		src/algo/costs/cost_sam.c \
# 		src/algo/costs/cost_swp.c \

DEBUG =	src/init_stack_debug.c \
		src/play/play_print_labels.c \
		src/play/play_print_values.c \


OBJS_SRC =	$(MAIN:.c=.o) $(UTILS:.c=.o) $(ALGO:.c=.o) \
			$(MOVES:.c=.o) $(COSTS:.c=.o) \
			$(DEBUG:.c=.o) \
			
# $(PLAY:.c=.o) \

CC = cc
RM = rm -f
#CFLAGS = -Wall -Wextra -Werror -g
CFLAGS = -g

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
