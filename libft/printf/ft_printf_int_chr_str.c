#include "../libft.h"

int	ft_count_and_put_int(va_list args, int fd)
{
	long long int	n;

	n = va_arg(args, long long int);
	return (ft_putnbr_fd(n, fd));
}

int	ft_count_and_put_chr(va_list args, int fd)
{
	int	c;

	c = va_arg(args, int);
	return (ft_putchar_fd(c, fd));
}
int	ft_count_and_put_str(va_list args, int fd)
{
	char	*s;

	s = va_arg(args, char *);
	if (!s)
	{
		return (ft_putstr_fd("(null)", 1));
	}
	return (ft_putstr_fd(s, fd));
}

