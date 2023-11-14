/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:46:50 by kdaumont          #+#    #+#             */
/*   Updated: 2023/11/14 15:51:48 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_putchar(int c)
{
	write(1, &c, 1);
}

char	*get_next_line(int fd)
{
	char	*buffer[5000];
	int		i;

	i = 0;
	read(fd, buffer, 5000);
	while (buffer[i])
	{
		ft_putchar(*buffer);
		i++;
	}
}

void	main(void)
{
	int test = open("test.txt", O_RDONLY);
	get_next_line(test);
	close(test);
}