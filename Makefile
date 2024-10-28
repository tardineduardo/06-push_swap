SRC = src/push_swap.c \

UTILS = src/validate_args.c \
		src/init_stack.c \
		src/init_stack_debug.c \
		src/moves/moves_sa_sb_ss.c \
		src/moves/moves_ra_rb_rr.c \
		src/moves/moves_rra_rrb_rrr.c \
		src/moves/moves_pa_pb.c \
		src/algo/distribute_values.c \
		src/algo/move_node_to_top.c	\
		src/play/play_print.c \

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
