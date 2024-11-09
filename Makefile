MAIN =  src/push_swap.c \

UTILS = src/validate_args.c \
		src/inits.c \
		src/inutils.c \

ALGO = 	src/costs/costs.c \
		src/algo/initial_pb.c \
		src/algo/m_move.c \
		src/algo/m_opo.c \
		src/algo/m_rev.c \
		src/algo/m_rot.c \
		src/algo/m_top.c \
		src/algo/sorted_status.c \

MOVES =	src/moves/moves_sa_sb_ss.c \
		src/moves/moves_ra_rb_rr.c \
		src/moves/moves_rra_rrb_rrr.c \
		src/moves/moves_pa_pb.c \

DEBUG =	src/play/play_print_labels.c \
		src/play/play_print_values.c \

OBJS_SRC =	$(MAIN:.c=.o) $(UTILS:.c=.o) $(ALGO:.c=.o) \
			$(MOVES:.c=.o) $(COSTS:.c=.o) \
			$(DEBUG:.c=.o) \
			
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g

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
