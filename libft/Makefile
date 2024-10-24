PRINTF =	printf/ft_printf_dprintf.c \
			printf/ft_printf_int_chr_str.c \
			printf/ft_printf_hex_ptr_uns.c \

PUTS =	puts/ft_putchar_fd.c \
		puts/ft_puthex_int_low_fd.c \
		puts/ft_puthex_int_upp_fd.c \
		puts/ft_puthex_long_low_fd.c \
		puts/ft_putnbr_fd.c \
		puts/ft_putstr_fd.c \
		puts/ft_putuns_fd.c \

CONV =	conv/ft_atoi.c \
		conv/ft_atol.c \
		conv/ft_itoa.c \
		conv/ft_tolower.c \
		conv/ft_toupper.c \

DEBUG =	debug/ft_putstrarr_fd.c \
		debug/ft_print_list.c \
		debug/ft_print_dclist.c \

ERROR =	error/ft_error_exit.c \
		error/ft_perror_exit.c \
		error/ft_perror_extra.c \
		error/ft_null_and_stderr.c \
		fds/ft_close.c \

FDS =	fds/ft_close_four.c \
		fds/ft_close_three.c \
		fds/ft_close_two.c \

LISTS =	lists/slist/ft_lstadd_back.c \
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
		lists/clist/ft_clistsize.c \
		lists/clist/ft_clstadd_back.c \
		lists/clist/ft_clstadd_front.c \
		lists/clist/ft_clstadd_mid.c \
		lists/clist/ft_clstnew.c \
		lists/dclst/ft_dclistsize.c \
		lists/dclst/ft_dclstadd_back.c \
		lists/dclst/ft_dclstadd_front.c \
		lists/dclst/ft_dclstnew.c \
		lists/dclst/ft_dclsttrav_to_next.c \

MEM = 	mem/ft_bzero.c \
		mem/ft_calloc.c \
		mem/ft_free.c \
		mem/ft_free_str_array.c \
		mem/ft_memchr.c \
		mem/ft_memcmp.c \
		mem/ft_memcpy.c \
		mem/ft_memmove.c \
		mem/ft_memset.c \

STRING = string/ft_concatenate.c \
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
		string/ft_strcmp.c \
		string/ft_strnstr.c \
		string/ft_strrchr.c \
		string/ft_strtrim.c \
		string/ft_substr.c \

VALID =	valid/ft_isalnum.c \
		valid/ft_isalpha.c \
		valid/ft_isascii.c \
		valid/ft_isdigit.c \
		valid/ft_isprint.c \
		valid/ft_isspace.c \

GNL		=	gnl/get_next_line_bonus.c

OBJS =	$(PRINTF:.c=.o) $(CONV:.c=.o) $(DEBUG:.c=.o) $(ERROR:.c=.o) \
		$(FDS:.c=.o) $(LISTS:.c=.o) $(MEM:.c=.o) \
		$(PUTS:.c=.o) $(STRING:.c=.o) $(VALID:.c=.o) \
		$(GNL:.c=.o) \

CC = cc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror -g

NAME = libft.a

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@$(MAKE) clean

%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re