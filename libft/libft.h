/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 17:02:36 by eduribei          #+#    #+#             */
/*   Updated: 2024/11/12 21:07:22 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <stddef.h>
# include <stdbool.h>
# include <stdarg.h>
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>

# ifndef GNLBUFF
#  define GNLBUFF 42
# endif

# ifndef MAXLISTLOOPS
#  define MAXLISTLOOPS 1000000000
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

typedef struct s_dlist
{
	int				label;
	int				value;
	int				cost;
	int				cost_rot;
	int				cost_rev;
	int				cost_opo_srev_drot;
	int				cost_opo_srot_drev;
	bool			move_rot;
	bool			move_rev;
	bool			move_opo_srev_drot;
	bool			move_opo_srot_drev;
	void			*content;
	struct s_dlist	*to_meet;
	struct s_dlist	*next;
	struct s_dlist	*prev;
	struct s_dlist	*procedent;	
}					t_dll;

// conversions + comparisons
int		ft_atoi(const char *nptr);
int		ft_abs(int a);

// errors
void	ft_error_exit(char *mess, int exit_nb) __attribute__((noreturn));
void	ft_perror_exit(char *mess, int exit_nb) __attribute__((noreturn));

// memory
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_free_and_null(void *ptr);
bool	ft_free_and_false(void *ptr);
bool	ft_free_and_true(void *ptr);

// validations
int		ft_isdigit(int c);
int		ft_isspace(int c);

// strings
char	*ft_strchr(const char *str, int c);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);

//lists - dclist
t_dll	*ft_dclstnew(void *content);
t_dll	*ft_dclst_find_lo_int(t_dll **tail, int offset);
t_dll	*ft_dclst_find_hi_int(t_dll **tail, int offset);
t_dll	*ft_dclst_find_node(t_dll **tail, t_dll *node);
bool	ft_dclst_clock_sortd(t_dll **tail, char mode, int offset);
bool	ft_dclst_circ_sortd(t_dll **tail, char mode, int offset);
void	ft_dclstadd_back(t_dll **tail, t_dll *new);
void	ft_dclstclear_simple(t_dll **lst);
int		ft_dclstsize(t_dll **tail);
int		ft_dclst_dist_head_bidi(t_dll **tail, t_dll *node);
int		ft_dclst_dist_head_bidi_len(t_dll **tail, t_dll *node, int list_len);

// printf
int		ft_printf(const char *input, ...);
int		ft_dprintf(int fd, const char *input, ...);
int		ft_count_and_put_chr(va_list args, int fd);
int		ft_count_and_put_str(va_list args, int fd);
int		ft_count_and_put_int(va_list args, int fd);
int		ft_count_and_put_ptr(va_list args, int fd);
int		ft_count_and_put_uns(va_list args, int fd);
int		ft_count_and_put_hex_l(va_list args, int fd);
int		ft_count_and_put_hex_u(va_list args, int fd);

// printing
int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *s, int fd);
int		ft_putnbr_fd(int n, int fd);
int		ft_puthex_upp_int(unsigned int n, int fd);
int		ft_puthex_low_int_fd(unsigned int n, int fd);
int		ft_putuns_fd(unsigned int n, int fd);
int		ft_puthex_lo_long_fd(unsigned long long int n, int fd);

// sort
void	ft_sort_int_array_bubble(int *array, size_t len);

// get next line
char	*get_next_line(int fd);

#endif
