MAIN =  src/push_swap.c \

BONUS = bonus/checker.c \
		bonus/checker_init.c \
		bonus/checker_validate.c \
		bonus/get_members.c \

UTILS = src/validate_args.c \
		src/init_stack_a.c \

ALGO =	src/algo_high/costs_calculate.c \
		src/algo_high/costs_rot_rev_opo.c \
		src/algo_high/find_hi_lo_nodes.c \
		src/algo_high/move_choose_and_run.c \
		src/algo_high/move_rot_rev_opo.c \
		src/algo_high/move_node_to_top.c \
		src/algo_high/update_sorted_status.c \
		src/algo_high/init_stack_b.c \

LOW = 	src/algo_low/low_init_stack_b.c \
		src/algo_low/low_swapping.c \

MOVES =	src/moves/moves_sa_sb_ss.c \
		src/moves/moves_ra_rb_rr.c \
		src/moves/moves_rra_rrb_rrr.c \
		src/moves/moves_pa_pb.c \

OBJS_SRC =	$(MAIN:.c=.o) $(UTILS:.c=.o) $(ALGO:.c=.o) $(LOW:.c=.o) \
			$(MOVES:.c=.o) \

OBJS_BON =	$(BONUS:.c=.o) $(MOVES:.c=.o) \

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

NAME = push_swap
LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

CHECK = checker

all: $(NAME)

bonus: $(CHECK)

$(NAME): $(OBJS_SRC) $(LIBFT)
		$(CC) $(CFLAGS) $(OBJS_SRC) $(LIBFT) -o $(NAME)

$(CHECK): $(OBJS_BON) $(LIBFT) $(BONUS)
		$(CC) $(CFLAGS) $(OBJS_BON) $(LIBFT) -o $(CHECK)

$(LIBFT): $(LIBFT_OBJS)
		$(MAKE) -C $(LIBFT_PATH) all

src/%.o: src/%.c
		$(CC) $(CFLAGS) -c $< -o $@

bonus/%.o: bonus/%.c
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		$(RM) $(OBJS_SRC) $(OBJS_BON)
		$(MAKE) -C $(LIBFT_PATH) clean

fclean: clean
		$(RM) $(NAME) $(CHECK)
		$(MAKE) -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re