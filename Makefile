SRC = push_swap.c

#BONUS = src/pipex_bonus.c

UTILS = src/ft_is_sorted.c \

OBJS_SRC = $(SRC:.c=.o) $(UTILS:.c=.o)
#OBJS_BONUS = $(BONUS:.c=.o) $(UTILS:.c=.o)

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

NAME = pipex
LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

all: $(NAME)

$(NAME): $(OBJS_SRC) $(LIBFT)
		$(CC) $(CFLAGS) $(OBJS_SRC) $(LIBFT) -o $(NAME)

#bonus: $(OBJS_BONUS) $(LIBFT)
#        $(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) -o $(NAME)

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

# Rebuild                                                                               
re: fclean all

.PHONY: all clean fclean re
