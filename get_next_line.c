/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 10:14:35 by nseon             #+#    #+#             */
/*   Updated: 2024/12/04 17:39:17 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*get_next_line(int fd);
{
	static char	leftover[BUFFER_SIZE];
	char	*tab;
	int		i;

	i = 0;
	read(fd, leftover, BUFFER_SIZE);
	while (leftover[i] != '\n' && leftover[i])
	{

	}
}
