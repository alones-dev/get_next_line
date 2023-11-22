/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:46:50 by kdaumont          #+#    #+#             */
/*   Updated: 2023/11/22 16:32:07 by kdaumont         ###   ########.fr       */
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

char	*add_to_line(char *new)
{
	char	*line;
	int		len;

	len = ft_strlen(ft_strrchr(new, '\n'));
	line = ft_strndup(new, ft_strlen(new) - len);
	if (!line)
		return (NULL);
	return (line);
}

char	*check_newline(int fd)
{
	char		*new;
	char		*line;
	static char	buffer[BUFFER_SIZE];
	int			readed;

	readed = 1;
	line = NULL;
	new = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!new)
		return (NULL);
	while ((!is_new_line(new)) && readed > 0)
	{
		readed = read(fd, buffer, BUFFER_SIZE);
		new = ft_strjoin(new, buffer);
		if (!new)
		{
			free(new);
			return (NULL);
		}
	}
	line = add_to_line(new);
	return (line);
}

char	*get_next_line(int fd)
{
}

void	main(void)
{
	int fd = open("test.txt", O_RDWR);
	printf("1: %s", check_newline(fd));
	printf("2: %s", check_newline(fd));
	// check_newline(fd);
	close(fd);
}