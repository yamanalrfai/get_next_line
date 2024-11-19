/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalrfai <yalrfai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 00:59:00 by yhamdan           #+#    #+#             */
/*   Updated: 2024/11/19 08:59:13 by yalrfai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_rem(char *buf, char *l)
{
	int		i;
	int		j;
	char	*rem;

	i = ft_strlen(l);
	j = 0;
	if (!buf[i])
	{
		free(buf);
		return (NULL);
	}
	while (buf[i++])
		j++;
	rem = ft_calloc((j + 1), 1);
	i = ft_strlen(l);
	j = 0;
	while (buf[i + j])
	{
		rem[j] = buf[i + j];
		j++;
	}
	rem[j] = '\0';
	free(buf);
	return (rem);
}

char	*ft_line(char *buf)
{
	char	*line;
	int		i;

	i = 0;
	if (!buf)
		return (NULL);
	while (buf[i] && buf[i] != '\n')
		i++;
	line = ft_calloc(i + 2, 1);
	if (!line)
		return (NULL);
	i = 0;
	while (buf[i] && buf[i] != '\n')
	{
		line[i] = buf[i];
		i++;
	}
	if (buf[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_read_line(int fd, char *buf)
{
	char	*read_file;
	int		num_of_char;

	num_of_char = 1;
	while (num_of_char > 0 && !ft_strchr(buf))
	{
		read_file = ft_calloc(BUFFER_SIZE + 1, 1);
		if (!read_file)
			return (NULL);
		num_of_char = read(fd, read_file, BUFFER_SIZE);
		if (num_of_char == -1 || (!buf && num_of_char == 0))
		{
			free(read_file);
			return (NULL);
		}
		read_file[num_of_char] = '\0';
		buf = ft_strjoin(buf, read_file);
		if (!buf)
			return (free(read_file),NULL);
	}
	return (buf);
}

char	*get_next_line(int fd)
{
	static char	*buf = NULL;
	char		*line;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	tmp = ft_read_line(fd, buf);
	if (!tmp)
	{
		if (buf)
			free(buf);
		buf = NULL;
		return (NULL);
	}
	buf = tmp;
	line = ft_line(buf);
	buf = ft_rem(buf, line);
	return (line);
}
