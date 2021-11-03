/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 17:04:32 by tpereira          #+#    #+#             */
/*   Updated: 2021/03/20 12:54:38 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	int	ft_saveline(char **save, char **line)
{
	int	len;
	char *temp;

	len = 0;
	temp = NULL;
	while ((*save)[len] != '\n' && (*save)[len] != '\0')
		len++;
	if ((*save)[len] == '\n')
	{
		*line = ft_substr(*save, 0, len);
		temp = ft_strdup(&((*save)[len + 1]));
		free(*save);
		*save = temp;
	}
	else
	{
		*line = ft_strdup(*save);
		free(*save);
		*save = NULL;
		return (0);
	}
	return (1);
}

static int	ft_output(char **save, char **line, int r, int fd)
{
	if (r < 0)
		return (-1);
	else if (r == 0 && save[fd] == NULL)
	{
		*line = ft_strdup("");
		return (0);
	}
	else
		return (ft_saveline(&save[fd], line));
}

int get_next_line(int fd, char **line)
{
	int			r;
	static char	*save[OPEN_MAX];
	char 		*temp;
	char 		buff[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE <= 0 || !line || read(fd, buff, 0) < 0)
		return (-1);
	while ((r = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[r] = '\0';
		if (save[fd] == NULL)
			save[fd] = ft_strdup(buff);
		else
		{
			temp = ft_strjoin(save[fd], buff); 
			free(save[fd]);
			save[fd] = temp;
		}
		if (ft_strchr(save[fd], '\n'))
			break ;
	}
	return (ft_output(save, line, r, fd));
}
