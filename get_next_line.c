/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 10:14:35 by nseon             #+#    #+#             */
/*   Updated: 2024/12/06 14:26:20 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	*leftover;
	char		tab[BUFFER_SIZE + 1];
	char		*res;
	int			i;

	while (1)
	{
		i = 0;
		if (read(fd, tab, BUFFER_SIZE) == -1)
			return (NULL);
		leftover = ft_strnjoin(leftover, tab, BUFFER_SIZE);
		while (leftover[i])
		{
			if (leftover[i] == '\n')
			{
				res = ft_strnjoin(NULL, leftover, i);
				leftover = ft_substr(leftover, ++i);
				return (res);
			}
			i++;
		}
	}
	return (0);
}

// #include <fcntl.h>

// int	main()
// {
// 	int	fd;
// 	int	heecks;

// 	fd = open("text.txt", O_RDONLY);
// 	heecks = 0;
// 	while (heecks < 10)
// 	{
// 		printf("%s\n", get_next_line(fd));
// 		heecks++;
// 	}
// 	return (0);
// }
