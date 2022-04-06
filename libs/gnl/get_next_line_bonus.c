/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 20:00:04 by bducrocq          #+#    #+#             */
/*   Updated: 2021/12/31 16:08:20 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strichr_nl(char *str)
{
	size_t	i;
	size_t	j;

	if (BUFFER_SIZE == 1 && str[0] == '\n')
		return (-3);
	i = 0;
	while (i < BUFFER_SIZE)
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	j = 0;
	while (j < BUFFER_SIZE)
	{
		if (str[j] != '\0')
			return (-1);
		j++;
	}
	return (-2);
}

int	ft_buf_process(char *bufp)
{
	int	i;

	i = 0;
	while (*bufp != '\n')
	{
		if (i == BUFFER_SIZE)
			break ;
		*bufp = '\0';
		bufp++;
		i++;
	}
	*bufp = '\0';
	return (0);
}

int	ft_norm_read(int fd, char **buf, int *ret2, char **line)
{
	int	chr_nl;

	chr_nl = ft_strichr_nl(*buf);
	while ((chr_nl < 0 && chr_nl != -3 && *ret2 > 0) || chr_nl == -1)
	{
		if (chr_nl == -1)
			chr_nl = BUFFER_SIZE;
		ft_strjoin_gnl(&*line, *line, *buf, chr_nl);
		*ret2 = read(fd, *buf, BUFFER_SIZE);
		chr_nl = ft_strichr_nl(*buf);
	}
	return (chr_nl);
}

static int	ft_read(int fd, int ret2, char *buf, char **line)
{
	int	chr_nl;
	int	start_buf;

	chr_nl = ft_strichr_nl(buf);
	if (chr_nl == -2)
		ret2 = read(fd, buf, BUFFER_SIZE);
	start_buf = 0;
	while (*buf == '\0' && start_buf < BUFFER_SIZE)
		start_buf++;
	ft_norm_read(fd, &buf, &ret2, &*line);
	chr_nl = ft_strichr_nl(buf);
	if (ret2 == 0 && start_buf != BUFFER_SIZE)
		return (0);
	if (chr_nl == -3)
		chr_nl = 1;
	if (chr_nl == -2)
	{
		chr_nl = ft_strlen(*line);
		if (chr_nl != 0)
			return (0);
	}
	if (ret2 == 0 && chr_nl == 0)
		return (0);
	ft_strjoin_gnl(&*line, *line, buf, chr_nl);
	return (ret2);
}

char	*get_next_line(int fd)
{	
	static char		buf[OPEN_MAX][BUFFER_SIZE + 1];
	char			*line;
	int				ret;

	if (read(fd, buf[fd], 0) < 0 || fd > OPEN_MAX || BUFFER_SIZE == 0)
		return (NULL);
	line = ft_strdup("");
	ret = 0;
	ret = ft_read(fd, ret, buf[fd], &line);
	ret = ft_strlen(line);
	if (ret == 0)
	{
		if (line)
			free(line);
		return (NULL);
	}
	return (line);
}
