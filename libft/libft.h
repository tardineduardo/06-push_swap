/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 17:02:36 by eduribei          #+#    #+#             */
/*   Updated: 2024/11/01 17:51:40 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <stdint.h>
# include <stddef.h>
# include <stdbool.h>
# include <stdarg.h>
# include <string.h>
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>
# include <sys/types.h>
# include <bits/posix1_lim.h>

# ifndef GNLBUFF
#  define GNLBUFF 42
# endif

# ifndef MAXLISTLOOPS
#  define MAXLISTLOOPS 1000000000
# endif

# define RESET   "\033[0m"
# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define YELLOW  "\033[33m"
# define BLUE    "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN    "\033[36m"
# define WHITE   "\033[37m"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;


// NAO MUDAR ORDEM ROT - REV - OPO !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
typedef struct s_dlist
{
	int				label;
	int				value;
	int				cost;
	int				cost_sam;
	int				cost_swp;
	int				cost_rot;
	int				cost_rev;
	int				cost_opo;
	bool			move_sam;
	bool			move_swp;
	bool			move_rot;
	bool			move_rev;
	bool			move_opo;
	char			opo_way_a;
	void			*content;
	struct s_dlist	*next;
	struct s_dlist	*prev;
	struct s_dlist	*precedent;
	struct s_dlist	*procedent;
}				t_dll;

// conversions + comparisons
int		ft_atoi(const char *nptr);
long	ft_atol(const char *nptr);
char	*ft_itoa(int n);
int		ft_tolower(int c);
int		ft_toupper(int c);
int		abs(int a);
int		lowest(int a, int b);
int		greatest(int a, int b);

// debug
void	ft_debug_print_array_of_strings(char **s, int fd);
void	ft_debug_print_list(t_list **head, char *type, size_t offset);
void	ft_debug_print_dclist(t_dll **tail, char *type, size_t offset, int fd);
void	ft_debug_print_arr_ints(int *a, int len, bool lnbk, bool idx, int fd);

// errors
void	ft_error_exit(char *message, int exit_number) __attribute__((noreturn));
void	ft_perror_extra(char *extra_argument, char *normal_perror);
void	ft_perror_exit(char *message, int exit_number) __attribute__((noreturn));
void	*ft_null_and_stderr(char *message); 

// memory
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	ft_free_str_array(char **array_of_chars);
void	ft_free(int total, ...);

// validations
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_isspace(int c);

// strings
char	**ft_split_char(char const *s, char c);
char	**ft_split_space(char *s);
char	*ft_strchr(const char *str, int c);
char	*ft_strdup(const char *s);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strrchr(const char *str, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_concatenate_var(int num, ...);
char	*ft_concatenate(char *s1, char *s2, char *s3);

// printing
int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *s, int fd);
int		ft_putnbr_fd(int n, int fd);
int		ft_puthex_upp_int(unsigned int n, int fd);
int		ft_puthex_low_int_fd(unsigned int n, int fd);
int		ft_putuns_fd(unsigned int n, int fd);
int		ft_puthex_lo_long_fd(unsigned long long int n, int fd);

// file descriptors
void	ft_close(int total, ...);
void	ft_close_two(int fd1, int fd2);
void	ft_close_three(int fd1, int fd2, int fd3);
void	ft_close_four(int fd1, int fd2, int fd3, int fd4);

//lists - slist
void	ft_lstclear_err_exit(t_list **lst, void (*del)(void*), char *e, int n);
void	*ft_lstclear_null(t_list **lst, void (*del)(void*));
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstnew(void *content);
int		ft_lstsize(t_list *lst);

//lists - dlist
//lists - clist
t_list	*ft_clstnew(void *content);
int		ft_clstsize(t_list **tail);
void	ft_clstadd_back(t_list **tail, t_list *new);
void	ft_clstadd_front(t_list **tail, t_list *new);
void	ft_clstadd_mid_wrap(t_list **tail, t_list *new, size_t pos);

//lists - dclist
t_dll	*ft_dclstnew(void *content);
int		ft_dclstsize(t_dll **tail);
void	ft_dclstadd_back(t_dll **tail, t_dll *new);
void	ft_dclstadd_front(t_dll **tail, t_dll *new);
t_dll	*ft_dclsttrav_to_index(t_dll **tail, int index);
t_dll	*ft_dclst_find_value(t_dll **tail, int value, int offset);
t_dll	*ft_dclst_find_lowest_int(t_dll **tail, int offset);
t_dll	*ft_dclst_find_lowest_abs(t_dll **tail, int offset);
t_dll	*ft_dclst_find_highest_int(t_dll **tail, int offset);
bool	ft_dclst_clock_sortd(t_dll **tail, char mode, int offset);
bool	ft_dclst_circ_sortd(t_dll **tail, char type, char mode, int offset);
bool	ft_dclst_list_sortd(t_dll **tail, char *type, char mode, int offset);
int		ft_dclst_dist_head_bidi(t_dll **tail, t_dll *node);
int		ft_dclst_dist_head_bidi_len(t_dll **tail, t_dll *node, int list_len);
int		ft_dclst_dist_head_unid(t_dll **tail, t_dll *nd, char mode);
int		ft_dclst_dist_head_unid_len(t_dll **tail, t_dll *nd, int llen, char mode);
t_dll	*ft_dclst_find_node(t_dll **tail, t_dll *node);

// printf
int	ft_printf(const char *input, ...);
int	ft_dprintf(int fd, const char *input, ...);
int	ft_count_and_put_chr(va_list args, int fd);
int	ft_count_and_put_str(va_list args, int fd);
int	ft_count_and_put_int(va_list args, int fd);
int	ft_count_and_put_ptr(va_list args, int fd);
int	ft_count_and_put_uns(va_list args, int fd);
int	ft_count_and_put_hex_l(va_list args, int fd);
int	ft_count_and_put_hex_u(va_list args, int fd);

// sort
void	ft_sort_int_array_bubble(int *array, size_t len);

// get next line
char    *get_next_line(int fd);

#endif
