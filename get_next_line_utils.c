/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhamdan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 01:00:02 by yhamdan           #+#    #+#             */
/*   Updated: 2024/09/15 01:07:24 by yhamdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*st;

	j = 0;
	i = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		s1 = ft_calloc(1, 1);
	st = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (st == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		st[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		st[i + j] = s2[j];
		j++;
	}
	st[i + j] = '\0';
	return (free(s1), free(s2), st);
}

char	*ft_strchr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == '\n')
			return (&str[i]);
		i++;
	}
	return (NULL);
}

void	ft_bzero(void *s, size_t n)
{
	size_t		i;
	char		*str;

	str = s;
	i = 0;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}

void	*ft_calloc(size_t n, size_t size)
{
	char	*p;

	p = malloc(n * size);
	if (p == NULL)
		return (NULL);
	ft_bzero(p, n * size);
	return (p);
}
