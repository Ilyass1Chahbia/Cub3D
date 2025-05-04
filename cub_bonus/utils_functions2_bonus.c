/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_functions2_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kid-ouis <kid-ouis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:24:26 by ilchahbi          #+#    #+#             */
/*   Updated: 2024/12/26 15:38:33 by kid-ouis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

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

void	door_coords(t_stc *stc)
{
	int	n;
	int	m;
	int	d;

	n = 0;
	d = 0;
	if (stc->n_d == 0)
		return ;
	while (stc->map[n])
	{
		m = 0;
		while (stc->map[n][m])
		{
			if (stc->map[n][m] == 'D')
			{
				stc->door.d_x[d] = m * SZ_TILE;
				stc->door.d_y[d] = n * SZ_TILE;
				d++;
			}
			m++;
		}
		n++;
	}
}

void	update_door(t_stc *stc)
{
	t_up	var;

	var.d = 0;
	if (stc->n_d == 0)
		return ;
	while (var.d < stc->n_d)
	{
		var.o = 2.0f * SZ_TILE;
		var.x = stc->door.d_x[var.d] + (SZ_TILE / 2);
		var.y = stc->door.d_y[var.d] + (SZ_TILE / 2);
		var.distance = sqrt(pow(stc->player.x - var.x, 2)
				+ pow(stc->player.y - var.y, 2));
		var.prog = 1.0f - (var.distance / var.o);
		if (var.prog < 0.0f)
			var.prog = 0.0f;
		if (var.prog > 1.0f)
			var.prog = 1.0f;
		if (var.prog > 0.0f)
			stc->map[stc->door.d_y[var.d] / SZ_TILE]
			[stc->door.d_x[var.d] / SZ_TILE] = '0';
		else
			stc->map[stc->door.d_y[var.d] / SZ_TILE]
			[stc->door.d_x[var.d] / SZ_TILE] = 'D';
		var.d++;
	}
}
