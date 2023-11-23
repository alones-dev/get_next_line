/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:46:50 by kdaumont          #+#    #+#             */
/*   Updated: 2023/11/23 09:42:46 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	is_new_line(char *new)
{
	int	i;

	i = 0;
	if (!new)
		return (0);
	while (new[i])
	{
		i++;
		if (new[i] == '\n')
			return (i + 1);
	}
	return (0);
}

int	read_buffer(int fd, char **buffer)
{
	if (!*buffer)
		return (read(fd, buffer, BUFFER_SIZE));
	return (1);
}

char	*get_next_line(int fd)
{
	char		*line;
	int			new_line;
	int			i;
	static char	buffer[BUFFER_SIZE];

	line = NULL;
	i = 0;
	while ((!is_new_line(line)) && read_buffer(fd, (char **)buffer) > 0)
	{
		new_line = is_new_line(line);
		line = ft_strjoin(line, buffer, new_line);
		if (!line)
			return (NULL);
		while (i < new_line && i + new_line < BUFFER_SIZE)
		{
			buffer[i] = buffer[i + new_line];
			i++;
		}
		buffer[i] = '\0';
	}
	return (line);
}

void	main(void)
{
	int fd = open("test.txt", O_RDWR);
	printf("1: %s\n \n", check_newline(fd));
	printf("2: %s", check_newline(fd));
	// check_newline(fd);
	close(fd);
}