/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_functions2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kid-ouis <kid-ouis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:24:26 by ilchahbi          #+#    #+#             */
/*   Updated: 2024/12/26 15:33:31 by kid-ouis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	path_len(char *line, int *start, int i, int len)
{
	if (line[i] == ' ')
		return (write(2, "Error\nspc at the beginning\n", 28), -1);
	while (line[i])
	{
		if (line[i] == ' ')
		{
			while (line[i])
			{
				if (line[i] != ' ')
				{
					*start = i;
					while (line[i])
					{
						len++;
						i++;
					}
					return (len);
				}
				i++;
			}
		}
		if (line[i] != '\0')
			i++;
	}
	return (0);
}

char	*get_path(char *line, int start, int len, int i)
{
	char	*path;

	path = NULL;
	len = path_len(line, &start, 0, 0);
	if (len < 0)
		return (NULL);
	if (len == 0)
		return (NULL);
	path = malloc(len + 1);
	if (!path)
		return (NULL);
	while (line[start])
	{
		path[i++] = line[start++];
	}
	path[i] = '\0';
	return (path);
}

int	num_cols(char **str)
{
	int		num;
	int		n;

	n = 0;
	num = 0;
	while (str[n])
	{
		if (ft_strlen(str[n]) > num)
			num = ft_strlen(str[n]);
		n++;
	}
	return (num);
}
