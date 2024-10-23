/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 18:50:47 by eduribei          #+#    #+#             */
/*   Updated: 2024/10/22 21:14:47 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <bsd/string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			a;
	unsigned char	*source;
	unsigned char	*destiny;

	source = (unsigned char *)src;
	destiny = (unsigned char *)dest;
	a = 0;
	while (a < n)
	{
		destiny[a] = source[a];
		a++;
	}
	return (dest);
}

size_t	ft_strlen(const char *s)
{
	int	count;

	count = 0;
	while (*s != '\0')
	{
		count++;
		s++;
	}
	return (count);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	copy_len;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	if (size <= dst_len)
		return (size + src_len);
	copy_len = size - dst_len - 1;
	if (copy_len > src_len)
		copy_len = src_len;
	ft_memcpy(dst + dst_len, src, copy_len);
	dst[dst_len + copy_len] = '\0';
	return (dst_len + src_len);
}

// int main(void)
// {
// 	char nome[12] = "eduardo";
// 	char sobrenome[16] = "magalhaes silva";
// 	// nome = malloc(12 * sizeof(char));
// 	// sobrenome = malloc(6 * sizeof(char));
	
// 	printf("%s\n", nome);
// 	printf("%s\n", sobrenome);
// 	int a = strlcat(nome, sobrenome, 4);
// 	printf("%s\n", nome);

// 	printf("%i\n", a);

// }


