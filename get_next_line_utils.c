/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 10:22:29 by nseon             #+#    #+#             */
/*   Updated: 2024/12/06 14:24:50 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(const char *s)
{
	int	n;

	n = 0;
	if (!s)
		return (0);
	while (s[n] != '\0')
		n++;
	return (n);
}

char	*ft_strnjoin(char *s1, char *s2, int n)
{
	char	*tab;
	int		i;
	int		j;

	i = 0;
	tab = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof (char));
	if (tab == NULL)
		return (0);
	while (s1 && s1[i])
	{
		tab[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j] && j < n)
	{
		tab[i] = s2[j];
		i++;
		j++;
	}
	tab[i] = '\0';
	free(s1);
	return (tab);
}

char	*ft_substr(char const *s, unsigned int start)
{
	int		i;
	char	*tab;

	i = 0;
	tab = malloc((ft_strlen(s) - start + 1) * sizeof (char));
	if (tab == NULL)
		return (0);
	while (s[i + start])
	{
		tab[i] = s[i + start];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}
