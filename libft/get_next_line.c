/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dquitari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 14:54:39 by dquitari          #+#    #+#             */
/*   Updated: 2023/06/15 14:54:40 by dquitari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*temp_trimmer(char *temp)
{
	char	*new_temp;
	int		i;
	int		j;

	i = 0;
	while (temp [i] && temp[i] != '\n')
		i++;
	if (!temp[i])
	{
		free(temp);
		return (NULL);
	}
	new_temp = malloc(sizeof(char) * (ft_strlen(temp) - i));
	if (!new_temp)
		return (NULL);
	j = 0;
	while (++i < ft_strlen(temp))
		new_temp[j++] = temp[i];
	new_temp[j] = '\0';
	free(temp);
	return (new_temp);
}

char	*get_new_line(char *temp)
{
	int		i;
	int		len;
	char	*line;

	i = 0;
	len = 0;
	if (!temp[i])
		return (NULL);
	while (temp[len] && temp[len] != '\n')
		len++;
	line = malloc(sizeof(char) * len + 2);
	if (!line)
		return (NULL);
	while (i <= len)
	{
		line[i] = temp[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*get_temp(int fd, char *temp)
{
	char	*buf;
	int		read_val;

	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	read_val = 1;
	while (read_val != 0 && !ft_strchr(temp, '\n'))
	{
		read_val = read(fd, buf, BUFFER_SIZE);
		if (read_val == -1)
		{
			free(buf);
			free(temp);
			return (NULL);
		}
		buf[read_val] = '\0';
		temp = ft_strjoin(temp, buf);
	}
	free(buf);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*temp;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	temp = get_temp(fd, temp);
	if (!temp)
		return (NULL);
	line = get_new_line(temp);
	temp = temp_trimmer(temp);
	return (line);
}
