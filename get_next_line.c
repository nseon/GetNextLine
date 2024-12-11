/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 10:14:35 by nseon             #+#    #+#             */
/*   Updated: 2024/12/11 17:39:47 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char	*line(int i, char **left)
{
	char	*str;
	int		j;

	j = 0;
	str = malloc((ft_strlen(*left) + 2) * sizeof (char));
	if (!str)
	{
		null_free(&str);
		return (null_free(left));
	}
	while (j <= i)
	{
		str[j] = (*left)[j];
		j++;
	}
	str[j] = '\0';
	*left = ft_substr(left, i + 1);
	if (!*left || !str)
	{
		null_free(&str);
		return (null_free(left));
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
			return (null_free(&left));
		left = ft_strnjoin(&left, buff, nb);
		if (!left)
			return (0);
		while (left[i])
		{
			if (left[i] == '\n')
				return (line(i, &left));
			i++;
		}
	}
	return (line(i, &left));
}

// #include <fcntl.h>

// int	main()
// {
// 	int	fd;
// 	int	heecks;
// 	char	*tab;

// 	fd = open("t.txt", O_RDONLY);
// 	heecks = 0;
// 	tab = get_next_line(fd);
// 	while (tab)
// 	{
// 		printf("%s", tab);
// 		fflush(stdout);
// 		free(tab);
// 		tab = get_next_line(fd);
// 	}
// 	free(tab);
// 	return (0);
// }
