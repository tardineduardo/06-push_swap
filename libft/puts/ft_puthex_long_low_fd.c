#include "../libft.h"

int	ft_puthex_lo_long_fd(unsigned long long int n, int fd)
{
	int		count;
	char	hex_str[17];
	int		a;

	count = 0;
	a = 0;
	if (n == 0)
	{
		ft_putchar_fd('0', fd);
		return (1);
	}
	while (n > 0)
	{
		hex_str[a++] = "0123456789abcdef"[n % 16];
		n /= 16;
	}
	while (--a >= 0)
	{
		ft_putchar_fd(hex_str[a], fd);
		count++;
	}
	return (count);
}