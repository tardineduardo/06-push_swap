MAIN =  src/push_swap.c \

UTILS = src/validate_args.c \
		src/algo/init_stack_a.c \

ALGO = 	src/algo/costs_calculate.c \
		src/algo/costs_rot_rev_opo.c \
		src/algo/find_hi_lo_nodes.c \
		src/algo/move_choose_and_run.c \
		src/algo/move_rot_rev_opo.c \
		src/algo/move_node_to_top.c \
		src/algo/update_sorted_status.c \
		src/algo/init_stack_b.c \
		src/inutils.c \

MOVES =	src/moves/moves_sa_sb_ss.c \
		src/moves/moves_ra_rb_rr.c \
		src/moves/moves_rra_rrb_rrr.c \
		src/moves/moves_pa_pb.c \

DEBUG =	src/play/play_print_labels.c \
		src/play/play_print_values.c \

OBJS_SRC =	$(MAIN:.c=.o) $(UTILS:.c=.o) $(ALGO:.c=.o) \
			$(MOVES:.c=.o) $(COSTS:.c=.o) \
			$(DEBUG:.c=.o) \
			
# $(PLAY:.c=.o) \

CC = cc
RM = rm -f
#CFLAGS = -Wall -Wextra -Werror -g
CFLAGS = -pg -g

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
