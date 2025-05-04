/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kid-ouis <kid-ouis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:53:40 by kid-ouis          #+#    #+#             */
/*   Updated: 2024/12/23 19:06:58 by kid-ouis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_read(char *buff, char *str, int fd)
{
	int		rbytes;
	char	*tmp;

	rbytes = 1;
	while (rbytes > 0)
	{
		rbytes = read(fd, buff, BUFFER_SIZE);
		if (rbytes < 0)
			return (free(buff), free(str), str = NULL, buff = NULL, NULL);
		buff[rbytes] = '\0';
		tmp = str;
		str = ft_strjoin(str, buff);
		if (!str)
			return (free(tmp), free(buff), NULL);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(str, '\n'))
			break ;
	}
	free(buff);
	buff = NULL;
	if (str && str[0] == '\0')
		return (free(str), str = NULL, NULL);
	return (str);
}

static char	*get_line(char *str, char *line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	while (str && str[i] != '\0' && str[i] != '\n')
		i++;
	if (str && str[i] == '\n')
		i++;
	line = malloc((i + 1) * sizeof(char));
	if (!line)
		return (free (str), str = NULL, NULL);
	while (j < i)
	{
		line[j] = str[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

static char	*update_str(char *str)
{
	char	*newstr;
	int		i;

	if (!str)
		return (NULL);
	i = 0;
	while (str && str[i] != '\0' && str[i] != '\n')
		i++;
	if (str && str[i] == '\n')
		i++;
	newstr = ft_strdup(str + i);
	if (!newstr)
		return (free(str), str = NULL, NULL);
	free(str);
	str = NULL;
	return (newstr);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*buff;
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (buff = NULL, NULL);
	buff = malloc((size_t)BUFFER_SIZE + 1);
	if (!buff)
		return (free(str), str = NULL, NULL);
	str = ft_read(buff, str, fd);
	if (!str)
		return (NULL);
	line = get_line(str, line);
	if (!line)
		return (str = NULL, NULL);
	str = update_str(str);
	return (line);
}
