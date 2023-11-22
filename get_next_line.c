/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:46:50 by kdaumont          #+#    #+#             */
/*   Updated: 2023/11/22 09:57:13 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	check_newline(int fd)
{
	char	*new;
	char		*buffer[BUFFER_SIZE];
	int	readed;
	
	readed = 1;
	while ((!is_new_line(new)) && readed > 0)
	{
		readed = read(fd, buffer, BUFFER_SIZE);
		new = ft_strjoin(buffer, new);
		if (!new)
		{
			free(new);
			return (NULL);
		}
	}
	return (new);
}

char add_to_line(char *new)
{
	
}

	
is_new_line(char *new)
{
	int	i;

	i = 0;
	while (new[i])
	{
		if (new[i] == '\n')
			return (1);
	}
	return (0);
}

char	*get_next_line(int fd)
{
}
