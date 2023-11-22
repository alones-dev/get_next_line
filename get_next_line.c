/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:46:50 by kdaumont          #+#    #+#             */
/*   Updated: 2023/11/22 14:31:50 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	is_new_line(char *new)
{
	int	i;

	i = 0;
	while (new[i])
	{
		i++;
		if (new[i] == '\n')
			return (1);
	}
	return (0);
}

char	*check_newline(int fd)
{
	char		*new;
	static char	buffer[BUFFER_SIZE];
	int			readed;

	readed = 1;
	new = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!new)
		return (0);
	while ((!is_new_line(new)) && readed > 0)
	{
		readed = read(fd, buffer, BUFFER_SIZE);
		// printf("buffer: %s\n", buffer);
		new = ft_strjoin(new, buffer);
		// printf("new: %s\n\n\n", new);
		if (!new)
		{
			free(new);
			return (0);
		}
	}
	return (new);
}

char	add_to_line(char *new)
{
	char	*line;
}

char	*get_next_line(int fd)
{
}

void	main(void)
{
	int fd = open("test.txt", O_RDWR);
	printf("1: %s\n\n", check_newline(fd));
	printf("2: %s\n", check_newline(fd));
	// check_newline(fd);
	close(fd);
}