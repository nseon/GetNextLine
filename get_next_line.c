/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 10:14:35 by nseon             #+#    #+#             */
/*   Updated: 2024/12/10 11:40:12 by nseon            ###   ########.fr       */
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
		return (free(str), free(*left), NULL);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*left = NULL;
	char		buff[BUFFER_SIZE];
	int			i;
	int			nb;

	while (1)
	{
		i = 0;
		nb = read(fd, buff, BUFFER_SIZE);
		if (nb == -1 || (nb == 0 && (!left || (left && left[0] == '\0'))))
			return (NULL);
		left = ft_strnjoin(left, buff, nb);
		if (!left)
			return (NULL);
		while (left[i])
		{
			if (left[i] == '\n')
				return (line(i, &left));
			i++;
		}
		if (nb == 0 && left)
			return (line(i, &left));
	}
	return (0);
}

// #include <fcntl.h>

// int	main()
// {
// 	int	fd;
// 	int	heecks;

// //	fd = open("text.txt", O_RDONLY);
// 	heecks = 0;
// 	while (heecks < 10)
// 	{
// 		printf("%s\n", get_next_line(0));
// 		heecks++;
// 	}
// 	return (0);
// }
