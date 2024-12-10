/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 10:14:35 by nseon             #+#    #+#             */
/*   Updated: 2024/12/10 16:10:09 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char	*line(int i, char **left)
{
	char	*str;

	str = ft_strnjoin(NULL, *left, i);
	*left = ft_substr(*left, i + 1);
	if (!*left || !str)
	{
		free_all(&str);
		free_all(left);
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*left;
	char		buff[BUFFER_SIZE];
	int			i;
	int			nb;

	nb = 1;
	while (!(nb == 0 && left))
	{
		i = 0;
		nb = read(fd, buff, BUFFER_SIZE);
		if (nb == -1 || (nb == 0 && (!left || (left && left[0] == '\0'))))
			return (free_all(&left));
		left = ft_strnjoin2(left, buff, nb);
		if (!left)
			return (free_all(&left));
		while (left[i])
		{
			if (left[i] == '\n')
				return (line(i, &left));
			i++;
		}
	}
	return (line(i, &left));
}

#include <fcntl.h>

int	main()
{
	int	fd;
	int	heecks;

	fd = open("text.txt", O_RDONLY);
	heecks = 0;
	while (heecks < 10)
	{
		printf("%s", get_next_line(fd));
		heecks++;
	}
	return (0);
}
