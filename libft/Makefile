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
		conv/ft_abs.c \

ERROR =	error/ft_error_exit.c \
		error/ft_perror_exit.c \

LISTS =	lists/dclst/ft_dclistsize.c \
		lists/dclst/ft_dclstadd_back.c \
		lists/dclst/ft_dclstnew.c \
		lists/dclst/ft_dclst_find_lowest_int.c \
		lists/dclst/ft_dclst_find_highest_int.c \
		lists/dclst/ft_dclst_find_value.c \
		lists/dclst/ft_dclst_dist_head_bidi_len.c \
		lists/dclst/ft_dclst_dist_head_bidi.c \
		lists/dclst/ft_dclst_clock_sortd.c \
		lists/dclst/ft_dclst_circle_sorted.c \
		lists/dclst/ft_dclst_list_sorted.c \
		lists/dclst/ft_dclstclear_simple.c \

MEM = 	mem/ft_bzero.c \
		mem/ft_free_and.c \
		mem/ft_calloc.c \
		mem/ft_memcpy.c \

STRING =	string/ft_strchr.c \
			string/ft_strcmp.c \
			string/ft_strdup.c \
			string/ft_strjoin.c \
			string/ft_strlcpy.c \
			string/ft_strlen.c \

VALID =	valid/ft_isdigit.c \
		valid/ft_isspace.c \

SORT =	sort/ft_sort_int_array_bubble.c

GNL	=	gnl/get_next_line_bonus.c \
		
OBJS =	$(PRINTF:.c=.o) $(CONV:.c=.o) $(ERROR:.c=.o) \
		$(FDS:.c=.o) $(LISTS:.c=.o) $(MEM:.c=.o) \
		$(PUTS:.c=.o) $(STRING:.c=.o) $(VALID:.c=.o) \
		$(GNL:.c=.o) $(SORT:.c=.o) \

CC = cc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

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