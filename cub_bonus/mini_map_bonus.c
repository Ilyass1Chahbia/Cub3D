/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kid-ouis <kid-ouis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:42:15 by kid-ouis          #+#    #+#             */
/*   Updated: 2024/12/23 19:09:25 by kid-ouis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	draw_outline(t_stc *stc, int x, int y, int color)
{
	int	i;

	i = 0;
	while (i < 12)
	{
		mlx_put_pixel(stc->img_pt, x + i, y, color);
		mlx_put_pixel(stc->img_pt, x + i, y + 12 - 1, color);
		mlx_put_pixel(stc->img_pt, x, y + i, color);
		mlx_put_pixel(stc->img_pt, x + 12 - 1, y + i, color);
		i++;
	}
}

void	draw_player(t_stc *stc)
{
	int	x;
	int	y;

	y = (200 / 2) - 2;
	x = (200 / 2) - 2;
	draw_outline_2(stc, x, y, ft_rgb(255, 0, 0, 255));
}

int	map_check(int x, int y, float off_x, float off_y)
{
	if ((x * 12) + off_x <= 200 && (x * 12) + off_x >= 0
		&& (y * 12) + off_y <= 200 && (y * 12) + off_y >= 0)
		return (1);
	else
		return (0);
}

void	map_while(t_stc *stc, float off_y, float off_x)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (stc->map[y])
	{
		x = 0;
		while (stc->map[y][x])
		{
			if (stc->map[y][x] == '1')
				if (map_check(x, y, off_x, off_y))
					draw_outline(stc, (x * 12) + off_x,
						(y * 12) + off_y, ft_rgb(255, 255, 255, 255));
			if (stc->map[y][x] == 'D')
				if (map_check(x, y, off_x, off_y))
					draw_outline(stc, (x * 12) + off_x,
						(y * 12) + off_y, ft_rgb(0, 0, 255, 255));
			x++;
		}
		y++;
	}
}

void	draw_map(t_stc *stc)
{
	int		x;
	int		y;
	float	off_y;
	float	off_x;

	y = 0;
	x = 0;
	while (y < 215)
	{
		x = 0;
		while (x < 215)
		{
			mlx_put_pixel(stc->img_pt, x, y, ft_rgb(0, 0, 0, 160));
			x++;
		}
		y++;
	}
	off_x = (200 / 2) - ((stc->player.x / SZ_TILE) * 12);
	off_y = (200 / 2) - ((stc->player.y / SZ_TILE) * 12);
	map_while(stc, off_y, off_x);
	draw_player(stc);
}
