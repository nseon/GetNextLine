/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 10:14:35 by nseon             #+#    #+#             */
/*   Updated: 2024/12/05 17:42:42 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

char	*get_next_line(int fd)
{
	static char	leftover[BUFFER_SIZE + 1];
	char		*tab;
	int			i;

	tab = NULL;
	while (1)
	{
		i = 0;
		tab = ft_strjoin(tab, leftover);
		if (read(fd, leftover, BUFFER_SIZE) == -1)
			return (NULL);
		while (leftover[i])
		{
			if (leftover[i] == '\n')
			{
				tab = ft_strjoin(tab, leftover);
				*leftover += i;
				return (tab);
			}
			i++;
		}
	}
	return (0);
}
int	main()
{
	int	fd;

	fd = open("text");
	printf("%s\n", get_next_line(fd));
	return (0);
}
