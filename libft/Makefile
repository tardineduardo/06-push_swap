SRCS = conv/ft_atoi.c \
		conv/ft_atol.c \
		conv/ft_itoa.c \
		conv/ft_tolower.c \
		conv/ft_toupper.c \
		debug/ft_putstrarr_fd.c \
		error/ft_error_exit.c \
		error/ft_perror_exit.c \
		error/ft_perror_extra.c \
		error/ft_null_and_stderr.c \
		fds/ft_close.c \
		fds/ft_close_four.c \
		fds/ft_close_three.c \
		fds/ft_close_two.c \
		lists/slist/ft_lstadd_back.c \
		lists/slist/ft_lstadd_front.c \
		lists/slist/ft_lstclear.c \
		lists/slist/ft_lstclear_err_exit.c \
		lists/slist/ft_lstclear_null.c \
		lists/slist/ft_lstdelone.c \
		lists/slist/ft_lstiter.c \
		lists/slist/ft_lstlast.c \
		lists/slist/ft_lstmap.c \
		lists/slist/ft_lstnew.c \
		lists/slist/ft_lstsize.c \
		mem/ft_bzero.c \
		mem/ft_calloc.c \
		mem/ft_free.c \
		mem/ft_free_str_array.c \
		mem/ft_memchr.c \
		mem/ft_memcmp.c \
		mem/ft_memcpy.c \
		mem/ft_memmove.c \
		mem/ft_memset.c \
		print/ft_putchar_fd.c \
		print/ft_putendl_fd.c \
		print/ft_putnbr_fd.c \
		print/ft_putstr_fd.c \
		string/ft_concatenate.c \
		string/ft_concatenate_var.c \
		string/ft_split_char.c \
		string/ft_split_space.c \
		string/ft_strchr.c \
		string/ft_strdup.c \
		string/ft_striteri.c \
		string/ft_strjoin.c \
		string/ft_strlcat.c \
		string/ft_strlcpy.c \
		string/ft_strlen.c \
		string/ft_strmapi.c \
		string/ft_strncmp.c \
		string/ft_strnstr.c \
		string/ft_strrchr.c \
		string/ft_strtrim.c \
		string/ft_substr.c \
		valid/ft_isalnum.c \
		valid/ft_isalpha.c \
		valid/ft_isascii.c \
		valid/ft_isdigit.c \
		valid/ft_isprint.c \
		valid/ft_isspace.c \

OBJS_S = $(SRCS:.c=.o)

CC = cc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

all: $(NAME)

$(NAME): $(OBJS_S)
	@ar rc $(NAME) $(OBJS_S)
	@ranlib $(NAME)

%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS_S)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re