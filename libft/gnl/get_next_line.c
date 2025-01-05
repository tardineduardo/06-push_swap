/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:02:27 by eduribei          #+#    #+#             */
/*   Updated: 2024/12/16 13:29:11 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*read_loop_heap(int fd, char *nextline)
{
	char	*buffer;
	char	*temp_read_loop;
	int		size_read;

	buffer = malloc((GNLBUFF + 1) * sizeof(char));
	while (!ft_strchr(nextline, '\n'))
	{
		size_read = read(fd, buffer, GNLBUFF);
		if (size_read == -1)
		{
			free(buffer);
			buffer = NULL;
			return (NULL);
		}
		buffer[size_read] = 0;
		temp_read_loop = nextline;
		nextline = ft_strjoin(nextline, buffer);
		free(temp_read_loop);
		temp_read_loop = NULL;
		if (size_read < GNLBUFF)
			break ;
	}
	free(buffer);
	buffer = NULL;
	return (nextline);
}

char	*read_loop_stack(int fd, char *nextline)
{
	char	buffer[GNLBUFF + 1];
	char	*temp_read_loop;
	int		size_read;

	while (!ft_strchr(nextline, '\n'))
	{
		size_read = read(fd, buffer, GNLBUFF);
		if (size_read == -1)
			return (NULL);
		buffer[size_read] = 0;
		temp_read_loop = nextline;
		nextline = ft_strjoin(nextline, buffer);
		free(temp_read_loop);
		temp_read_loop = NULL;
		if (size_read < GNLBUFF)
			break ;
	}
	return (nextline);
}

void	ft_extract_remain(char *nextline, char *remainder)
{
	int		a;

	a = 0;
	while (nextline[a] != '\n' && nextline[a] != 0)
		a++;
	ft_strlcpy(remainder, &nextline[a + 1], GNLBUFF);
	nextline[a + 1] = 0;
}

char	*get_next_line(int fd)
{
	char		*nextline;
	static char	remainder[GNLBUFF];

	if (fd < 0 || GNLBUFF <= 0)
		return (NULL);
	if (read(fd, 0, 0) == -1)
		return (NULL);
	nextline = ft_strdup(remainder);
	remainder[0] = 0;
	if (!nextline)
		return (NULL);
	if (GNLBUFF >= 1)
		nextline = read_loop_heap(fd, nextline);
	if (GNLBUFF < 1)
		nextline = read_loop_stack(fd, nextline);
	if (!nextline || nextline[0] == 0)
	{
		free(nextline);
		nextline = NULL;
		return (NULL);
	}
	if (ft_strchr(nextline, '\n'))
		ft_extract_remain(nextline, remainder);
	return (nextline);
}
